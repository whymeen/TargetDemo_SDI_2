
// TargetDemo_SDI_2View.h : CTargetDemo_SDI_2View Ŭ������ �������̽�
//

#include "GridCtrl.h"

#pragma once


class CTargetDemo_SDI_2View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CTargetDemo_SDI_2View();
	DECLARE_DYNCREATE(CTargetDemo_SDI_2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TARGETDEMO_SDI_2_FORM };
#endif

// Ư���Դϴ�.
public:
	CTargetDemo_SDI_2Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	CGridCtrl m_Grid;

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CTargetDemo_SDI_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TargetDemo_SDI_2View.cpp�� ����� ����
inline CTargetDemo_SDI_2Doc* CTargetDemo_SDI_2View::GetDocument() const
   { return reinterpret_cast<CTargetDemo_SDI_2Doc*>(m_pDocument); }
#endif

