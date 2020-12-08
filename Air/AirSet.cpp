
// AirSet.cpp : CAirSet Ŭ������ ����
//

#include "stdafx.h"
#include "Air.h"
#include "AirSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAirSet ����

// �ڵ� ���� ��ġ 2018�� 12�� 14�� �ݿ���, ���� 1:12

IMPLEMENT_DYNAMIC(CAirSet, CRecordset)

CAirSet::CAirSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_airlines = "";
	m_airport = "";
	m_airportcode = "";
	m_datetime = "";
	m_flightId = "";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CAirSet::GetDefaultConnect()
{
	return _T("DSN=airDSN;UID=root;PWD=hyunji99;DATABASE=air;PORT=3306;CHARSET=euckr");
}

CString CAirSet::GetDefaultSQL()
{
	return _T("[schedule]");
}

void CAirSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[airlines]"), m_airlines);
	RFX_Text(pFX, _T("[airport]"), m_airport);
	RFX_Text(pFX, _T("[airportcode]"), m_airportcode);
	RFX_Text(pFX, _T("[datetime]"), m_datetime);
	RFX_Text(pFX, _T("[flightId]"), m_flightId);

}
/////////////////////////////////////////////////////////////////////////////
// CAirSet ����

#ifdef _DEBUG
void CAirSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAirSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

