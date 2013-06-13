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

#include "TLayTouch.h"

TLayTouch::TLayTouch(std::string source, int session_id, float x_position, float y_position, float x_velocity, float y_velocity, float angle, float motion_acceleration) {
  s  = source;
  id = session_id;
  xp = x_position;
  yp = y_position;
  xv = x_velocity;
  yv = y_velocity;
  a  = angle;
  ma = motion_acceleration;
  #ifdef DEBUG
  std::cout << __FILE__ << ":" << __LINE__ << ": TLayTouch event created. (s='" << s
                                                                     << "',id=" << id
                                                                     << ",xp="  << xp
                                                                     << ",yp="  << yp
                                                                     << ",xv="  << xv
                                                                     << ",yv="  << yv
                                                                     << ",a="   << a
                                                                     << ",ma="  << ma
                                                                     << ")"     << std::endl;
  #endif
}

TLayTouch::TLayTouch(std::string json_string) {
  jimport(json_string);
}

bool TLayTouch::jimport(std::string json_string) {
  Json::Reader jReader;
  Json::Value jRoot;

  if (!jReader.parse(json_string, jRoot, false)) {
    #ifdef DEBUG
    std::cout << __FILE__ << ":" << __LINE__ << ": TLayTouch event creation failed. (Invalid JSON: '" << json_string << "')";
    #endif
    return false;
  } else {
    s = jRoot.get("s", "unknown").asString();
    id = jRoot.get("id", 1).asInt();
    xp = jRoot.get("xp", 0.00).asFloat();
    yp = jRoot.get("yp", 0.00).asFloat();
    xv = jRoot.get("xv", 0.00).asFloat();
    yv = jRoot.get("yv", 0.00).asFloat();
    a = jRoot.get("a", 0.00).asFloat();
    ma = jRoot.get("ma", 0.00).asFloat();
    #ifdef DEBUG
    std::cout << __FILE__ << ":" << __LINE__ << ": TLayTouch event created from JSON. (json_string='" << json_string
                                                                                 << "',s='"  << s
                                                                                 << "',id="  << id
                                                                                 << ",xp="   << xp
                                                                                 << ",yp="   << yp
                                                                                 << ",xv="   << xv
                                                                                 << ",yv="   << yv
                                                                                 << ",a="    << a
                                                                                 << ",ma="   << ma
                                                                                 << ")"      << std::endl;
    #endif
    return true;
  }
}

std::string TLayTouch::jexport(void) {
  std::stringstream ss;
  ss << "{\"s\": \""   << s  <<
        "\", \"id\": " << id <<
        ", \"xp\": "   << xp <<
        ", \"yp\": "   << yp <<
        ", \"xv\": "   << xv <<
        ", \"yv\": "   << yv <<
        ", \"a\": "    << a  <<
        ", \"ma\": "   << ma <<
        "}";
  return ss.str();
}