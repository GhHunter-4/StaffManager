// InfoManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StaffManager.h"
#include "InfoManageDlg.h"
#include "afxdialogex.h"


// CInfoManageDlg �Ի���

IMPLEMENT_DYNAMIC(CInfoManageDlg, CDialogEx)

CInfoManageDlg::CInfoManageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfoManageDlg::IDD, pParent)
{

}

CInfoManageDlg::~CInfoManageDlg()
{
}

void CInfoManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoManageDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CInfoManageDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ADD, &CInfoManageDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MODIFY, &CInfoManageDlg::OnBnClickedModify)
	ON_BN_CLICKED(IDC_DELETE, &CInfoManageDlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CInfoManageDlg ��Ϣ�������


void CInfoManageDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}


void CInfoManageDlg::OnBnClickedAdd()
{
	CAddDlg dlg;
	dlg.m_pInfoDlg = this;
	dlg.DoModal();
}


void CInfoManageDlg::OnBnClickedModify()
{
	m_list = (CListCtrl*)GetDlgItem(IDC_STAFF_LIST);

	POSITION pos = m_list->GetFirstSelectedItemPosition();
	int nSel = m_list->GetNextSelectedItem(pos);

	if(nSel<0)
	{
		AfxMessageBox("��ѡ��һ��Ա���ٽ����޸ģ�");
		return;
	}

	CString no, name, sex, duty, tel;
	no = m_list->GetItemText(nSel,0);
	name = m_list->GetItemText(nSel,1);
	sex = m_list->GetItemText(nSel,2);
	duty = m_list->GetItemText(nSel,3);
	tel = m_list->GetItemText(nSel,4);

	CAddDlg dlg;
	dlg.m_pInfoDlg = this;
	dlg.no = no;
	dlg.name = name;
	dlg.sex = sex;
	dlg.duty = duty;
	dlg.tel = tel;
	dlg.modifyFlag = TRUE;
	dlg.nSel = nSel;
	dlg.DoModal();
}


void CInfoManageDlg::OnBnClickedDelete()
{
	m_list = (CListCtrl*)GetDlgItem(IDC_STAFF_LIST);

	POSITION pos = m_list->GetFirstSelectedItemPosition();
	int nSel = m_list->GetNextSelectedItem(pos);

	if(nSel<0)
	{
		AfxMessageBox("��ѡ��һ��Ա���ٽ���ɾ����");
		return;
	}

	CString staff_no = m_list->GetItemText(nSel,0);

	MYSQL mysql;
	MYSQL_RES *result = NULL;
	SQLUtils* sqlutils = new SQLUtils("localhost","root","root","work_database",3306);

	mysql_init(&mysql);

	string serverName = sqlutils->getServerName();
	string userName = sqlutils->getUserName();
	string password = sqlutils->getPassword();
	string databaseName = sqlutils->getDatabaseName();
	int port = sqlutils->getPort();
	if (mysql_real_connect(&mysql,serverName.c_str(),userName.c_str(),password.c_str(),databaseName.c_str(),port,NULL,0))
	{
		string sql = "delete from t_staff where staff_no=";
		sql.append(1,'\'').append(staff_no).append(1,'\'');
		mysql_query(&mysql,sql.c_str());
		
		//ɾ��Ŀ¼
		string str = "select face_path from t_face where staff_no = ";
		str.append(1,'\'').append(staff_no).append(1,'\'');
		mysql_query(&mysql,str.c_str());
		result = mysql_store_result(&mysql);
		//  int fieldcount = mysql_num_fields(result);
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		Utils utils;
		if(row==NULL)
		{
			//AfxMessageBox("���ȵǼ�");  //���Ϊ��ʲôҲ����
		}else{
			utils.DeletePath(row[0]);
		}
		if(result!=NULL) 
			mysql_free_result(result);//�ͷŽ����Դ 

		//ɾ�����ݱ�����
		string m_SQL = "delete from t_face where staff_no=";
		m_SQL.append(1,'\'').append(staff_no).append(1,'\'');
		mysql_query(&mysql,m_SQL.c_str());

		mysql_close(&mysql);
		m_list->DeleteItem(nSel);
		return;
	}
	else{
		MessageBox("ϵͳ����");
	}
}


BOOL CInfoManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetListItemName();
	ReadStaff(m_list);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInfoManageDlg::SetListItemName()
{
	m_list = (CListCtrl*)GetDlgItem(IDC_STAFF_LIST);
	m_list->InsertColumn(0,"����",0,80);
	m_list->InsertColumn(1,"����",0,80);
	m_list->InsertColumn(2,"�Ա�",0,80);
	m_list->InsertColumn(3,"ְ��",0,100);
	m_list->InsertColumn(4,"�绰",0,150);
}


void CInfoManageDlg::ReadStaff(CListCtrl* pList)
{
	MYSQL mysql;
	MYSQL_RES *result = NULL;
	Staff staff;
	SQLUtils* sqlutils = new SQLUtils("localhost","root","root","work_database",3306);

	mysql_init(&mysql);

	string serverName = sqlutils->getServerName();
	string userName = sqlutils->getUserName();
	string password = sqlutils->getPassword();
	string databaseName = sqlutils->getDatabaseName();
	int port = sqlutils->getPort();
	if (mysql_real_connect(&mysql,serverName.c_str(),userName.c_str(),password.c_str(),databaseName.c_str(),port,NULL,0))
	{
		string sql = "select staff_no, staff_name, staff_sex, staff_duty, staff_tel from t_staff";
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
					staff.setNo(row[i]);
					break;
				case 1:
					staff.setName(row[i]);
					break;
				case 2:
					staff.setSex(row[i]);
					break;
				case 3:
					staff.setDuty(row[i]);
					break;
				case 4:
					staff.setTel(row[i]);
					break;
				}
			}
			pList->InsertItem(j,staff.getNo());
			pList->SetItemText(j,1,staff.getName());
			pList->SetItemText(j,2,staff.getSex());
			pList->SetItemText(j,3,staff.getDuty());
			pList->SetItemText(j,4,staff.getTel());
			++j;
			row = mysql_fetch_row(result);
		}
		mysql_close(&mysql);

	}
	else{
		MessageBox("ϵͳ����");
	}
}
