
// AirView.cpp : CAirView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	

	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &CAirView::OnBnClickedButtonTotal)
	

	
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAirView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAirView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CAirView::OnCbnSelchangeCombo2)
	
	ON_BN_CLICKED(IDC_BUTTON_FACILITY, &CAirView::OnBnClickedButtonFacility)
END_MESSAGE_MAP()

// CAirView 생성/소멸

CAirView::CAirView()
	: CRecordView(IDD_AIR_FORM)
	
	, m_Combo1(_T(""))
	, m_Combo2(_T(""))
{
	m_pSet = NULL;
	
	// TODO: 여기에 생성 코드를 추가합니다.
	current_pos = 1;
	record_count = 0;


}

CAirView::~CAirView()
{
}

void CAirView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 컨트롤을 데이터베이스 필드에 '연결'하기 위해 여기에 DDX_Field* 함수를 삽입할 수 있습니다. 예:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 자세한 내용은 MSDN 및 ODBC 샘플을 참조하십시오.
	DDX_Control(pDX, IDC_LIST_AIR, m_ListAir);
	DDX_Control(pDX, IDC_BUTTON_TOTAL, m_ButtonTotal);
	DDX_Control(pDX, IDC_COMBO1, m_ComboAirlines);
	DDX_Control(pDX, IDC_COMBO2, m_ComboAirport);
	DDX_CBString(pDX, IDC_COMBO1, m_Combo1);
	DDX_CBString(pDX, IDC_COMBO2, m_Combo2);
}

BOOL CAirView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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


// CAirView 인쇄

BOOL CAirView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAirView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAirView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CAirView 진단

#ifdef _DEBUG
void CAirView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CAirView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CAirDoc* CAirView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAirDoc)));
	return (CAirDoc*)m_pDocument;
}
#endif //_DEBUG


// CAirView 데이터베이스 지원
CRecordset* CAirView::OnGetRecordset()
{
	return m_pSet;
	
}



// CAirView 메시지 처리기




//레코드 내용 출력
void CAirView::AddColumn()
{
	CRect rect;
	m_ListAir.GetClientRect(&rect);
	
	m_ListAir.InsertColumn(0, _T("항공사"), LVCFMT_RIGHT, 200);
	m_ListAir.InsertColumn(1, _T("도착지"), LVCFMT_LEFT, rect.Width() - 600);
	m_ListAir.InsertColumn(2, _T("출발예정시간"), LVCFMT_LEFT, 200);
	m_ListAir.InsertColumn(3, _T("탑승항공기"), LVCFMT_LEFT, 200);

	
}

#include "AirSet.h"
//데이터베이스 데이터 리스트 컨트롤에 추가
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
	cntSet.Open(CRecordset::snapshot, _T("select count(*) from schedule")); // 전체 레코드의 개수를 구함
	CString strCount;
	cntSet.GetFieldValue((short)0, strCount);
	record_count = _wtoi((const wchar_t *)strCount);
	cntSet.Close();
}


void CAirView::OnBnClickedButtonTotal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AddAllRecord();
}



void CAirView::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ListFacilityDlg dlg;
	int res = dlg.DoModal();
}
