#pragma once
class Line
{
public:
	Line(void);
	~Line(void);
	Line(CPoint start,CPoint end);
	
	CPoint Start;
	CPoint End;
	void SetStart(CPoint start);
	void SetEnd(CPoint end);
};

