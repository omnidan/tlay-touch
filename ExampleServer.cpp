/*
 * =====================================================================================
 *
 *       Filename:  ExampleServer.cpp
 *
 *    Description:  Example TLayTouch server
 *
 *        Version:  1.0.0
 *        Created:  06/08/2013 04:03:21 AM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

// headers
#include "TLayTouch.h"
#include "udp/UdpListener.h"

int loop(std::string buf) {
	std::cout << "RECV: " << buf << std::endl;
	TLayTouch *tt = new TLayTouch(buf);
	std::cout << "EXPO: " << tt->jexport() << std::endl;
	if (tt->jexport() == buf) std::cout << "RECV AND EXPO MATCH! (SUCCESS!)" << std::endl;
	delete tt;
    return 0; // if this is not 0, loop returns the error code
}

int main() {
    UdpListener *test = new UdpListener(4444); // create socket
    return test->loop(loop); // quit with error code from the loop
}
