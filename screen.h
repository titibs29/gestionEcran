#include <wiringSerial.h>
#include <iostream>

#pragma once

void sendCommand( const char* cmd);

void Init();

void setTemp(double input);

void setPwr(double pwr);

void setLatitude(int input);

void setLongitude(int input);

void setPosition(double lat,double lon);

void setSignal(int input);