
// JLL_EXAM3_3Doc.cpp : CJLL_EXAM3_3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "JLL_EXAM3_3.h"
#endif

#include "JLL_EXAM3_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CJLL_EXAM3_3Doc

IMPLEMENT_DYNCREATE(CJLL_EXAM3_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CJLL_EXAM3_3Doc, CDocument)
END_MESSAGE_MAP()


// CJLL_EXAM3_3Doc ����/����

CJLL_EXAM3_3Doc::CJLL_EXAM3_3Doc()
{
	// TODO: �ڴ����һ���Թ������
	CProduct *p1=new CProduct(TEXT("��Ʒ1"),1,RGB(0,0,255),40,37,23,23,40);
	CProduct *p2=new CProduct(TEXT("��Ʒ2"),2,RGB(255,0,0),30,26,27,35,24);
	CProduct *p3=new CProduct(TEXT("��Ʒ3"),3,RGB(0,255,0),23,21,38,37,21);
	product.push_back(p1);
	product.push_back(p2);
	product.push_back(p3);

}

CJLL_EXAM3_3Doc::~CJLL_EXAM3_3Doc()
{
}

BOOL CJLL_EXAM3_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CJLL_EXAM3_3Doc ���л�

void CJLL_EXAM3_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for(int i=0;i<product.size();i++)
		{
			ar << product[i];
		}
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		int size = product.size();
		product.clear();
		for(int i=0;i<size;i++)
		{
			CProduct *pt = (CProduct*) ar.ReadObject(RUNTIME_CLASS(CProduct));
			product.push_back(pt);
		}
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CJLL_EXAM3_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CJLL_EXAM3_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CJLL_EXAM3_3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CJLL_EXAM3_3Doc ���

#ifdef _DEBUG
void CJLL_EXAM3_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJLL_EXAM3_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CJLL_EXAM3_3Doc ����


vector<CProduct*>  CJLL_EXAM3_3Doc::GetProduct()
{
	return product;
}

void CJLL_EXAM3_3Doc::AddPro(CProduct * pro)
{
	product.push_back(pro);
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}


void CJLL_EXAM3_3Doc::ChangePro(int index, CString name, int shape, COLORREF color, int m1, int m2, int m3, int m4, int m5)
{
    product[index]->SetName(name);
    product[index]->SetShape(shape);
    product[index]->SetColor(color);
    product[index]->SetM1(m1);
    product[index]->SetM2(m2);
    product[index]->SetM3(m3);
    product[index]->SetM4(m4);
    product[index]->SetM5(m5);
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}

void CJLL_EXAM3_3Doc::DeletePro(int index)
{
	product.erase(product.begin()+index);
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}
