
// JLL_EXAM3_3View.h : CJLL_EXAM3_3View ��Ľӿ�
//

#pragma once


class CJLL_EXAM3_3View : public CView
{
protected: // �������л�����
	CJLL_EXAM3_3View();
	DECLARE_DYNCREATE(CJLL_EXAM3_3View)

// ����
public:
	CJLL_EXAM3_3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CJLL_EXAM3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // JLL_EXAM3_3View.cpp �еĵ��԰汾
inline CJLL_EXAM3_3Doc* CJLL_EXAM3_3View::GetDocument() const
   { return reinterpret_cast<CJLL_EXAM3_3Doc*>(m_pDocument); }
#endif

