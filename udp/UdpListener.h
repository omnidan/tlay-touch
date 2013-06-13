/*
 * =====================================================================================
 *
 *       Filename:  UdpListener.h
 *
 *    Description:  Headers for the small UDP socket manager - receiving end.
 *
 *        Version:  1.0.0
 *        Created:  06/08/2013 03:57:31 AM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#ifndef _UDPLISTENER_H_
#define _UDPLISTENER_H_

// configuration
#define BUFFER_SIZE 256 // TODO: Check if this value is okay

// standard headers
#include <iostream>
#include <string.h>

// networking headers
#include <sys/socket.h>
#include <netinet/in.h>

class UdpListener {
private:
    int s; // this is used to store the socket
    int n;
    struct sockaddr_in s_self, s_remote;

public:
    UdpListener(int);
    ~UdpListener(void);
    int loop(int (*f)(std::string));
};

#endif