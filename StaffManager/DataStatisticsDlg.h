#pragma once
#include "Log.h"

// CDataStatisticsDlg �Ի���

class CDataStatisticsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDataStatisticsDlg)

public:
	CListCtrl* m_list;
	CDC m_dc;
	CSize m_size;
	CDataStatisticsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDataStatisticsDlg();

// �Ի�������
	enum { IDD = IDD_DATAMANAGEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	void ReadAllLogs(CListCtrl* pList);
	afx_msg void OnPaint();
};
