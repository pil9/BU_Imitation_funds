// FormAccount.cpp: 구현 파일
//

#include "pch.h"
#include "BU_imitation.h"
#include "FormAccount.h"


// FormAccount

IMPLEMENT_DYNCREATE(FormAccount, CFormView)

FormAccount::FormAccount()
	: CFormView(IDD_FORM1)
{
	
}

FormAccount::~FormAccount()
{
}
CFont g_editFont;
CFont gbox_editFont;
CFont gbox2_editFont;
void FormAccount::OnPaint() {
	m_hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_BITMAP_MAIN_BG));
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);
	CPaintDC dc(this); // device context for painting
	CRect rect;
	GetWindowRect(&rect); // 스크린과 호환되는 DC생성.
	HDC hMemDC = CreateCompatibleDC(dc);
	SetStretchBltMode(hMemDC, HALFTONE); // 호환DC에 비트맵을 선정.
	SelectObject(hMemDC, m_hBitmap); // 메모리 DC에서 스크린 DC로 이미지 복사
	StretchBlt(dc, 0, 0, rect.Width(), rect.Height(), hMemDC, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY); // 메모리 DC삭제
	DeleteDC(hMemDC);

	

}

void FormAccount::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_account_list);
}

BOOL FormAccount::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{
	

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormAccount::OnInitialUpdate()
{

	SetWindowTheme(GetDlgItem(IDC_STATIC_GBOX)->m_hWnd, _T(""), _T(""));
	SetWindowTheme(GetDlgItem(IDC_STATIC_GBOX2)->m_hWnd, _T(""), _T(""));
	g_editFont.CreatePointFont(150, TEXT("나눔바른고딕"));
	GetDlgItem(IDC_STATIC_TEXT1)->SetFont(&g_editFont);

	gbox_editFont.CreatePointFont(130, TEXT("나눔바른고딕"));
	GetDlgItem(IDC_STATIC_GBOX)->SetFont(&gbox_editFont);
	gbox2_editFont.CreatePointFont(130, TEXT("나눔바른고딕"));
	GetDlgItem(IDC_STATIC_GBOX2)->SetFont(&gbox_editFont);

	HFONT hNewFont;

	hNewFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1,
						  VARIABLE_PITCH | FF_MODERN, L"나눔바른고딕");
	

	CFormView::OnInitialUpdate();

	m_account_list.AddString(L"기업은행 102-1234-1236");
	m_account_list.AddString(L"국민은행 213-5890-9878");
	m_account_list.AddString(L"농협은행 324-5623-3453");
	m_account_list.AddString(L"하나은행 435-1254-8654");
	m_account_list.AddString(L"우리은행 546-8764-1235");
	m_account_list.AddString(L"신한은행 657-3457-4566");
	m_account_list.SendMessage(WM_SETFONT, (WPARAM)hNewFont, (LPARAM)TRUE);
}

BEGIN_MESSAGE_MAP(FormAccount, CFormView)
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_STATIC_TEXT1, &FormAccount::OnStnClickedStaticText1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &FormAccount::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON9, &FormAccount::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_STATIC_GBOX2, &FormAccount::OnBnClickedStaticGbox2)
END_MESSAGE_MAP()


// FormAccount 진단

#ifdef _DEBUG
void FormAccount::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormAccount::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormAccount 메시지 처리기


HBRUSH FormAccount::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_DLG) // 다이얼로그일 경우
	{
		CBrush B;
		B.CreateStockObject(NULL_BRUSH);
		pDC->SetBkMode(TRANSPARENT); // 투명 설정 

		return B;
	}
	else if (pWnd->GetDlgCtrlID() == (IDC_STATIC_TEXT1))
	{
		CBrush B;
		B.CreateStockObject(NULL_BRUSH);
		pDC->SetBkColor(RGB(40, 40, 43)); // 투명 설정 
		pDC->SetTextColor(RGB(255, 255, 255));
		return B;
	}


	switch (nCtlColor)

	{

	case CTLCOLOR_STATIC:

		pDC->SetTextColor(RGB(255, 255, 255));

		pDC->SetBkColor(RGB(40, 40, 43));

		return (HBRUSH)GetStockObject(NULL_BRUSH);

		break;

	}

	return hbr;
}


void FormAccount::OnStnClickedStaticText1()
{
	// TODO: Add your control notification handler code here
}


void FormAccount::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void FormAccount::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
}


void FormAccount::OnBnClickedStaticGbox2()
{
	// TODO: Add your control notification handler code here
}
