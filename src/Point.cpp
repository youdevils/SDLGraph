#include "../include/Point.hpp"

Point::Point()
{
}
Point::~Point()
{
}
Point::Point(const char *id, float x, float y)
{
    m_X_Coordinate = x;
    m_Y_Coordinate = y;
    identifier = id;
}

const char *Point::GetID()
{
    return identifier;
}

float Point::GetX()
{
    return m_X_Coordinate;
}

float Point::GetY()
{
    return m_Y_Coordinate;
}

float Point::GetXInverted()
{
    return m_X_Coordinate * -1;
}

float Point::GetYInverted()
{
    return m_Y_Coordinate * -1;
}

void Point::PrintPoint()
{
    std::cout << "(" << m_X_Coordinate << ", " << m_Y_Coordinate << ")";
}