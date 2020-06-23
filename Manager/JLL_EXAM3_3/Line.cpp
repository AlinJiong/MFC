#include "stdafx.h"
#include "Line.h"

Line::Line(void)
{
}

Line::~Line(void)
{
}

Line::Line(CPoint start, CPoint end)
{
    Start = start;
    End = end;
}

void Line::SetStart(CPoint start)
{
    Start = start;
}

void Line::SetEnd(CPoint end)
{
    End = end;
}