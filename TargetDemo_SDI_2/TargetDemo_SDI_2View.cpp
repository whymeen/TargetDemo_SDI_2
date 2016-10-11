
// TargetDemo_SDI_2View.cpp : CTargetDemo_SDI_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TargetDemo_SDI_2.h"
#endif

#include "TargetDemo_SDI_2Doc.h"
#include "TargetDemo_SDI_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTargetDemo_SDI_2View

IMPLEMENT_DYNCREATE(CTargetDemo_SDI_2View, CFormView)

BEGIN_MESSAGE_MAP(CTargetDemo_SDI_2View, CFormView)
END_MESSAGE_MAP()

// CTargetDemo_SDI_2View 생성/소멸

CTargetDemo_SDI_2View::CTargetDemo_SDI_2View()
	: CFormView(IDD_TARGETDEMO_SDI_2_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTargetDemo_SDI_2View::~CTargetDemo_SDI_2View()
{
}

void CTargetDemo_SDI_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CTargetDemo_SDI_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CTargetDemo_SDI_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTargetDemo_SDI_2View 진단

#ifdef _DEBUG
void CTargetDemo_SDI_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CTargetDemo_SDI_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTargetDemo_SDI_2Doc* CTargetDemo_SDI_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTargetDemo_SDI_2Doc)));
	return (CTargetDemo_SDI_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTargetDemo_SDI_2View 메시지 처리기
