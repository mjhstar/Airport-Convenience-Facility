
// AirDoc.h : CAirDoc Ŭ������ �������̽�
//


#pragma once
#include "AirSet.h"
#include "alldatas.h"



class CAirDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CAirDoc();
	DECLARE_DYNCREATE(CAirDoc)

// Ư���Դϴ�.
public:
	CAirSet m_AirSet;
	Calldatas m_alldatas;

// �۾��Դϴ�.
public:


// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CAirDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
