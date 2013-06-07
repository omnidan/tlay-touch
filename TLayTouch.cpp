/*
 * =====================================================================================
 *
 *       Filename:  TLayTouch.cpp
 *
 *    Description:  The official C++ implementation of the TLay Touch protocol.
 *
 *        Version:  1.0.0
 *        Created:  06/07/2013 08:36:41 PM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

// this is a sample udp server for now, later, there should be a class here

#define BUFFER_SIZE 10
#define PORT 1337

// standard headers
#include <iostream>
#include <string.h>

// networking headers
#include <sys/socket.h>
#include <netinet/in.h>

int main (int argc, char* argv[]) {
  int s, n;
  struct sockaddr_in s_self, s_remote;
  char buf[BUFFER_SIZE];

  s = socket(AF_INET, SOCK_DGRAM, 0);

  bzero(&s_self, sizeof(s_self));
  s_self.sin_family = AF_INET;
  s_self.sin_addr.s_addr = htonl(INADDR_ANY);
  s_self.sin_port = htons(PORT);

  bind(s, (struct sockaddr *)&s_self, sizeof(s_self));

  for (;;) {
    n = recvfrom(s, buf, BUFFER_SIZE, 0, (struct sockaddr *)&s_remote, (socklen_t *)sizeof(s_remote));
    sendto(s, buf, n, 0, (struct sockaddr *)&s_remote, sizeof(s_remote));
    buf[n] = 0;
    std::cout << "RECV: " << buf << std::endl;
  }
}