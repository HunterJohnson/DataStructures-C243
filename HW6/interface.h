/*****************************************************************************
  Authors:       Dana Vrajitoru, IUSB, CS
                 William Knight, IUSB, CS
  Class:         C243 Data Structures
  File name:     interface.h
  Last updated:  October 10, 2015.
  Description:   Prototypes of interface functions.
******************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "tree.h"

void  printMenuAndGetAction (char & response);

void performAction(NodePtr &treep, char response);

void  printExplanatoryMessage();

void  readAndEchoCharResponse (char & response);

void  readAndEchoIntResponse (int & response);

void  testDynamicAllocation (void * pointerValue);

#endif
