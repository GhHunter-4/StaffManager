#pragma once
#include "Staff.h"

// CRegisterFaceDlg �Ի���

class CRegisterFaceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterFaceDlg)

public:
	CListCtrl* m_list;
	CRegisterFaceDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterFaceDlg();

// �Ի�������
	enum { IDD = IDD_INPUT_FACE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddButton();
	virtual BOOL OnInitDialog();
	void readStaff(CListCtrl* pList);
};
