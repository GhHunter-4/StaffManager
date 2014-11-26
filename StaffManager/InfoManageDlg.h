#pragma once
#include "AddDlg.h"


// CInfoManageDlg �Ի���

class CInfoManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoManageDlg)

public:
	CListCtrl* m_list;
	CDC m_dc;
	CSize m_size;
	CInfoManageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInfoManageDlg();

// �Ի�������
	enum { IDD = IDD_INFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedAdd();

public:
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedDelete();
	virtual BOOL OnInitDialog();
	void SetListItemName();
	void ReadStaff(CListCtrl* pList);
	afx_msg void OnPaint();
};
