
// BU_imitationDlg.cpp: 구현 파일
//
#pragma commnet(lib, "UxTheme.lib")

#include "pch.h"
#include "framework.h"
#include "BU_imitation.h"
#include "BU_imitationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBUimitationDlg 대화 상자



CBUimitationDlg::CBUimitationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BU_IMITATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	p_account = NULL;
	p_deposit = NULL;
}

void CBUimitationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE_VIEW, m_img_logo);
	DDX_Control(pDX, IDC_BUTTON3, menu_btn1);
	DDX_Control(pDX, IDC_BUTTON4, menu_btn2);
	DDX_Control(pDX, IDC_BUTTON1, menu_btn3);
	DDX_Control(pDX, IDC_BUTTON2, menu_btn4);
	DDX_Control(pDX, IDC_BUTTON5, menu_btn8);
	DDX_Control(pDX, IDC_BUTTON6, menu_btn5);
	DDX_Control(pDX, IDC_BUTTON7, menu_btn6);
	DDX_Control(pDX, IDC_BUTTON8, menu_btn7);
}

BEGIN_MESSAGE_MAP(CBUimitationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBUimitationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBUimitationDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_PICTURE_VIEW, &CBUimitationDlg::OnStnClickedPictureView)
	ON_STN_CLICKED(IDC_STATIC_RECT, &CBUimitationDlg::OnStnClickedStaticRect)
	ON_BN_CLICKED(IDC_BUTTON3, &CBUimitationDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBUimitationDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CBUimitationDlg 메시지 처리기

BOOL CBUimitationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP_MAIN_BG));
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	SetWindowText(_T("모의 금융 자산 관리 솔루션 '이미펀드'"));

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	AllocForms();
	menu_btn1.LoadBitmaps(IDB_BITMAP3, NULL, NULL, NULL);
	menu_btn1.SizeToContent();
	menu_btn2.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP1, NULL, NULL);
	menu_btn2.SizeToContent();
	menu_btn3.LoadBitmaps(IDB_BITMAP2, NULL, NULL, NULL);
	menu_btn3.SizeToContent();
	menu_btn4.LoadBitmaps(IDB_BITMAP5, NULL, NULL, NULL);
	menu_btn4.SizeToContent();
	menu_btn5.LoadBitmaps(IDB_BITMAP6, NULL, NULL, NULL);
	menu_btn5.SizeToContent();
	menu_btn6.LoadBitmaps(IDB_BITMAP7, NULL, NULL, NULL);
	menu_btn6.SizeToContent();
	menu_btn7.LoadBitmaps(IDB_BITMAP8, NULL, NULL, NULL);
	menu_btn7.SizeToContent();
	menu_btn8.LoadBitmaps(IDB_BITMAP9, NULL, NULL, NULL);
	menu_btn8.SizeToContent();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBUimitationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBUimitationDlg::OnPaint()
{
	
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetWindowRect(&rect); // 스크린과 호환되는 DC생성.
	HDC hMemDC = CreateCompatibleDC(dc);
	SetStretchBltMode(hMemDC, HALFTONE); // 호환DC에 비트맵을 선정.
	SelectObject(hMemDC, m_hBitmap); // 메모리 DC에서 스크린 DC로 이미지 복사
	StretchBlt(dc, 0, 0, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY); // 메모리 DC삭제
	DeleteDC(hMemDC);

	
	CStatic* bitmaptemp = (CStatic*)GetDlgItem(IDC_PICTURE_VIEW);
	CBitmap image;
	image.LoadBitmap(IDB_BITMAP_MAIN_LOGO);
	bitmaptemp->SetBitmap(image);

	//CDC memDC;
	//memDC.CreateCompatibleDC(m_img_logo.GetDC());
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP_MAIN_LOGO);
	//memDC.SelectObject(&bitmap);
	//// 컨트롤 박스 사이즈 구하는 부분
	//CStatic *staticSize = (CStatic *)GetDlgItem(IDC_PICTURE_VIEW);
	////CRect rect;
	//staticSize->GetClientRect(rect);
	//int iWidth = rect.Width();
	//int iHeight = rect.Height();
	//m_img_logo.GetDC()->StretchBlt(0, 0, iWidth, iHeight, &memDC, 0, 0, 200, 130, SRCCOPY);

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CBUimitationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBUimitationDlg::AllocForms()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC_RECT)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	p_account = new FormAccount();
	p_account->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM1, &context);
	p_account->OnInitialUpdate();
	p_account->ShowWindow(SW_SHOW);

	
	p_deposit = new FormDeposit();
	p_deposit->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM2, &context);
	p_deposit->OnInitialUpdate();
	p_deposit->ShowWindow(SW_HIDE);
	/*
	m_pForm3 = new CMyForm3();
	m_pForm3->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM3, &context);
	m_pForm3->OnInitialUpdate();
	m_pForm3->ShowWindow(SW_HIDE);*/

	//GetDlgItem(IDC_STATIC_RECT)->DestroyWindow();
}

void CBUimitationDlg::ShowForm(int idx)
{
	switch (idx)
	{
	case 0:
		p_account->ShowWindow(SW_SHOW);
		p_deposit->ShowWindow(SW_HIDE);

		break;
	case 1:
		p_account->ShowWindow(SW_HIDE);
		p_deposit->ShowWindow(SW_SHOW);
		break;
		/*
	case 2:
		m_pForm1->ShowWindow(SW_HIDE);
		m_pForm2->ShowWindow(SW_HIDE);
		m_pForm3->ShowWindow(SW_SHOW);
		break;
	}*/
	}
}

	void CBUimitationDlg::OnBnClickedButton1()
	{
		
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CBUimitationDlg::OnBnClickedButton2()
	{
		
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CBUimitationDlg::OnStnClickedPictureView()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CBUimitationDlg::OnStnClickedStaticRect()
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CBUimitationDlg::OnBnClickedButton3()
	{
		ShowForm(0);
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


	void CBUimitationDlg::OnBnClickedButton4()
	{
		ShowForm(1);
		// TODO: Add your control notification handler code here
	}
