// CTestDlg.cpp: 实现文件
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
