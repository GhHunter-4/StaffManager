#pragma once


// CDataStatisticsDlg �Ի���

class CDataStatisticsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDataStatisticsDlg)

public:
	CDataStatisticsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDataStatisticsDlg();

// �Ի�������
	enum { IDD = IDD_DATAMANAGEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
