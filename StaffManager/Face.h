#pragma once
class Face
{
public:
	Face(void);
	~Face(void);
	// ����
	CString staff_no;
	// ����������Դ�ļ�·��
	CString face_path;
	int face_id;
	void SetStaffNo(CString staff_no);
	void SetFacePath(CString face_path);
	void SetFaceId(int face_id);

	CString GetStaffNo();
	CString GetFacePath();
	int GetFaceId();
};

