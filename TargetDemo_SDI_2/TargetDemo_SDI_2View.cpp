
// TargetDemo_SDI_2View.cpp : CTargetDemo_SDI_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CTargetDemo_SDI_2View ����/�Ҹ�

CTargetDemo_SDI_2View::CTargetDemo_SDI_2View()
	: CFormView(IDD_TARGETDEMO_SDI_2_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CTargetDemo_SDI_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CTargetDemo_SDI_2View ����

#ifdef _DEBUG
void CTargetDemo_SDI_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CTargetDemo_SDI_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTargetDemo_SDI_2Doc* CTargetDemo_SDI_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTargetDemo_SDI_2Doc)));
	return (CTargetDemo_SDI_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTargetDemo_SDI_2View �޽��� ó����
