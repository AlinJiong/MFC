
// JLL_EXAM3_3View.h : CJLL_EXAM3_3View 类的接口
//

#pragma once


class CJLL_EXAM3_3View : public CView
{
protected: // 仅从序列化创建
	CJLL_EXAM3_3View();
	DECLARE_DYNCREATE(CJLL_EXAM3_3View)

// 特性
public:
	CJLL_EXAM3_3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CJLL_EXAM3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // JLL_EXAM3_3View.cpp 中的调试版本
inline CJLL_EXAM3_3Doc* CJLL_EXAM3_3View::GetDocument() const
   { return reinterpret_cast<CJLL_EXAM3_3Doc*>(m_pDocument); }
#endif

