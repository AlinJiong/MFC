#pragma once
#include "afxcmn.h"


// DlgMa �Ի���

class DlgMa : public CDialogEx
{
	DECLARE_DYNAMIC(DlgMa)

public:
	DlgMa(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgMa();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	void UpdateDlg(void);
};
