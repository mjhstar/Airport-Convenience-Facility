// ListFacilityDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Air.h"
#include "ListFacilityDlg.h"
#include "afxdialogex.h"


// ListFacilityDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(ListFacilityDlg, CDialogEx)

ListFacilityDlg::ListFacilityDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FACILITY, pParent)
{

}

ListFacilityDlg::~ListFacilityDlg()
{
}

void ListFacilityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FACILITY, m_ListFacility);
	DDX_Control(pDX, IDC_BUTTON_FINANCE, m_ButtonFinance);
	DDX_Control(pDX, IDC_BUTTON_INTERNET, m_ButtonInternet);
	DDX_Control(pDX, IDC_BUTTON_INFORMATION, m_ButtonInformation);
	DDX_Control(pDX, IDC_BUTTON_REST, m_ButtonRest);
	DDX_Control(pDX, IDC_BUTTON_MEDICAL, m_ButtonMedical);
	DDX_Control(pDX, IDC_BUTTON_POST, m_ButtonPost);
	DDX_Control(pDX, IDC_BUTTON_CAR, m_ButtonCar);
	DDX_Control(pDX, IDC_BUTTON_DUTYFREE, m_ButtonDutyfree);
	DDX_Control(pDX, IDC_BUTTON_ETC, m_ButtonEtc);
	DDX_Control(pDX, IDC_BUTTON_TOTAL, m_ButtonTotal);
}


BEGIN_MESSAGE_MAP(ListFacilityDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FINANCE, &ListFacilityDlg::OnBnClickedButtonFinance)
	ON_BN_CLICKED(IDC_BUTTON_INTERNET, &ListFacilityDlg::OnBnClickedButtonInternet)
	ON_BN_CLICKED(IDC_BUTTON_INFORMATION, &ListFacilityDlg::OnBnClickedButtonInformation)
	ON_BN_CLICKED(IDC_BUTTON_REST, &ListFacilityDlg::OnBnClickedButtonRest)
	ON_BN_CLICKED(IDC_BUTTON_MEDICAL, &ListFacilityDlg::OnBnClickedButtonMedical)
	ON_BN_CLICKED(IDC_BUTTON_POST, &ListFacilityDlg::OnBnClickedButtonPost)
	ON_BN_CLICKED(IDC_BUTTON_CAR, &ListFacilityDlg::OnBnClickedButtonCar)
	ON_BN_CLICKED(IDC_BUTTON_DUTYFREE, &ListFacilityDlg::OnBnClickedButtonDutyfree)
	ON_BN_CLICKED(IDC_BUTTON_ETC, &ListFacilityDlg::OnBnClickedButtonEtc)
	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &ListFacilityDlg::OnBnClickedButtonTotal)
END_MESSAGE_MAP()


// ListFacilityDlg �޽��� ó�����Դϴ�.


void ListFacilityDlg::AddColumn()
{
	CRect rect;
	m_ListFacility.GetClientRect(&rect);

	m_ListFacility.InsertColumn(0, _T("�з�"), LVCFMT_RIGHT, 60);
	m_ListFacility.InsertColumn(1, _T("�ü��̸�"), LVCFMT_LEFT, 100);
	m_ListFacility.InsertColumn(2, _T("��"), LVCFMT_LEFT, 50);
	m_ListFacility.InsertColumn(3, _T("�͹̳�"), LVCFMT_LEFT, 100);
	m_ListFacility.InsertColumn(4, _T("��ġ"), LVCFMT_LEFT, 150);
	m_ListFacility.InsertColumn(5, _T("��������"), LVCFMT_LEFT, 60);
	m_ListFacility.InsertColumn(6, _T("��������"), LVCFMT_LEFT, 60);
	m_ListFacility.InsertColumn(7, _T("��ȭ��ȣ"), LVCFMT_LEFT, 150);

}


void ListFacilityDlg::AddAllRecord()
{
	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from alldatas "));


	//���ڵ� ���
	CString str;
	int i = 0;
	while (!rs.IsEOF()) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;

}


BOOL ListFacilityDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	AddColumn();
	AddAllRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void ListFacilityDlg::OnBnClickedButtonFinance()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from finance "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF()==FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonInternet()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from internet "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonInformation()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from information "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonRest()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from rest "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonMedical()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from medical "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonPost()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from post "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonCar()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from car "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonDutyfree()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from dutyfree "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonEtc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from etc "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;
}


void ListFacilityDlg::OnBnClickedButtonTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//���ڵ�� ��ü ����
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from alldatas "));

	m_ListFacility.DeleteAllItems();

	//���ڵ� ���
	CString str;
	int i = 0;
	while (rs.IsEOF() == FALSE) {
		rs.GetFieldValue(short(2), str);
		m_ListFacility.InsertItem(i, str, 2);
		rs.GetFieldValue(short(3), str);
		m_ListFacility.SetItemText(i, 1, str);
		rs.GetFieldValue(short(4), str);
		m_ListFacility.SetItemText(i, 2, str);
		rs.GetFieldValue(short(5), str);
		m_ListFacility.SetItemText(i, 3, str);
		rs.GetFieldValue(short(6), str);
		m_ListFacility.SetItemText(i, 4, str);
		rs.GetFieldValue(short(7), str);
		m_ListFacility.SetItemText(i, 5, str);
		rs.GetFieldValue(short(8), str);
		m_ListFacility.SetItemText(i, 6, str);
		rs.GetFieldValue(short(9), str);
		m_ListFacility.SetItemText(i, 7, str);


		rs.MoveNext();
		i++;
	}
	rs.Close();
	db.Close();

	return;

	
}
