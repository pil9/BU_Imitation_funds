#pragma once



// FormAccount 폼 보기

class FormAccount : public CFormView
{
	DECLARE_DYNCREATE(FormAccount)
	
public:
	FormAccount();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~FormAccount();
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;
public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM1 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedStaticText1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedStaticGbox2();
private:
	CListBox m_account_list;
};


