
// AirSet.cpp : CAirSet 클래스의 구현
//

#include "stdafx.h"
#include "Air.h"
#include "AirSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAirSet 구현

// 코드 생성 위치 2018년 12월 14일 금요일, 오전 1:12

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
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[airlines]"), m_airlines);
	RFX_Text(pFX, _T("[airport]"), m_airport);
	RFX_Text(pFX, _T("[airportcode]"), m_airportcode);
	RFX_Text(pFX, _T("[datetime]"), m_datetime);
	RFX_Text(pFX, _T("[flightId]"), m_flightId);

}
/////////////////////////////////////////////////////////////////////////////
// CAirSet 진단

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

