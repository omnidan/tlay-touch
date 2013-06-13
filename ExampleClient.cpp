/*
 * =====================================================================================
 *
 *       Filename:  ExampleClient.cpp
 *
 *    Description:  Example TLayTouch client
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

// headers
#include "TLayTouch.h"
#include "udp/UdpClient.h"

int main() {
    UdpClient *test = new UdpClient(); // create socket
    TLayTouch *tt = new TLayTouch("example", 0, 1, 0.5, 0.5, 0, 0, 0, 0, 0);
    if (test->send("localhost", 4444, (char *)tt->jexport().c_str()) == 0) { // send message
    	std::cout << "success!" << std::endl;
    	delete tt; // delete touch event
        delete test; // close socket
    	return 0;
    } else return -1;
}
