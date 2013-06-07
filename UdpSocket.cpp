/*
 * =====================================================================================
 *
 *       Filename:  UdpSocket.cpp
 *
 *    Description:  Small UDP socket manager.
 *
 *        Version:  1.0.0
 *        Created:  06/07/2013 10:02:23 PM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#include "UdpSocket.h"

UdpSocket::UdpSocket(void) {
  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    std::cerr << __FILE__ << ": Couldn't create socket." << std::endl;
  std::cout << __FILE__ << ": Socket initialized. (s=" << s << ")" << std::endl;
}

UdpSocket::~UdpSocket(void) {
  if (close(s) != 0)
    std::cerr << __FILE__ << ": Couldn't close socket." << std::endl;
  std::cout << __FILE__ << ": Socket unloaded. (s=" << s << ")" << std::endl;
}

int UdpSocket::send(char *server, int port, char *msg) {
  struct sockaddr_in s_self, s_remote;

  memset((char *)&s_remote, 0, sizeof(s_remote));
  s_remote.sin_family = AF_INET;
  s_remote.sin_port = htons(port);

  struct hostent *h_remote = gethostbyname((char *)server);
  char *ip = inet_ntoa(*(struct in_addr*)h_remote->h_addr_list);

  if (inet_aton((char *)ip, &s_remote.sin_addr) == 0) {
    std::cerr << __FILE__ << ": inet_aton() failed." << std::endl;
    return -1;
  }

  if (sendto(s, msg, strlen((char *)msg), 0, (sockaddr*)&s_remote, sizeof(s_remote)) == -1) {
    std::cerr << __FILE__ << ": sendto() failed." << std::endl;
    return -1;
  }

  return 0; // sweet success.
}