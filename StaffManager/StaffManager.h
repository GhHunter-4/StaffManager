
// StaffManager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "LoginDlg.h"

// CStaffManagerApp:
// �йش����ʵ�֣������ StaffManager.cpp
//

class CStaffManagerApp : public CWinApp
{
public:
	CStaffManagerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStaffManagerApp theApp;