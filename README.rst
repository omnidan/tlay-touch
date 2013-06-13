================
TLay Touch 1.0.0
================

Copyright (c) 2013 Daniel Bugl, TouchLay. All rights reserved. See the LICENSE file for more information.

TLay Touch is a UDP protocol that allows you to add multitouch support to programs.
The protocol itself is pretty much just a specification, this repository contains the main implementation of TLay Touch, which is C++ and mainly used in our software.

.. contents::

Specification
-------------

This is done in a JSON example and explained with C-like comments because the protocol is using JSON and an example is always easier to understand.
::
  
  {
    "s": "example", // source - this can be anything, but there is a structure below
    "id": 80,       // id of the event (session id)
    "xp": 0.501,    // x position
    "yp": 0.123,    // y position
    "xv": 0.192,    // x velocity
    "yv": 0.831,    // y velocity
    "a": 0.921,     // angle
    "ma": 0         // motion acceleration
  }

The "s" variable (source) can be set to any string, however there is a standardised structure you should use.
::
  
  "s": "client@ip%interfaceX/sourcetype/inputtype"

And an example:
::
  
  "s": "TUIOdroid@fe80::646:dead:beef:cafe%wlan0/tuio/2Dcur"

License
-------

The TLay Touch protocol specification and the implementation are both licensed under the BSD license. For further information please consult the LICENSE file.
