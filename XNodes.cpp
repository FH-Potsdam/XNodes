/**
 * Copyright 2017 Fabian Morón Zirfas
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to  permit persons to
 * whom the Software is furnished to do so, subject to
 * the following conditions:
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTIO
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * see also http://www.opensource.org/licenses/mit-license.php
 */
#include "Arduino.h"
#include "XNode.h"

XNode::XNode(int inpin, int outpin, int inviruspin, int outviruspin) {
 pinMode(inpin, INPUT_PULLUP);
 pinMode(inviruspin, INPUT_PULLUP);
 pinMode(outpin, OUTPUT);
 pinMode(outviruspin, OUTPUT);
 _inviruspin = inviruspin;
 _outviruspin = outviruspin;
 _inpin = inpin;
 _outpin = outpin;
  digitalWrite(_outviruspin, HIGH);
}


XNode::~XNode() {}

boolean XNode::virusDetect() {
  int in = digitalRead(_inviruspin);

    if (in == LOW) {
      _isinfected = true;
      return true;
    } else {
      _isinfected = false;
      return false;
    }
}

boolean XNode::isInfected(){
  return _isinfected;
boolean XNode::listen() {
    int in = digitalRead(_inpin);
    }
    if (in == LOW) {
      return true;
    } else {
      return false;
    }
}

void XNode::toggleInfection(){
  _isInfected = !_isinfected;
}
/**
 * This might be needed
 */
void XNode::init(){
  digitalWrite(_outviruspin, HIGH);
}
void XNode::listenForVirus(){
    int inv = digitalRead(_inviruspin);

    if(inv == LOW) {
      _isinfected = true;
    } else {
      // do we need this?
      // this uninfects a node
      // if we use the reset pin to uninfect
      // the node we can remove this part of the code
      _isinfected = false;
}
}
void XNode::setInterval(long interval) {
  _interval = interval;
}
void XNode::send() {
    digitalWrite(_outpin, HIGH);
    delay(_interval);
    digitalWrite(_outpin, LOW);
}

void XNode::sendVirus(){
  if(_isinfected == true) {
    digitalWrite(_outviruspin, LOW);
  } else {
    digitalWrite(_outviruspin, HIGH);

  }
}
