/*
 * =====================================================================================
 *
 *       Filename:  TLayTouch.h
 *
 *    Description:  Headers for TLayTouch.cpp
 *
 *        Version:  1.0.0
 *        Created:  06/07/2013 08:38:16 PM
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay (http://touchlay.com/)
 *
 * =====================================================================================
 */

#ifndef _TLAYTOUCH_H_
#define _TLAYTOUCH_H_

// standard headers
#include <iostream>
#include <string>
#include <sstream>

// json headers
#include "json/json.h"


class TLayTouch {	
public:
    std::string s; // source
    unsigned int a; // action
    unsigned int id; // session id
    float xp, yp, xv, yv; // positions and velocity
    float an, ms, ma; // angle and motion acceleration

    TLayTouch(std::string, unsigned int, unsigned int, float, float, float, float, float, float, float); // create new object
    TLayTouch(std::string); // overloaded function, import message from JSON
    bool jimport(std::string); // import message from JSON
    std::string jexport(void); // export message as JSON
};

#endif