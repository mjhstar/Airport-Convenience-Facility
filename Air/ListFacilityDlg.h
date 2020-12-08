#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// ListFacilityDlg ��ȭ �����Դϴ�.

class ListFacilityDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListFacilityDlg)

public:
	ListFacilityDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ListFacilityDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FACILITY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
