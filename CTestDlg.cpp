// CTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "Mybole.h"
#include "CTestDlg.h"
#include "afxdialogex.h"


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

	int num1, num2, num3;
	TCHAR ch1[10], ch2[10], ch3[10];

	GetDlgItem(IDC_NUMBER1)->GetWindowText(ch1, 10);
	GetDlgItem(IDC_NUMBER2)->GetWindowText(ch1, 10);

	num1 = _tstoi(ch1);


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
