// UserView.cpp : 实现文件
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "UserView.h"
using namespace std;


// CUserView

IMPLEMENT_DYNCREATE(CUserView, CView)

CUserView::CUserView()
{

}

CUserView::~CUserView()
{
}

BEGIN_MESSAGE_MAP(CUserView, CView)
END_MESSAGE_MAP()


// CUserView 绘图

void CUserView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	InitLine();
	InitPro();
}


// CUserView 诊断

#ifdef _DEBUG
void CUserView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserView 消息处理程序


void CUserView::InitPro(void)
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CRect rect1(rect.left + (rect.right - rect.left) / 5, rect.top + (rect.bottom - rect.top) / 10,
	            rect.right - (rect.right - rect.left) / 5, rect.bottom - (rect.bottom - rect.top) / 10);
	int widx = (rect1.right - rect1.left)/ 5;
	int widy = (rect1.bottom - rect1.top) / 9;
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //获取当前doc
	
	vector<CProduct*> pts =pDoc->GetProduct();
	Line line[4]; //设置折线
	
	for(int i = 0; i < pts.size(); i++)
	{
		line[0] = Line(CPoint(rect1.left + 1 * widx, rect1.bottom - pts[i]->GetM1() * widy / 5),
		               CPoint(rect1.left + 2 * widx, rect1.bottom - pts[i]->GetM2() * widy / 5));
		line[1] = Line(CPoint(rect1.left + 2 * widx, rect1.bottom - pts[i]->GetM2() * widy / 5),
		               CPoint(rect1.left + 3 * widx, rect1.bottom - pts[i]->GetM3() * widy / 5));
		line[2] = Line(CPoint(rect1.left + 3 * widx, rect1.bottom - pts[i]->GetM3() * widy / 5),
		               CPoint(rect1.left + 4 * widx, rect1.bottom - pts[i]->GetM4() * widy / 5));
		line[3] = Line(CPoint(rect1.left + 4 * widx, rect1.bottom - pts[i]->GetM4() * widy / 5),
		               CPoint(rect1.left + 5 * widx, rect1.bottom - pts[i]->GetM5() * widy / 5)); //绘制月份信息

		CPen pen = CPen(PS_SOLID, 3,pts[i]->GetColor()); //创建画笔和画刷
		CPen* oldPen = dc.SelectObject(&pen);
		CBrush brush(pts[i]->GetColor());
		CBrush* oldBrush = dc.SelectObject(&brush);
		for (int j = 0; j < 4; j++)
		{
			dc.MoveTo(line[j].Start);
			dc.LineTo(line[j].End);
			CShape shape(line[j].Start, pts[i]->GetShape());
			dc.Polygon(shape.point, 4);
		}
			CShape shape(line[3].End, pts[i]->GetShape()); //绘制小图标
		dc.Polygon(shape.point, 4);

		CShape shape1(CPoint(rect1.right + 40,rect1.top + i* widy) , pts[i]->GetShape()); //绘制小图标
		dc.Polygon(shape1.point, 4);
		dc.MoveTo(rect1.right + 10, rect1.top+i*widy);
		dc.LineTo(rect1.right + 70,rect1.top + i* widy);
		dc.TextOutW(rect1.right + 70,rect1.top + i* widy -10,pts[i]->GetName()); //绘制右侧产品信息
		
		dc.SelectObject(oldPen);
		dc.SelectObject(oldBrush);
		
	}
}


void CUserView::InitLine(void)
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CRect rect1(rect.left + (rect.right - rect.left) / 5, rect.top + (rect.bottom - rect.top) / 10,
	            rect.right - (rect.right - rect.left) / 5, rect.bottom - (rect.bottom - rect.top) / 10);
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
	dc.TextOut((rect.right - rect.left) / 2 - (rect.right - rect.left) / 20, 10, CString(_T("车床生产数据图")));
	Line line[16];
	int widx = (rect1.right - rect1.left) / 5;
	int widy = (rect1.bottom - rect1.top) / 9;
	for (int i = 0; i < 10; i++) //绘制横排横线
	{
		line[i] = Line(CPoint(rect1.left, rect1.bottom - i * widy), CPoint(rect1.right, rect1.bottom - i * widy));
		CString output; //产量信息
		output.Format(_T("%d"), i * 5);
		dc.TextOutW(line[i].Start.x - 20, line[i].Start.y - 10, output); //输出产量信息
	}
	
	line[10] = Line(CPoint(rect1.left,rect1.bottom),CPoint(rect1.left,rect1.top));  //最左边的横线
	CString Mouth[5] = {TEXT("一月"), TEXT("二月"), TEXT("三月"), TEXT("四月"), TEXT("五月")};

	for (int i = 1; i <= 5; i++)
	{
		line[i + 10] = Line(CPoint(rect1.left + i * widx, rect1.bottom),
		                    CPoint(rect1.left + i * widx, rect1.bottom - 10));
		dc.TextOutW(line[i + 10].Start.x - 20, line[i + 10].Start.y, Mouth[i - 1]); //绘制月份
	}

	for (int i = 0; i <= 15; i++)
	{
		dc.MoveTo(line[i].Start);
		dc.LineTo(line[i].End);
	}
	dc.SelectObject(oldPen);
}
