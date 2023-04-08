#pragma once

#include <iostream>
#include <cmath>

class Point
{
private:
    float m_X_Coordinate;
    float m_Y_Coordinate;
    const char *identifier;

public:
    Point();
    ~Point();
    Point(const char *id, float x, float y);
    const char *GetID();
    float GetX();
    float GetY();
    float GetXInverted();
    float GetYInverted();
    void PrintPoint();
};
