
// JLL_EXAM3_3View.cpp : CJLL_EXAM3_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CJLL_EXAM3_3View ����/����

CJLL_EXAM3_3View::CJLL_EXAM3_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CJLL_EXAM3_3View::~CJLL_EXAM3_3View()
{
}

BOOL CJLL_EXAM3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CJLL_EXAM3_3View ����

void CJLL_EXAM3_3View::OnDraw(CDC* /*pDC*/)
{
	CJLL_EXAM3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CJLL_EXAM3_3View ��ӡ

BOOL CJLL_EXAM3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CJLL_EXAM3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CJLL_EXAM3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CJLL_EXAM3_3View ���

#ifdef _DEBUG
void CJLL_EXAM3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CJLL_EXAM3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJLL_EXAM3_3Doc* CJLL_EXAM3_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJLL_EXAM3_3Doc)));
	return (CJLL_EXAM3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CJLL_EXAM3_3View ��Ϣ�������
