/*
 * =====================================================================================
 *
 *       Filename:  UdpClient.cpp
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

#include "UdpClient.h"

UdpClient::UdpClient(void) {
  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    std::cerr << __FILE__ << ":" << __LINE__ << ": Couldn't create socket." << std::endl;
  std::cout << __FILE__ << ":" << __LINE__ << ": Socket initialized. (s=" << s << ")" << std::endl;
}

UdpClient::~UdpClient(void) {
  if (close(s) != 0)
    std::cerr << __FILE__ << ":" << __LINE__ << ": Couldn't close socket." << std::endl;
  std::cout << __FILE__ << ":" << __LINE__ << ": Socket unloaded. (s=" << s << ")" << std::endl;
}

int UdpClient::send(char *server, int port, char *msg) {
  struct sockaddr_in s_remote;

  // set up socket
  bzero(&s_remote, sizeof(s_remote));
  s_remote.sin_family = AF_INET;
  s_remote.sin_port = htons(port);

  // resolve hostname and set IP
  struct hostent *h_remote = gethostbyname(server);
  char *ip = inet_ntoa((*(struct in_addr **)h_remote->h_addr_list)[0]);
  s_remote.sin_addr.s_addr = inet_addr(ip);

  // send message
  if (sendto(s, msg, strlen(msg), 0, (struct sockaddr*)&s_remote, sizeof(s_remote)) == -1) {
    std::cerr << __FILE__ << ":" << __LINE__ << ": sendto() failed." << std::endl;
    return -1;
  }

  return 0; // sweet success.
}