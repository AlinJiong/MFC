// UserListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "UserListView.h"
#include"DlgMa.h"


// CUserListView

IMPLEMENT_DYNCREATE(CUserListView, CListView)

CUserListView::CUserListView()
{

}

CUserListView::~CUserListView()
{
}

BEGIN_MESSAGE_MAP(CUserListView, CListView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &CUserListView::OnAdd)
	ON_COMMAND(ID_32772, &CUserListView::OnMa)
END_MESSAGE_MAP()


// CUserListView ���

#ifdef _DEBUG
void CUserListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserListView ��Ϣ�������


void CUserListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	CRect rect;
	GetClientRect(&rect);

	// TODO: �ڴ����ר�ô����/����û���
	CListCtrl &m_list = this->GetListCtrl();
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.ModifyStyle(0,LVS_REPORT);
	CString col[8] = {TEXT("��Ʒ��"),TEXT("��״"),TEXT("��ɫ"),TEXT("1��"),TEXT("2��"),TEXT("3��"),TEXT("4��"),TEXT("5��")};
	for (int i = 0; i < 8; i++)
	{
		m_list.InsertColumn(i, col[i], LVCFMT_CENTER, rect.Width()/8);
	}
	Update();
}


void CUserListView::Update(void)
{
	CListCtrl &m_list = this->GetListCtrl();
	m_list.DeleteAllItems();
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //��ȡ��ǰdoc

	vector<CProduct*> pts = pDoc->GetProduct();
	for(int i=0;i<pts.size();i++)
	{
	    int nRow = m_list.InsertItem(i, pts[i]->GetName());
	    CString list[7];
		CString color[4] ={TEXT("��"),TEXT("����"),TEXT("������"),TEXT("������")};
	    list[0] = color[pts[i]->GetShape()];
	    if(pts[i]->GetColor() == RGB(0,0,255))
	    {
	        list[1] = TEXT("��ɫ");
	    }
	    else if(pts[i]->GetColor() ==  RGB(255,0,0))
	    {
	        list[1] = TEXT("��ɫ");
	    }
	    else if(pts[i]->GetColor() == RGB(0,255,0))
	    {
	        list[1] = TEXT("��ɫ");
	    }
	    list[2].Format(_T("%d"), pts[i]->GetM1());
	    list[3].Format(_T("%d"), pts[i]->GetM2());
	    list[4].Format(_T("%d"), pts[i]->GetM3());
	    list[5].Format(_T("%d"), pts[i]->GetM4());
	    list[6].Format(_T("%d"), pts[i]->GetM5());
	    for(int j=0;j<7;j++)
	    {
	        m_list.SetItemText(nRow,j+1,list[j]);
	    }
	    nRow++;
	}
}


void CUserListView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//DlgProperty dlg;
	//dlg.DoModal();
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //��ȡ��ǰdoc
	vector<CProduct*> pts = pDoc->GetProduct();
	CListCtrl &m_list = this->GetListCtrl();
	CString str;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("���Ӷ���"));
		DlgProperty dlg;
		dlg.title=TEXT("��������");
		COLORREF m_color;
		int m_shape;
		if (dlg.DoModal() == IDOK)
		{
		    if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(0, 0, 255);
		    }
		    else if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(255, 0, 0);
		    }
		    else if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(0, 255, 0);
		    }
		    if (dlg.shape == TEXT("����"))
		    {
		        m_shape = 1;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 2;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 3;
		    }
			pDoc->AddPro(new CProduct(dlg.name, m_shape, m_color, dlg.m1, dlg.m2, dlg.m3, dlg.m4, dlg.m5));
			Update();
	        CUserTreeView* treeView = (CUserTreeView*)pMainFrame->sWnd.GetPane(0,0);
			treeView->Update();
		}
	}
	else
	{
		int i = m_list.GetNextSelectedItem(pos);
		str.Format(_T("�޸��˵�%d��"), i);
		MessageBox(str);
		DlgProperty dlg;
		dlg.name = pts[i]->GetName();
		dlg.m1 = pts[i]->GetM1();
		dlg.m2 = pts[i]->GetM2();
		dlg.m3 = pts[i]->GetM3();
		dlg.m4 = pts[i]->GetM4();
		dlg.m5 = pts[i]->GetM5();
		if (pts[i]->GetColor() == RGB(0, 0, 255))
		{
			dlg.color = TEXT("��ɫ");
		}
		else if (pts[i]->GetColor() == RGB(255, 0, 0))
		{
			dlg.color = TEXT("��ɫ");
		}
		else if (pts[i]->GetColor() == RGB(0, 255, 0))
		{
			dlg.color = TEXT("��ɫ");
		}
		if (pts[i]->GetShape() == 1)
		{
			dlg.shape = TEXT("����");
		}
		else if (pts[i]->GetShape() == 2)
		{
			dlg.shape = TEXT("������");
		}

		else if (pts[i]->GetShape() == 3)
		{
		    dlg.shape = TEXT("������");
		}

		COLORREF m_color;
		int m_shape;
		if (dlg.DoModal() == IDOK)
		{
		    if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(0, 0, 255);
		    }
		    else if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(255, 0, 0);
		    }
		    else if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(0, 255, 0);
		    }
		    if (dlg.shape == TEXT("����"))
		    {
		        m_shape = 1;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 2;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 3;
		    }
		    pDoc->ChangePro(i, dlg.name, m_shape, m_color, dlg.m1, dlg.m2, dlg.m3, dlg.m4, dlg.m5);
			Update();
		    CListView::OnLButtonDblClk(nFlags, point);
		}
	}
}


void CUserListView::OnAdd()
{
	// TODO: �ڴ���������������
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //��ȡ��ǰdoc
	DlgProperty dlg;
	dlg.title=TEXT("��������");
	COLORREF m_color;
	int m_shape;
	if (dlg.DoModal() == IDOK)
	{
	    if (dlg.color == TEXT("��ɫ"))
	    {
	        m_color = RGB(0, 0, 255);
	    }
	    else if (dlg.color == TEXT("��ɫ"))
	    {
	        m_color = RGB(255, 0, 0);
	    }
	    else if (dlg.color == TEXT("��ɫ"))
		    {
		        m_color = RGB(0, 255, 0);
		    }
		    if (dlg.shape == TEXT("����"))
		    {
		        m_shape = 1;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 2;
		    }
		    if (dlg.shape == TEXT("������"))
		    {
		        m_shape = 3;
		    }
			pDoc->AddPro(new CProduct(dlg.name, m_shape, m_color, dlg.m1, dlg.m2, dlg.m3, dlg.m4, dlg.m5));
			Update();
	        CUserTreeView* treeView = (CUserTreeView*)pMainFrame->sWnd.GetPane(0,0);
			treeView->Update();
	}
}


void CUserListView::OnMa()
{
	DlgMa dlg;
	dlg.DoModal();
	return;
	// TODO: �ڴ���������������
}
