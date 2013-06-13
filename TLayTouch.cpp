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

TLayTouch::TLayTouch(std::string source, unsigned int action, unsigned int session_id, float x_position, float y_position, float x_velocity, float y_velocity, float angle, float motion_speed, float motion_acceleration) {
  s  = source;
  a  = action;
  id = session_id;
  xp = x_position;
  yp = y_position;
  xv = x_velocity;
  yv = y_velocity;
  an = angle;
  ms = motion_speed;
  ma = motion_acceleration;
  #ifdef DEBUG
  std::cout << __FILE__ << ":" << __LINE__ << ": TLayTouch event created. (s='" << s
                                                                     << "',a="  << a
                                                                     << ",id="  << id
                                                                     << ",xp="  << xp
                                                                     << ",yp="  << yp
                                                                     << ",xv="  << xv
                                                                     << ",yv="  << yv
                                                                     << ",an="  << an
                                                                     << ",ms="  << ms
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
    a = jRoot.get("a", 0).asInt();
    id = jRoot.get("id", 1).asInt();
    xp = jRoot.get("xp", 0.00).asFloat();
    yp = jRoot.get("yp", 0.00).asFloat();
    xv = jRoot.get("xv", 0.00).asFloat();
    yv = jRoot.get("yv", 0.00).asFloat();
    an = jRoot.get("an", 0.00).asFloat();
    ms = jRoot.get("ms", 0.00).asFloat();
    ma = jRoot.get("ma", 0.00).asFloat();
    #ifdef DEBUG
    std::cout << __FILE__ << ":" << __LINE__ << ": TLayTouch event created from JSON. (json_string='" << json_string
                                                                                 << "',s='" << s
                                                                                 << "',a="  << a
                                                                                 << ",id="  << id
                                                                                 << ",xp="  << xp
                                                                                 << ",yp="  << yp
                                                                                 << ",xv="  << xv
                                                                                 << ",yv="  << yv
                                                                                 << ",an="  << an
                                                                                 << ",ms="  << ms
                                                                                 << ",ma="  << ma
                                                                                 << ")"     << std::endl;
    #endif
    return true;
  }
}

std::string TLayTouch::jexport(void) {
  std::stringstream ss;
  ss << "{\"s\": \""   << s  <<
        "\", \"a\": "  << a  <<
        ", \"id\": "   << id <<
        ", \"xp\": "   << xp <<
        ", \"yp\": "   << yp <<
        ", \"xv\": "   << xv <<
        ", \"yv\": "   << yv <<
        ", \"an\": "   << an <<
        ", \"ms\": "   << ms <<
        ", \"ma\": "   << ma <<
        "}";
  return ss.str();
}