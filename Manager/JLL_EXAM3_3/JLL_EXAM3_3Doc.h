
// JLL_EXAM3_3Doc.h : CJLL_EXAM3_3Doc ��Ľӿ�
//


#pragma once

#include "Product.h"
using namespace std;

class CJLL_EXAM3_3Doc : public CDocument
{
protected: // �������л�����
	CJLL_EXAM3_3Doc();
	DECLARE_DYNCREATE(CJLL_EXAM3_3Doc)

// ����
public:

// ����
public:
	vector<CProduct*>product; //���ö�̬����;
	vector<CProduct*> GetProduct(); //��ȡ����;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CJLL_EXAM3_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	
public:
	void AddPro(CProduct * pro);
	void DeletePro(int index);
	void ChangePro(int index, CString name , int shape , COLORREF color, int m1 , int m2 , int m3 , int m4 , int m5);
};
