
// AirView.h : CAirView 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CAirSet;
class Calldatas;


class CAirView : public CRecordView
{
protected: // serialization에서만 만들어집니다.
	CAirView();
	DECLARE_DYNCREATE(CAirView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_AIR_FORM };
#endif
	CAirSet* m_pSet;

// 특성입니다.
public:
	CAirDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CAirView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	void AddColumn();
	CListCtrl m_ListAir;
	CButton m_ButtonTotal;

	void AddAllRecord();
	void GetTotalRecordCount();

	int current_pos;
	int record_count;
	
	afx_msg void OnBnClickedButtonTotal();

	CComboBox m_ComboAirlines;
	CComboBox m_ComboAirport;
	
	CString m_Combo1;
	CString m_Combo2;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();

	afx_msg void OnBnClickedButtonFacility();
};

#ifndef _DEBUG  // AirView.cpp의 디버그 버전
inline CAirDoc* CAirView::GetDocument() const
   { return reinterpret_cast<CAirDoc*>(m_pDocument); }
#endif

