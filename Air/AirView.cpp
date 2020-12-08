
// AirView.cpp : CAirView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Air.h"
#endif

#include "AirSet.h"
#include "AirDoc.h"
#include "AirView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAirView

IMPLEMENT_DYNCREATE(CAirView, CRecordView)

BEGIN_MESSAGE_MAP(CAirView, CRecordView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	

	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &CAirView::OnBnClickedButtonTotal)
	

	
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAirView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAirView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CAirView::OnCbnSelchangeCombo2)
	
	ON_BN_CLICKED(IDC_BUTTON_FACILITY, &CAirView::OnBnClickedButtonFacility)
END_MESSAGE_MAP()

// CAirView ����/�Ҹ�

CAirView::CAirView()
	: CRecordView(IDD_AIR_FORM)
	
	, m_Combo1(_T(""))
	, m_Combo2(_T(""))
{
	m_pSet = NULL;
	
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	current_pos = 1;
	record_count = 0;


}

CAirView::~CAirView()
{
}

void CAirView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.
	DDX_Control(pDX, IDC_LIST_AIR, m_ListAir);
	DDX_Control(pDX, IDC_BUTTON_TOTAL, m_ButtonTotal);
	DDX_Control(pDX, IDC_COMBO1, m_ComboAirlines);
	DDX_Control(pDX, IDC_COMBO2, m_ComboAirport);
	DDX_CBString(pDX, IDC_COMBO1, m_Combo1);
	DDX_CBString(pDX, IDC_COMBO2, m_Combo2);
}

BOOL CAirView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CRecordView::PreCreateWindow(cs);
}

void CAirView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_AirSet;
	CRecordView::OnInitialUpdate();
	AddColumn();
	AddAllRecord();
	GetTotalRecordCount();

	m_ListAir.SetExtendedStyle(m_ListAir.GetExtendedStyle() | LVS_EX_GRIDLINES);
	m_ListAir.SetExtendedStyle(m_ListAir.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	m_ComboAirlines.SetCurSel(0);
	m_ComboAirport.SetCurSel(0);

}


// CAirView �μ�

BOOL CAirView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CAirView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CAirView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CAirView ����

#ifdef _DEBUG
void CAirView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CAirView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CAirDoc* CAirView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAirDoc)));
	return (CAirDoc*)m_pDocument;
}
#endif //_DEBUG


// CAirView �����ͺ��̽� ����
CRecordset* CAirView::OnGetRecordset()
{
	return m_pSet;
	
}



// CAirView �޽��� ó����




//���ڵ� ���� ���
void CAirView::AddColumn()
{
	CRect rect;
	m_ListAir.GetClientRect(&rect);
	
	m_ListAir.InsertColumn(0, _T("�װ���"), LVCFMT_RIGHT, 200);
	m_ListAir.InsertColumn(1, _T("������"), LVCFMT_LEFT, rect.Width() - 600);
	m_ListAir.InsertColumn(2, _T("��߿����ð�"), LVCFMT_LEFT, 200);
	m_ListAir.InsertColumn(3, _T("ž���װ���"), LVCFMT_LEFT, 200);

	
}

#include "AirSet.h"
//�����ͺ��̽� ������ ����Ʈ ��Ʈ�ѿ� �߰�
void CAirView::AddAllRecord()
{

	m_pSet->Requery();
	int i = 0;
	m_ListAir.DeleteAllItems();
	CString strTemp;

	while (m_pSet->IsEOF() == FALSE) {
		m_ListAir.InsertItem(i, m_pSet->m_airlines, 0);
		m_ListAir.SetItemText(i, 1, m_pSet->m_airport);
		m_ListAir.SetItemText(i, 2, m_pSet->m_datetime);
		m_ListAir.SetItemText(i, 3, m_pSet->m_flightId);
		m_pSet->MoveNext();
		i++;
	}
}


void CAirView::GetTotalRecordCount(void)
{
	CRecordset cntSet(m_pSet->m_pDatabase);
	cntSet.Open(CRecordset::snapshot, _T("select count(*) from schedule")); // ��ü ���ڵ��� ������ ����
	CString strCount;
	cntSet.GetFieldValue((short)0, strCount);
	record_count = _wtoi((const wchar_t *)strCount);
	cntSet.Close();
}


void CAirView::OnBnClickedButtonTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AddAllRecord();
}



void CAirView::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strItem;
	int nIndex = m_ComboAirlines.GetCurSel();
	m_ComboAirlines.GetLBText(nIndex, strItem);

	if (m_pSet->m_airlines.IsEmpty() == false) {
		m_pSet->m_strFilter.Format(_T("airlines like '%%%s%%'"), strItem);
		int i = 0;
		m_pSet->Requery();
		m_pSet->m_strFilter.Empty();
		m_ListAir.DeleteAllItems();
		
		while (m_pSet->IsEOF() == FALSE) {
			m_ListAir.InsertItem(i, m_pSet->m_airlines, 0);
			m_ListAir.SetItemText(i, 1, m_pSet->m_airport);
			m_ListAir.SetItemText(i, 2, m_pSet->m_datetime);
			m_ListAir.SetItemText(i, 3, m_pSet->m_flightId);
			
			i++;

			current_pos = record_count = i;
			m_pSet->SetAbsolutePosition(current_pos);
		}
	}
}


void CAirView::OnCbnSelchangeCombo2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strItem;
	int nIndex = m_ComboAirport.GetCurSel();
	m_ComboAirport.GetLBText(nIndex, strItem);

	if (m_pSet->m_airport.IsEmpty() == false) {
		m_pSet->m_strFilter.Format(_T("airport like '%%%s%%'"), strItem);
		int i = 0;
		m_pSet->Requery();
		m_pSet->m_strFilter.Empty();
		m_ListAir.DeleteAllItems();

		while (m_pSet->IsEOF() == FALSE) {
			m_ListAir.InsertItem(i, m_pSet->m_airlines, 0);
			m_ListAir.SetItemText(i, 1, m_pSet->m_airport);
			m_ListAir.SetItemText(i, 2, m_pSet->m_datetime);
			m_ListAir.SetItemText(i, 3, m_pSet->m_flightId);

			i++;

			current_pos = record_count = i;
			m_pSet->SetAbsolutePosition(current_pos);
		}
	}
}



#include "ListFacilityDlg.h"

void CAirView::OnBnClickedButtonFacility()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ListFacilityDlg dlg;
	int res = dlg.DoModal();
}
