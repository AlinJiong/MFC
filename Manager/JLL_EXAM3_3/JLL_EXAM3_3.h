
// JLL_EXAM3_3.h : JLL_EXAM3_3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CJLL_EXAM3_3App:
// 有关此类的实现，请参阅 JLL_EXAM3_3.cpp
//

class CJLL_EXAM3_3App : public CWinAppEx
{
public:
	CJLL_EXAM3_3App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CJLL_EXAM3_3App theApp;
