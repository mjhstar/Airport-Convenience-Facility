
// AirView.h : CAirView Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CAirSet;
class Calldatas;


class CAirView : public CRecordView
{
protected: // serialization������ ��������ϴ�.
	CAirView();
	DECLARE_DYNCREATE(CAirView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_AIR_FORM };
#endif
	CAirSet* m_pSet;

// Ư���Դϴ�.
public:
	CAirDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CAirView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // AirView.cpp�� ����� ����
inline CAirDoc* CAirView::GetDocument() const
   { return reinterpret_cast<CAirDoc*>(m_pDocument); }
#endif

