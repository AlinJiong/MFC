#pragma once


// CUserListView 视图

class CUserListView : public CListView
{
	DECLARE_DYNCREATE(CUserListView)

protected:
	CUserListView();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void Update(void);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAdd();
	afx_msg void OnMa();
};


