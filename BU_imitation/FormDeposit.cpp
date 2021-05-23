// FormDeposit.cpp: 구현 파일
//

#include "pch.h"
#include "BU_imitation.h"
#include "FormDeposit.h"



// FormDeposit 대화 상자

IMPLEMENT_DYNAMIC(FormDeposit, CFormView)

FormDeposit::FormDeposit()
	: CFormView(IDD_FORM2)
{

}

FormDeposit::~FormDeposit()
{
}

void FormDeposit::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL FormDeposit::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT & rect, CWnd * pParentWnd, UINT nID, CCreateContext * pContext)
{
	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void FormDeposit::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
}


BEGIN_MESSAGE_MAP(FormDeposit, CFormView)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// FormDeposit 메시지 처리기


HBRUSH FormDeposit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_DLG) // 다이얼로그일 경우
	{
		CBrush B;
		B.CreateStockObject(NULL_BRUSH);
		pDC->SetBkMode(TRANSPARENT); // 투명 설정 

		return B;
	}
	return hbr;
}
