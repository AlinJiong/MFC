#pragma once


// CUserView ��ͼ

class CUserView : public CView
{
	DECLARE_DYNCREATE(CUserView)

protected:
	CUserView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	void InitPro(void);
	void InitLine(void);
};


