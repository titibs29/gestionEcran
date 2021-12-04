#pragma once

void sendCommand(int hmi, const char* cmd);

void Init();

void setTemp(double input);

void setPwr(double pwr);

void setLatitude(int input);

void setLongitude(int input);

void setPosition(double lat,double lon);

void setSignal(int input);