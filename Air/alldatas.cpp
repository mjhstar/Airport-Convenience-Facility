// alldatas.h : Calldatas Ŭ������ �����Դϴ�.



// Calldatas �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 14�� �ݿ���, ���� 9:13

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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// Calldatas ����

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


