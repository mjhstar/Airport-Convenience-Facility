// alldatas.h : Calldatas�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 14�� �ݿ���, ���� 9:13

class Calldatas : public CRecordset
{
public:
	Calldatas(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Calldatas)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_facID;
	long	m_finID;
	CString	m_facKind;
	CString	m_facName;
	CString	m_floor;
	CString	m_terminal;
	CString	m_location;
	CString	m_OPhours;
	CString	m_CLhours;
	CString	m_tel;

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


