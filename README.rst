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
    "a": 1,         // action - this is an integer, see below for more information
    "id": 80,       // id of the event (session id)
    "xp": 0.501,    // x position
    "yp": 0.123,    // y position
    "xv": 0.192,    // x velocity
    "yv": 0.831,    // y velocity
    "an": 0.921,    // angle
    "ms": 0.213,    // motion speed
    "ma": 0.864     // motion acceleration
  }

The "s" variable (source) can be set to any string, however there is a standardised structure you should use.
::
  
  "s": "client@ip%interfaceX/sourcetype/inputtype"

And an example:
::
  
  "s": "TUIOdroid@fe80::646:dead:beef:cafe%wlan0/tuio/2Dcur"

The "a" variable (action) can be set to the following integers:

* 0 - undefined action
* 1 - add cursor/object
* 2 - update cursor/object
* 3 - remove cursor/object

License
-------

The TLay Touch protocol specification and the implementation are both licensed under the BSD license. For further information please consult the LICENSE file.
