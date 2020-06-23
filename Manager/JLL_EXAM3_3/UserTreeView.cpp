// UserTreeView.cpp : ʵ���ļ�
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


// CUserTreeView ���

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


// CUserTreeView ��Ϣ�������


void CUserTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	m_tree.ModifyStyle(0, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
	HTREEITEM root = m_tree.InsertItem(TEXT("��Ʒ����"),0,NULL,NULL);
	HTREEITEM s = m_tree.InsertItem(TEXT("��Ʒ1"),1,NULL,root);
	HTREEITEM m = m_tree.InsertItem(TEXT("��Ʒ2"),1,NULL,root);
	HTREEITEM l = m_tree.InsertItem(TEXT("��Ʒ3"),1,NULL,root);
	// TODO: �ڴ����ר�ô����/����û���
}


void CUserTreeView::Update(void)
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //��ȡ��ǰdoc
	vector<CProduct*> pts = pDoc->GetProduct();
	CTreeCtrl &m_tree = this->GetTreeCtrl();
	m_tree.DeleteAllItems();
	HTREEITEM root = m_tree.InsertItem(TEXT("��Ʒ����"),0,NULL,NULL);
	for(int i=0;i<pts.size();i++)
	{
		m_tree.InsertItem(pts[i]->GetName(),1,NULL,root);
	}
}
