// DlgProperty.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "DlgProperty.h"
#include "afxdialogex.h"


// DlgProperty �Ի���

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
	name = TEXT("��Ʒ1");
	color=TEXT("��ɫ");
	shape=TEXT("����");
	title = TEXT("����");
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
	CShape.AddString(TEXT("����"));
	CShape.AddString(TEXT("������"));
	CShape.AddString(TEXT("������"));
	CColor.AddString(TEXT("��ɫ"));
	CColor.AddString(TEXT("��ɫ"));
	CColor.AddString(TEXT("��ɫ"));
}


BEGIN_MESSAGE_MAP(DlgProperty, CDialogEx)
END_MESSAGE_MAP()


// DlgProperty ��Ϣ�������



BOOL DlgProperty::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(title);
	return TRUE;
}
