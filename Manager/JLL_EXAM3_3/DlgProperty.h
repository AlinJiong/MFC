#pragma once
#include "afxwin.h"
#include"resource.h"

// DlgProperty �Ի���

class DlgProperty : public CDialogEx
{
	DECLARE_DYNAMIC(DlgProperty)

public:
	DlgProperty(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgProperty();

// �Ի�������
	enum { IDD = IDD_DlgPro };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox CShape;
	CComboBox CColor;
	CString shape;
	CString color;
	CString name;
	int m1;
	int m2;
	int m3;
	int m4;
	int m5;
	CString title;
	virtual BOOL OnInitDialog();
};
