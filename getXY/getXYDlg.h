// getXYDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CgetXYDlg 对话框
class CgetXYDlg : public CDialog
{
// 构造
public:
	CgetXYDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GETXY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnExit();
	CString m_strPrice_1;
	CString m_strPrice_2;
	CString m_strSum;
	CListBox m_ctlList;
	afx_msg void OnBnClickedCancel();

public:
	void CgetXYDlg::getXY( float fPrice_1, float fPrice_2, float fSum, float fAllowErrorPrice );
	CString m_strAllowErrorPrice;
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedFromFile();
	bool m_bFromFile;
};
