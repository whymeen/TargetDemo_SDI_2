
// TargetDemo_SDI_2.h : TargetDemo_SDI_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTargetDemo_SDI_2App:
// �� Ŭ������ ������ ���ؼ��� TargetDemo_SDI_2.cpp�� �����Ͻʽÿ�.
//

class CTargetDemo_SDI_2App : public CWinApp
{
public:
	CTargetDemo_SDI_2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTargetDemo_SDI_2App theApp;
