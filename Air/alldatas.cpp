// alldatas.h : Calldatas 클래스의 구현입니다.



// Calldatas 구현입니다.

// 코드 생성 위치 2018년 12월 14일 금요일, 오후 9:13

#include "stdafx.h"
#include "alldatas.h"
IMPLEMENT_DYNAMIC(Calldatas, CRecordset)

Calldatas::Calldatas(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_facID = 0;
	m_finID = 0;
	m_facKind = "";
	m_facName = "";
	m_floor = "";
	m_terminal = "";
	m_location = "";
	m_OPhours = "";
	m_CLhours = "";
	m_tel = "";
	m_nFields = 10;
	m_nDefaultType = snapshot;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString Calldatas::GetDefaultConnect()
{
	return _T("DSN=airDSN;UID=root;PWD=hyunji99;DATABASE=air;PORT=3306;CHARSET=euckr");
}

CString Calldatas::GetDefaultSQL()
{
	return _T("[alldatas]");
}

void Calldatas::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[facID]"), m_facID);
	RFX_Long(pFX, _T("[finID]"), m_finID);
	RFX_Text(pFX, _T("[facKind]"), m_facKind);
	RFX_Text(pFX, _T("[facName]"), m_facName);
	RFX_Text(pFX, _T("[floor]"), m_floor);
	RFX_Text(pFX, _T("[terminal]"), m_terminal);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[OPhours]"), m_OPhours);
	RFX_Text(pFX, _T("[CLhours]"), m_CLhours);
	RFX_Text(pFX, _T("[tel]"), m_tel);

}
/////////////////////////////////////////////////////////////////////////////
// Calldatas 진단

#ifdef _DEBUG
void Calldatas::AssertValid() const
{
	CRecordset::AssertValid();
}

void Calldatas::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


