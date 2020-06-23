#pragma once

class CProduct:public CObject
{
	DECLARE_SERIAL (CProduct);
public:
	CProduct();
	~CProduct();
	CProduct(CString name,int shape, COLORREF color, int m1, int m2, int m3, int m4, int m5 );
	virtual void Serialize(CArchive &ar);
    void SetName(CString name);
    void SetShape(int shape);
    void SetColor(COLORREF color);
    void SetM1(int m1);
    void SetM2(int m2);
    void SetM3(int m3);
    void SetM4(int m4);
    void SetM5(int m5);
    CString GetName();
    int GetShape();
    COLORREF GetColor();
    int GetM1();
    int GetM2();
    int GetM3();
    int GetM4();
    int GetM5();
private:
	CString m_Name;
	int m_Shape;
	COLORREF m_Color;
	int m_M1;
	int m_M2;
	int m_M3;
	int m_M4;
	int m_M5;
};

