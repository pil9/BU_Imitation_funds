// FormAudio.cpp: 구현 파일
//

#include "pch.h"
#include "BU_imitation.h"
#include "FormAudio.h"


// FormAudio

IMPLEMENT_DYNCREATE(FormAudio, CFormView)

FormAudio::FormAudio()
	: CFormView(IDD_DIALOG1)
{

}

FormAudio::~FormAudio()
{
}

void FormAudio::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormAudio, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &FormAudio::OnBnClickedButton1)
END_MESSAGE_MAP()


// FormAudio 진단

#ifdef _DEBUG
void FormAudio::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormAudio::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormAudio 메시지 처리기


void FormAudio::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
