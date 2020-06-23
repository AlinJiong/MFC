
// test2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// Ctest2Dlg 对话框
class Ctest2Dlg : public CDialogEx
{
// 构造
public:
	Ctest2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	CPoint mid;    //中心点位
protected:
	void DrawFace(CDC* pDC);
	void DrawHand(CDC* pDC, int nLength, int nDegrees, COLORREF Color);
};
