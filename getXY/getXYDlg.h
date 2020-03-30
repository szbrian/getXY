// getXYDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CgetXYDlg �Ի���
class CgetXYDlg : public CDialog
{
// ����
public:
	CgetXYDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETXY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
