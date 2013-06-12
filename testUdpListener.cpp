/*
 * =====================================================================================
 *
 *       Filename:  testUdpListener.cpp
 *
 *    Description:  Testing the UdpListener object.
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


// json headers
#include "json/json.h"

#include "UdpListener.h"


Json::Reader jReader;
Json::Value jRoot;

int loop(std::string buf) {
	std::cout << "RECV: " << buf << std::endl;
    if (!jReader.parse(buf, jRoot, false)) {
      std::cout << "DECODED: Invalid JSON (" << buf << ")." << std::endl;
    } else {
      std::cout << "DECODED: " << jRoot << "(" << buf << ")." << std::endl;
    }
    return 0; // if this is not 0, loop returns the error code
}

int main() {
    UdpListener *test = new UdpListener(); // create socket
    return test->loop(loop); // quit with error code from the loop
}
