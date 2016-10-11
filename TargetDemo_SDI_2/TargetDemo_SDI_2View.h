
// TargetDemo_SDI_2View.h : CTargetDemo_SDI_2View 클래스의 인터페이스
//

#include "GridCtrl.h"

#pragma once


class CTargetDemo_SDI_2View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CTargetDemo_SDI_2View();
	DECLARE_DYNCREATE(CTargetDemo_SDI_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TARGETDEMO_SDI_2_FORM };
#endif

// 특성입니다.
public:
	CTargetDemo_SDI_2Doc* GetDocument() const;

// 작업입니다.
public:
	CGridCtrl m_Grid;

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CTargetDemo_SDI_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TargetDemo_SDI_2View.cpp의 디버그 버전
inline CTargetDemo_SDI_2Doc* CTargetDemo_SDI_2View::GetDocument() const
   { return reinterpret_cast<CTargetDemo_SDI_2Doc*>(m_pDocument); }
#endif

