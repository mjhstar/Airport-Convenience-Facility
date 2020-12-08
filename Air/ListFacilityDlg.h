#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// ListFacilityDlg 대화 상자입니다.

class ListFacilityDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListFacilityDlg)

public:
	ListFacilityDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ListFacilityDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FACILITY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListFacility;
	CButton m_ButtonFinance;
	CButton m_ButtonInternet;
	CButton m_ButtonInformation;
	CButton m_ButtonRest;
	CButton m_ButtonMedical;
	CButton m_ButtonPost;
	CButton m_ButtonCar;
	CButton m_ButtonDutyfree;
	CButton m_ButtonEtc;
	CButton m_ButtonTotal;
	void AddColumn();
	void AddAllRecord();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonFinance();
	afx_msg void OnBnClickedButtonInternet();
	afx_msg void OnBnClickedButtonInformation();
	afx_msg void OnBnClickedButtonRest();
	afx_msg void OnBnClickedButtonMedical();
	afx_msg void OnBnClickedButtonPost();
	afx_msg void OnBnClickedButtonCar();
	afx_msg void OnBnClickedButtonDutyfree();
	afx_msg void OnBnClickedButtonEtc();
	afx_msg void OnBnClickedButtonTotal();
};
