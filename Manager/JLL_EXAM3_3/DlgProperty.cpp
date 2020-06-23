// DlgProperty.cpp : 实现文件
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "DlgProperty.h"
#include "afxdialogex.h"


// DlgProperty 对话框

IMPLEMENT_DYNAMIC(DlgProperty, CDialogEx)

DlgProperty::DlgProperty(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgProperty::IDD, pParent)
	, shape(_T(""))
	, color(_T(""))
	, name(_T(""))
	, m1(0)
	, m2(0)
	, m3(0)
	, m4(0)
	, m5(0)
{
	name = TEXT("产品1");
	color=TEXT("绿色");
	shape=TEXT("菱形");
	title = TEXT("属性");
}

DlgProperty::~DlgProperty()
{
}

void DlgProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, CShape);
	DDX_Control(pDX, IDC_COMBO2, CColor);
	DDX_CBString(pDX, IDC_COMBO1, shape);
	DDX_CBString(pDX, IDC_COMBO2, color);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, m1);
	DDX_Text(pDX, IDC_EDIT3, m2);
	DDX_Text(pDX, IDC_EDIT4, m3);
	DDX_Text(pDX, IDC_EDIT5, m4);
	DDX_Text(pDX, IDC_EDIT6, m5);
	CShape.AddString(TEXT("菱形"));
	CShape.AddString(TEXT("正方形"));
	CShape.AddString(TEXT("三角形"));
	CColor.AddString(TEXT("蓝色"));
	CColor.AddString(TEXT("红色"));
	CColor.AddString(TEXT("绿色"));
}


BEGIN_MESSAGE_MAP(DlgProperty, CDialogEx)
END_MESSAGE_MAP()


// DlgProperty 消息处理程序



BOOL DlgProperty::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(title);
	return TRUE;
}
