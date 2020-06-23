
// test2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test2.h"
#include "test2Dlg.h"
#include "afxdialogex.h"
#include"resource.h"
#include"math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#define Rectsize 2
#define Ellipsesize 1
#define PI 3.14159265358979323846
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest2Dlg �Ի���



Ctest2Dlg::Ctest2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest2Dlg::IDD, pParent)
	, pre_Hour(0)
	, pre_Minute(0)
	, pre_Second(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, &Ctest2Dlg::OnMcnSelchangeMonthcalendar1)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Ctest2Dlg ��Ϣ�������

BOOL Ctest2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	mid=CPoint(155,155);


	SetTimer(1, 1000, NULL);
	DateFont.CreatePointFont(100,_T("����"),NULL);
	TimeFont.CreatePointFont(100,_T("����"),NULL);
	GetDlgItem(IDC_STATIC1)->SetFont(&DateFont);
	GetDlgItem(IDC_STATIC2)->SetFont(&TimeFont); //�������ں����������ʽ

	CTime time=CTime::GetCurrentTime();
	pre_Hour = time.GetHour()% 12;
	pre_Minute = time.GetMinute();
	pre_Second = time.GetSecond();
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Ctest2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ctest2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		dc.FillSolidRect(rect,RGB(255,255,255)); //��������У��ı䱳����ɫ��
		CDialogEx::OnPaint();
	}
	Draw();
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ctest2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest2Dlg::OnMcnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
		*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

//void Ctest2Dlg::OnBnClickedButton1()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	Is_fast = false;
//	Invalidate ();
//}


//void Ctest2Dlg::OnBnClickedButton2()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	Is_fast = true;
//	Invalidate ();
//}



void Ctest2Dlg::Draw(void)
{
	CClientDC dc(this);
	DrawFace(&dc);
}


void Ctest2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString CDate,CTimes,CWeek,str;
	CDate = CTime::GetCurrentTime().Format(_T("%Y��%m��%d��"));
	GetDlgItem(IDC_STATIC1)->SetWindowText(CDate);   //��ȡ�ؼ�
	CTimes = CTime::GetCurrentTime().Format(_T("%H:%M:%S"));
	GetDlgItem(IDC_STATIC2)->SetWindowText(CTimes);
	str = CTime::GetCurrentTime().Format(_T("%w"));
	CWeek = str == "0" ? "������" : str == "1" ? "����һ" : str == "2" ? "���ڶ�" : str == "3" ?
		"������" : str == "4" ? "������" : str == "5" ? "������" : str == "6" ? "������" : "-1";
	GetDlgItem(IDC_STATIC3)->SetWindowText(CWeek);

	CClientDC dc(this);
	int nSecond, nMinute, nHour;
	COLORREF clrColor = ::GetSysColor (COLOR_3DFACE);
	CTime time = CTime::GetCurrentTime ();
	nSecond = time.GetSecond ();
	nMinute = time.GetMinute ();
	nHour = time.GetHour () % 12;
	if ((nSecond == pre_Second) &&
		(nMinute == pre_Minute) &&
		(nHour == pre_Hour))
		return;

	if (nHour != pre_Hour)
	{
		DrawHand(&dc, 30, pre_Hour*5+(int)(nMinute/12)%5, RGB(255, 255, 255));
		DrawHand(&dc, 30, nHour*5, RGB(255,0,0));
		pre_Hour = nHour;
	}

	if (nMinute != pre_Minute) {
		DrawHand (&dc, 60,pre_Minute,RGB(255,255,255));
		DrawHand (&dc, 60,nMinute,RGB(0,0,255));
		pre_Minute = nMinute;
		pre_Hour = nHour;
	}

	if (nSecond != pre_Second) 
	{
		DrawHand (&dc, 80,pre_Second,RGB(255,255,255));
		DrawHand (&dc, 80,nSecond,RGB(0,0,0));
		pre_Second = nSecond;
	}
	DrawHand(&dc, 30, nHour*5+(int)(nMinute/12)%5, RGB(255,0,0));
	DrawHand (&dc, 60,nMinute,RGB(0,0,255));
	DrawHand (&dc, 80,nSecond,RGB(0,0,0));
	CDialogEx::OnTimer(nIDEvent);
}


//�޸�Static Botton��ɫ
HBRUSH Ctest2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(147,112,219));
		pDC->SetBkColor(RGB(255,255,255));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC2)
	{
		pDC->SetTextColor(RGB(233,130,219));
		pDC->SetBkColor(RGB(255,255,255));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC3)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkColor(RGB(255,255,255));
	}
	return hbr;
}


void Ctest2Dlg::DrawFace(CDC* pDC)
{
	
	//CPoint mid=CPoint(155,155);//���ĵ�
	int Redius = 95;           //ʱ�Ӱ뾶
	CBrush bushHour(RGB(255,0,0));
	CBrush bushMinute(RGB(255,255,255));
	for (int i = 0; i < 60; i++)
	{
		CPoint point;
		point.x = (int)(mid.x + cos((PI / 30) * i) * Redius);
		point.y = (int)(mid.y - sin((PI / 30) * i) * Redius);
		//����ʱ�ӵ�λ
		if(i%5==0)
		{
			pDC->SelectObject(&bushHour);
			pDC->Rectangle(point.x - Rectsize, point.y - Rectsize, point.x + Rectsize, point.y + Rectsize);
		}
		//���Ʒ���λ��
		else 
		{
			pDC->SelectObject(&bushMinute);
			pDC->Ellipse(point.x - Ellipsesize, point.y - Ellipsesize, point.x + Ellipsesize, point.y + Ellipsesize);
		}
	}
	//���ĵ�λ
	pDC->SelectObject(&bushHour);
	pDC->Rectangle(mid.x - Rectsize, mid.y - Rectsize, mid.x + Rectsize, mid.y + Rectsize);
}


void Ctest2Dlg::DrawHand(CDC* pDC, int nLength, int nDegrees, COLORREF Color)
{
	CPoint point,point1;
	point.x = (int)(mid.x + sin((PI / 30) * nDegrees) * nLength);
	point.y = (int)(mid.y - cos((PI / 30) * nDegrees) * nLength);
	point1.x = int(mid.x - 0.2*(point.x-mid.x));
	point1.y = int(mid.y - 0.2*(point.y-mid.y));
	CPen pen (PS_SOLID, 0, Color);
	CPen* pOldPen = pDC->SelectObject (&pen); 
	pDC->SelectObject(&pen);
	pDC->MoveTo(mid.x,mid.y);
	pDC->LineTo(point.x,point.y);
	pDC->MoveTo(mid.x,mid.y);
	pDC->LineTo(point1.x, point1.y);
	pDC->SelectObject (pOldPen);
}
