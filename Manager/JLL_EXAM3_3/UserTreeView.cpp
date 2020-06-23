// UserTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "UserTreeView.h"


// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{

}

CUserTreeView::~CUserTreeView()
{
}

BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
END_MESSAGE_MAP()


// CUserTreeView 诊断

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserTreeView 消息处理程序


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	m_tree.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
	HTREEITEM root = m_tree.InsertItem(TEXT("产品管理"),0,NULL,NULL);
	HTREEITEM s = m_tree.InsertItem(TEXT("产品1"),1,NULL,root);
	HTREEITEM m = m_tree.InsertItem(TEXT("产品2"),1,NULL,root);
	HTREEITEM l = m_tree.InsertItem(TEXT("产品3"),1,NULL,root);
	// TODO: 在此添加专用代码和/或调用基类
}


void CUserTreeView::Update(void)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //获取当前doc
	vector<CProduct*> pts = pDoc->GetProduct();
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	m_tree.DeleteAllItems();
	HTREEITEM root = m_tree.InsertItem(TEXT("产品管理"),0,NULL,NULL);
	for(int i=0;i<pts.size();i++)
	{
		m_tree.InsertItem(pts[i]->GetName(),1,NULL,root);
	}
}
