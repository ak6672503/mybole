﻿// CTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "Mybole.h"
#include "CTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	
{

}

CTestDlg::~CTestDlg()
{
	
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_num1);
	//  DDV_MinMaxInt(pDX, m_num1, 0, 22);
	
	//  DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADD, &CTestDlg::OnBnClickedBtnAdd)
	ON_STN_CLICKED(IDC_NUMBER1, &CTestDlg::OnStnClickedNumber1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序


void CTestDlg::OnBnClickedBtnAdd()
{
	/*
	if(m_bIsCreated==FALSE){
	m_btn.Create(L"New", BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	m_bIsCreated = TRUE;
	}
	else {
		m_btn.DestroyWindow();
		m_bIsCreated = FALSE;
	}*/
	/*通过控件ID 获取到控件里边的文本，转为int计算 然后转为文本 输出
	int num1, num2, num3;
	TCHAR ch1[10], ch2[10], ch3[10];
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 10);
	num1 = _tstoi(ch1);
	num2 = _tstoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);
	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);*/

	/*通过函数直接用控件ID获取到文本，不用多一步了
	int num1, num2, num3;
	TCHAR ch1[10], ch2[10], ch3[10];
	GetDlgItemText(IDC_EDIT1, ch1, 10);
	GetDlgItemText(IDC_EDIT2, ch2, 10);

	num1 = _tstoi(ch1);
	num2 = _tstoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);
	SetDlgItemText(IDC_EDIT3, ch3);*/

	/*这个方式更简单
	int num1, num2, num3;
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);*/

	/*直接用类向导关联控件
	UpdateData();
	m_num3 = m_num1 + m_num2;
	UpdateData(FALSE);*/

	/*类向导添加控件的方式关联窗口*/
	int num1, num2, num3;
	TCHAR ch1[10], ch2[10], ch3[10];
	m_edit1.GetWindowText(ch1, 10);
	m_edit2.GetWindowText(ch2, 10);

	num1 = _tstoi(ch1);
	num2 = _tstoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);
	m_edit3.SetWindowText(ch3);

}


void CTestDlg::OnStnClickedNumber1()
{
	CString str;
	if (GetDlgItem(IDC_NUMBER1)->GetWindowText(str), str == L"Number1:") {
		GetDlgItem(IDC_NUMBER1)->SetWindowText(L"数值1：");
	
	}
	else {
		GetDlgItem(IDC_NUMBER1)->SetWindowText(L"Number1:");
	}


}


void CTestDlg::OnBnClickedButton2()
{
	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == "收缩《《")
	{

		SetDlgItemText(IDC_BUTTON2, L"扩展》》");

	}
	else {
		SetDlgItemText(IDC_BUTTON2, L"收缩《《");
	}

	static CRect rectLarge;
	static CRect rectSmall;

	if (rectLarge.IsRectNull())
	{
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);

		rectSmall.left = rectLarge.left;
		rectSmall.top = rectLarge.top;
		rectSmall.right = rectLarge.right;
		rectSmall.bottom = rectSeparator.bottom;


	}if (str == "收缩《《") {
		SetWindowPos(NULL, 0, 0, rectSmall.Width(), rectSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	else {
		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), SWP_NOMOVE | SWP_NOZORDER);

	}
}


void CTestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();
	
	//GetFocus()->GetNextWindow()->SetFocus();

	GetNextDlgTabItem(GetFocus())->SetFocus();
//	CDialog::OnOK();
}

WNDPROC prevProc;
LRESULT CALLBACK NewEditProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
) {
	if (uMsg == WM_CHAR && wParam == 0x0d) {
		//::SetFocus(GetNextWindow(hwnd, GW_HWNDNEXT));
		//::SetFocus(GetWindow(hwnd, GW_HWNDNEXT));
		//SetFocus(::GetNextDlgTabItem(::GetParent(hwnd), hwnd, FALSE));
		
		
		return 1;

	}
	else {
		return prevProc(hwnd, uMsg, wParam, lParam);
	}
}

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	//prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (LONG)NewEditProc);
	prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (LONG)NewEditProc);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
