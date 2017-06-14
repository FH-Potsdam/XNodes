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
 *
 * XNode  Library
 * @author Fabian Morón Zirfas
 * @description A library for the "X" project.
 * Using headphone jacks (or ethernet cables)
 * to communicate between Arduino boards
 */

#ifndef XNode_h
#define XNode_h

#include "Arduino.h"

class XNode {
public:
  XNode(int inpin, outpin, int inviruspin, int outviruspin);

  ~XNode();
  boolean listen();
  boolean listenForVirus();
  boolean virusDetect();
  boolean isInfected();
  void init();
  void send();
  void sendVirus();
  void toggleInfection();
  void setInterval(long interval);
private:
  int _inpin;
  int _outpin;
  int _inviruspin;
  int _outviruspin;
  boolean _isinfected = false;
  long _interval = 50;
};

#endif