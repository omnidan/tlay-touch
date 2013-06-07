/*
 * =====================================================================================
 *
 *       Filename:  testUdpSocket.cpp
 *
 *    Description:  Testing the UdpSocket object.
 *
 *        Version:  1.0.0
 *        Created:  06/07/2013 10:11:54 PM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#include "UdpSocket.h"

int main() {
    UdpSocket *test = new UdpSocket(); // create socket
    test->send("localhost", 1111, "daytime"); // send message
    delete test; // close socket
}
