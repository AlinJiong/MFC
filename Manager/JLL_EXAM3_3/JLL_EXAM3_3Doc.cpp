
// JLL_EXAM3_3Doc.cpp : CJLL_EXAM3_3Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CJLL_EXAM3_3Doc 构造/析构

CJLL_EXAM3_3Doc::CJLL_EXAM3_3Doc()
{
	// TODO: 在此添加一次性构造代码
	CProduct *p1=new CProduct(TEXT("产品1"),1,RGB(0,0,255),40,37,23,23,40);
	CProduct *p2=new CProduct(TEXT("产品2"),2,RGB(255,0,0),30,26,27,35,24);
	CProduct *p3=new CProduct(TEXT("产品3"),3,RGB(0,255,0),23,21,38,37,21);
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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CJLL_EXAM3_3Doc 序列化

void CJLL_EXAM3_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for(int i=0;i<product.size();i++)
		{
			ar << product[i];
		}
		// TODO: 在此添加存储代码
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
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CJLL_EXAM3_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CJLL_EXAM3_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CJLL_EXAM3_3Doc 诊断

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


// CJLL_EXAM3_3Doc 命令


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
