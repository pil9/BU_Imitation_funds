
// BU_imitationDlg.h: 헤더 파일
//

#pragma once
#include "FormAccount.h"
#include "FormDeposit.h"

// CBUimitationDlg 대화 상자
class CBUimitationDlg : public CDialogEx
{
// 생성입니다.
public:
	CBUimitationDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BU_IMITATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	FormAccount *p_account;
	FormDeposit *p_deposit;
	void AllocForms();
	void ShowForm(int idx);

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic m_img_logo;
	CBitmapButton m_bitmapb1;
	afx_msg void OnStnClickedPictureView();
	afx_msg void OnStnClickedStaticRect();
	afx_msg void OnBnClickedButton3();
//	CButton menu_btn1;
	CBitmapButton menu_btn1;
	CBitmapButton menu_btn2;
	CBitmapButton menu_btn3;
	CBitmapButton menu_btn4;
	CBitmapButton menu_btn5;
	CBitmapButton menu_btn6;
	CBitmapButton menu_btn7;
	CBitmapButton menu_btn8;
	afx_msg void OnBnClickedButton4();
};
