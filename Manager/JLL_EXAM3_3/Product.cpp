#include "stdafx.h"
#include "Product.h"

IMPLEMENT_SERIAL(CProduct , CObject,VERSIONABLE_SCHEMA|1);

CProduct::CProduct()
{
}


CProduct::~CProduct()
{
}

void CProduct::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<m_Name <<m_Shape<<m_Color<<m_M1<<m_M2<<m_M3<<m_M4<<m_M5;
	}
	else
	{
		ar >> m_Name >> m_Shape >> m_Color >> m_M1 >> m_M2 >> m_M3 >> m_M4 >> m_M5;
	}
}

CProduct::CProduct(CString name, int shape, COLORREF color, int m1, int m2, int m3, int m4, int m5)
{
    m_Name = name;
    m_Shape = shape;
    m_Color = color;
    m_M1 = m1;
    m_M2 = m2;
    m_M3 = m3;
    m_M4 = m4;
    m_M5 = m5;
}

void CProduct::SetName(CString name)
{
    name = m_Name;
}

void CProduct::SetShape(int shape)
{
    m_Shape = shape;
}

void CProduct::SetColor(COLORREF color)
{
    m_Color = color;
}

void CProduct::SetM1(int m1)
{
    m_M1 = m1;
}

void CProduct::SetM2(int m2)
{
    m_M2 = m2;
}

void CProduct::SetM3(int m3)
{
    m_M3 = m3;
}

void CProduct::SetM4(int m4)
{
    m_M4 = m4;
}

void CProduct::SetM5(int m5)
{
    m_M5 = m5;
}

CString CProduct::GetName()
{
    return m_Name;
}
int CProduct::GetShape()
{
    return m_Shape;
}
COLORREF CProduct::GetColor()
{
    return m_Color;
}
int CProduct::GetM1()
{
    return m_M1;
}
int CProduct::GetM2()
{
    return m_M2;
}
int CProduct::GetM3()
{
    return m_M3;
}
int CProduct::GetM4()
{
    return m_M4;
}
int CProduct::GetM5()
{
    return m_M5;
}