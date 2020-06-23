// DlgMa.cpp : 实现文件
//

#include "stdafx.h"
#include "JLL_EXAM3_3.h"
#include "DlgMa.h"
#include "afxdialogex.h"


// DlgMa 对话框

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
	CString col[8] = {TEXT("产品名"),TEXT("形状"),TEXT("颜色"),TEXT("1月"),TEXT("2月"),TEXT("3月"),TEXT("4月"),TEXT("5月") };
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


// DlgMa 消息处理程序


void DlgMa::UpdateDlg(void)
{
	m_list.DeleteAllItems();
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CJLL_EXAM3_3Doc* pDoc =(CJLL_EXAM3_3Doc*)pMainFrame->GetActiveDocument(); //获取当前doc
	vector<CProduct*> pts = pDoc->GetProduct();
	for(int i=0;i<pts.size();i++)
	{
	    int nRow = m_list.InsertItem(i, pts[i]->GetName());
	    CString list[7];
		CString color[4] ={TEXT("无"),TEXT("菱形"),TEXT("正方形"),TEXT("三角形")};
	    list[0] = color[pts[i]->GetShape()];
	    if(pts[i]->GetColor() == RGB(0,0,255))
	    {
	        list[1] = TEXT("蓝色");
	    }
	    else if(pts[i]->GetColor() ==  RGB(255,0,0))
	    {
	        list[1] = TEXT("红色");
	    }
	    else if(pts[i]->GetColor() == RGB(0,255,0))
	    {
	        list[1] = TEXT("绿色");
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
