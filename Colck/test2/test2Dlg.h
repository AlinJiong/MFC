
// test2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Ctest2Dlg �Ի���
class Ctest2Dlg : public CDialogEx
{
// ����
public:
	Ctest2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedButton1();
	//bool Is_fast;
	void Draw(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CFont DateFont;
	CFont TimeFont;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int pre_Hour;
	int pre_Minute;
	int pre_Second;
	CPoint mid;    //���ĵ�λ
protected:
	void DrawFace(CDC* pDC);
	void DrawHand(CDC* pDC, int nLength, int nDegrees, COLORREF Color);
};
