
// JLL_EXAM3_3View.cpp : CJLL_EXAM3_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "JLL_EXAM3_3.h"
#endif

#include "JLL_EXAM3_3Doc.h"
#include "JLL_EXAM3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CJLL_EXAM3_3View

IMPLEMENT_DYNCREATE(CJLL_EXAM3_3View, CView)

BEGIN_MESSAGE_MAP(CJLL_EXAM3_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CJLL_EXAM3_3View 构造/析构

CJLL_EXAM3_3View::CJLL_EXAM3_3View()
{
	// TODO: 在此处添加构造代码

}

CJLL_EXAM3_3View::~CJLL_EXAM3_3View()
{
}

BOOL CJLL_EXAM3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CJLL_EXAM3_3View 绘制

void CJLL_EXAM3_3View::OnDraw(CDC* /*pDC*/)
{
	CJLL_EXAM3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CJLL_EXAM3_3View 打印

BOOL CJLL_EXAM3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CJLL_EXAM3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CJLL_EXAM3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CJLL_EXAM3_3View 诊断

#ifdef _DEBUG
void CJLL_EXAM3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CJLL_EXAM3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJLL_EXAM3_3Doc* CJLL_EXAM3_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJLL_EXAM3_3Doc)));
	return (CJLL_EXAM3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CJLL_EXAM3_3View 消息处理程序
