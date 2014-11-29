// DataStatisticsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StaffManager.h"
#include "DataStatisticsDlg.h"
#include "afxdialogex.h"


// CDataStatisticsDlg �Ի���

IMPLEMENT_DYNAMIC(CDataStatisticsDlg, CDialogEx)

CDataStatisticsDlg::CDataStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDataStatisticsDlg::IDD, pParent)
{

}

CDataStatisticsDlg::~CDataStatisticsDlg()
{
}

void CDataStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataStatisticsDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CDataStatisticsDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CDataStatisticsDlg::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDataStatisticsDlg ��Ϣ�������


void CDataStatisticsDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}


void CDataStatisticsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


BOOL CDataStatisticsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//���ô��ڱ���
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BG_BITMAP);
	m_dc.CreateCompatibleDC(NULL);
	m_dc.SelectObject(&bmp);
	BITMAP bm;
	bmp.GetBitmap(&bm);
	m_size.cx = bm.bmWidth;
	m_size.cy = bm.bmHeight;

	m_list = (CListCtrl*)GetDlgItem(IDC_LOG_LIST);
	m_list->InsertColumn(0,"����",0,100);
	m_list->InsertColumn(1,"����",0,80);
	m_list->InsertColumn(2,"����״̬",0,125);
	m_list->InsertColumn(3,"����ʱ��",0,175);

	ReadAllLogs(m_list);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDataStatisticsDlg::ReadAllLogs(CListCtrl* pList)
{
	MYSQL mysql;
	MYSQL_RES *result = NULL;
	Log m_log;
	SQLUtils* sqlutils = new SQLUtils("localhost","root","root","work_database",3306);

	mysql_init(&mysql);

	string serverName = sqlutils->getServerName();
	string userName = sqlutils->getUserName();
	string password = sqlutils->getPassword();
	string databaseName = sqlutils->getDatabaseName();
	int port = sqlutils->getPort();
	if (mysql_real_connect(&mysql,serverName.c_str(),userName.c_str(),password.c_str(),databaseName.c_str(),port,NULL,0))
	{
		mysql_set_character_set(&mysql, "gbk");
		string sql = "select staff_no, staff_name, result, time from t_log order by time desc";
		mysql_query(&mysql,sql.c_str());
		result = mysql_store_result(&mysql);
		int fieldcount = mysql_num_fields(result);
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		int j = 0;
		while(NULL != row)
		{
			for(int i=0; i<fieldcount; i++)
			{
				switch(i){
				case 0:
					m_log.SetStaffNo(row[i]);
					break;
				case 1:
					m_log.SetStaffName(row[i]);
					break;
				case 2:
					m_log.SetResult(row[i]);
					break;
				case 3:
					m_log.SetTime(row[i]);
					break;
				}
			}
			pList->InsertItem(j,m_log.GetStaffNo());
			pList->SetItemText(j,1,m_log.GetStaffName());
			pList->SetItemText(j,2,m_log.GetResult());
			pList->SetItemText(j,3,m_log.GetTime());
			++j;
			row = mysql_fetch_row(result);
		}
		mysql_close(&mysql);

	}
	else{
		AfxMessageBox("ϵͳ����");
	}
}


void CDataStatisticsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	dc.BitBlt(0,0,m_size.cx,m_size.cy,&m_dc,0,0,SRCCOPY);
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
