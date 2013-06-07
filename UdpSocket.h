/*
 * =====================================================================================
 *
 *       Filename:  UdpSocket.h
 *
 *    Description:  Headers for the small UDP socket manager.
 *
 *        Version:  1.0.0
 *        Created:  06/07/2013 10:00:50 PM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#ifndef _UDPSOCKET_H_
#define _UDPSOCKET_H_

// standard headers
#include <iostream>
#include <string.h>
#include <unistd.h>

// networking headers
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>


class UdpSocket {
private:
	int s; // this is used to store the socket

public:
    UdpSocket(void);
    ~UdpSocket(void);
    int send(char *, int, char *); // send a message to a udp server
};

#endif