#include <wiringSerial.h>
#include <iostream>

#pragma once

void sendCommand(int hmi, const char* cmd);

int Init(int hmi);

void setTemp(float input);

void setPwr(int input);

void setLatitude(int input);

void setLongitude(int input);

void setSignal(int input);