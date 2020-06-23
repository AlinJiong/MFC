// DlgMa.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "DlgMa.h"
#include "afxdialogex.h"


// DlgMa �Ի���

IMPLEMENT_DYNAMIC(DlgMa, CDialogEx)

DlgMa::DlgMa(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgMa::IDD, pParent)
{

}

DlgMa::~DlgMa()
{
}

void DlgMa::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	CString col[8] = {TEXT("��Ʒ��"),TEXT("��״"),TEXT("��ɫ"),TEXT("1��"),TEXT("2��"),TEXT("3��"),TEXT("4��"),TEXT("5��") };
	CRect r;
	m_list.GetClientRect(&r);
	for (int i = 0; i < 8; i++)
	{
		m_list.InsertColumn(i, col[i], LVCFMT_CENTER, (r.right - r.left) / 8);
	}
	UpdateDlg();
}


BEGIN_MESSAGE_MAP(DlgMa, CDialogEx)
END_MESSAGE_MAP()


// DlgMa ��Ϣ�������


void DlgMa::UpdateDlg(void)
{
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
