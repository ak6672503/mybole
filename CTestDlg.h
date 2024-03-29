﻿#pragma once
#include "Resource.h"

// CTestDlg 对话框

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
private:
	CButton m_btn;
	BOOL m_bIsCreated;
public:
	afx_msg void OnStnClickedNumber1();
	void OnBnClickedButton2();
private:

	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
