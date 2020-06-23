#include "stdafx.h"
#include "Shape.h"

CShape::CShape(void)
{
}

CShape::~CShape(void)
{
}

CShape::CShape(CPoint pox,int chose)
{
    if (chose == 1)
    {
		CPoint pt1[4] = {CPoint(-10, 0), CPoint(0, 10), CPoint(10, 0), CPoint(0, -10)};
        for (int i = 0; i < 4; i++)
        {
            point[i].x = pt1[i].x + pox.x;
            point[i].y = pt1[i].y + pox.y;
        }
    }
    else if (chose == 2)
    {
        CPoint pt1[4] = {CPoint(-7, -7), CPoint(7, -7), CPoint(7, 7), CPoint(-7, 7)};
        for (int i = 0; i < 4; i++)
        {
            point[i].x = pt1[i].x + pox.x;
            point[i].y = pt1[i].y + pox.y;
        }
    }
    else if (chose == 3)
    {
        CPoint pt1[4] = {CPoint(0, -10), CPoint(0, -10), CPoint(10, 10), CPoint(-10, 10)};
        for (int i = 0; i < 4; i++)
        {
            point[i].x = pt1[i].x + pox.x;
            point[i].y = pt1[i].y + pox.y;
        }
    }
}