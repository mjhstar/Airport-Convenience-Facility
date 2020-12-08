// ListFacilityDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Air.h"
#include "ListFacilityDlg.h"
#include "afxdialogex.h"


// ListFacilityDlg 대화 상자입니다.

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


// ListFacilityDlg 메시지 처리기입니다.


void ListFacilityDlg::AddColumn()
{
	CRect rect;
	m_ListFacility.GetClientRect(&rect);

	m_ListFacility.InsertColumn(0, _T("분류"), LVCFMT_RIGHT, 60);
	m_ListFacility.InsertColumn(1, _T("시설이름"), LVCFMT_LEFT, 100);
	m_ListFacility.InsertColumn(2, _T("층"), LVCFMT_LEFT, 50);
	m_ListFacility.InsertColumn(3, _T("터미널"), LVCFMT_LEFT, 100);
	m_ListFacility.InsertColumn(4, _T("위치"), LVCFMT_LEFT, 150);
	m_ListFacility.InsertColumn(5, _T("영업시작"), LVCFMT_LEFT, 60);
	m_ListFacility.InsertColumn(6, _T("영업마감"), LVCFMT_LEFT, 60);
	m_ListFacility.InsertColumn(7, _T("전화번호"), LVCFMT_LEFT, 150);

}


void ListFacilityDlg::AddAllRecord()
{
	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from alldatas "));


	//레코드 출력
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

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	AddColumn();
	AddAllRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void ListFacilityDlg::OnBnClickedButtonFinance()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from finance "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from internet "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from information "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from rest "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from medical "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from post "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from car "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from dutyfree "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from etc "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CDatabase db;
	db.OpenEx(_T("DSN=airDSN"), 0);

	//레코드셋 객체 생성
	CRecordset rs(&db);
	rs.Open(CRecordset::snapshot, _T("select *from alldatas "));

	m_ListFacility.DeleteAllItems();

	//레코드 출력
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
