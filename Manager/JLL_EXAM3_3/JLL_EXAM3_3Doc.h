
// JLL_EXAM3_3Doc.h : CJLL_EXAM3_3Doc 类的接口
//


#pragma once

#include "Product.h"
using namespace std;

class CJLL_EXAM3_3Doc : public CDocument
{
protected: // 仅从序列化创建
	CJLL_EXAM3_3Doc();
	DECLARE_DYNCREATE(CJLL_EXAM3_3Doc)

// 特性
public:

// 操作
public:
	vector<CProduct*>product; //设置动态数组;
	vector<CProduct*> GetProduct(); //获取数组;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CJLL_EXAM3_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	
public:
	void AddPro(CProduct * pro);
	void DeletePro(int index);
	void ChangePro(int index, CString name , int shape , COLORREF color, int m1 , int m2 , int m3 , int m4 , int m5);
};
