/*
 * =====================================================================================
 *
 *       Filename:  UdpListener.cpp
 *
 *    Description:  Small UDP socket manager - receiving end.
 *
 *        Version:  1.0.0
 *        Created:  06/08/2013 03:59:54 AM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#include "UdpListener.h"

UdpListener::UdpListener(void) {
  s = socket(AF_INET, SOCK_DGRAM, 0);

  bzero(&s_self, sizeof(s_self));
  s_self.sin_family = AF_INET;
  s_self.sin_addr.s_addr = htonl(INADDR_ANY);
  s_self.sin_port = htons(PORT);

  bind(s, (struct sockaddr *)&s_self, sizeof(s_self));
}

int UdpListener::loop(int (*f)(std::string)) {
  char buf[BUFFER_SIZE];
  for (;;) {
    n = recvfrom(s, buf, BUFFER_SIZE, 0, (struct sockaddr *)&s_remote, (socklen_t *)sizeof(s_remote));
    sendto(s, buf, n, 0, (struct sockaddr *)&s_remote, sizeof(s_remote));
    buf[n] = 0;
    int result = (*f)((std::string)buf);
    if (result != 0) return result;
  }
}