
// JLL_EXAM3_3.h : JLL_EXAM3_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CJLL_EXAM3_3App:
// �йش����ʵ�֣������ JLL_EXAM3_3.cpp
//

class CJLL_EXAM3_3App : public CWinAppEx
{
public:
	CJLL_EXAM3_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CJLL_EXAM3_3App theApp;
