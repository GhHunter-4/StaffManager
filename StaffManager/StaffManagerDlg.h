
// StaffManagerDlg.h : ͷ�ļ�
//

#pragma once
#include "AddDlg.h"
#include "RegisterFaceDlg.h"
#include "RecognitionDlg.h"
#include "InfoManageDlg.h"
#include "DataStatisticsDlg.h"
// CStaffManagerDlg �Ի���
class CStaffManagerDlg : public CDialogEx
{
private:
	CRegisterFaceDlg* m_RegisterDlg;
	CRecognitionDlg* m_RecognizeDlg;
	CInfoManageDlg* m_InfoDlg;
	CDataStatisticsDlg* m_DataDlg;
	int m_nSel;
	CRect rect,rt;
	CWnd* ps[4];
// ����
public:
	CStaffManagerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CStaffManagerDlg();
// �Ի�������
	enum { IDD = IDD_STAFFMANAGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInputFaceButton();
	void SelectPage();
	afx_msg void OnBnClickedRecognizeButton();
	afx_msg void OnBnClickedDataButton();
	afx_msg void OnBnClickedInfoButton();
};
