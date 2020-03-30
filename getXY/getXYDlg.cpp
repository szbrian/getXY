// getXYDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "getXY.h"
#include "getXYDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CgetXYDlg �Ի���




CgetXYDlg::CgetXYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CgetXYDlg::IDD, pParent)
	, m_strPrice_1(_T("77.26"))
	, m_strPrice_2(_T("80"))
	, m_strSum(_T(""))
	, m_strAllowErrorPrice(_T("0.5"))
	, m_bFromFile(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgetXYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PRICE_1, m_strPrice_1);
	DDV_MaxChars(pDX, m_strPrice_1, 5);
	DDX_Text(pDX, IDC_PRICE_2, m_strPrice_2);
	DDV_MaxChars(pDX, m_strPrice_2, 5);
	DDX_Text(pDX, IDC_SUM, m_strSum);
	DDV_MaxChars(pDX, m_strSum, 12);
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_ALLOW_ERR, m_strAllowErrorPrice);
	DDV_MaxChars(pDX, m_strAllowErrorPrice, 4);
}

BEGIN_MESSAGE_MAP(CgetXYDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP

	ON_BN_CLICKED(ID_OK, &CgetXYDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_EXIT, &CgetXYDlg::OnExit)
	ON_BN_CLICKED(IDCANCEL, &CgetXYDlg::OnBnClickedCancel)
	ON_BN_CLICKED(ID_CLEAR, &CgetXYDlg::OnBnClickedClear)
	ON_BN_CLICKED(ID_FROM_FILE, &CgetXYDlg::OnBnClickedFromFile)
END_MESSAGE_MAP()


// CgetXYDlg ��Ϣ�������

BOOL CgetXYDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CgetXYDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CgetXYDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CgetXYDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CgetXYDlg::OnExit()
{
	OnCancel();
}

void CgetXYDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnCancel();
}

void CgetXYDlg::OnBnClickedOk()
{
	float fPrice_1;
	float fPrice_2;
	float fSum;
	float fAllowErrorPrice;

	UpdateData();
	
	m_bFromFile = FALSE;

	sscanf_s( m_strPrice_1.GetBuffer(0), "%f", &fPrice_1 );
	sscanf_s( m_strPrice_2.GetBuffer(0), "%f", &fPrice_2 );
	sscanf_s( m_strSum.GetBuffer(0), "%f", &fSum );
	sscanf_s( m_strAllowErrorPrice.GetBuffer(0), "%f", &fAllowErrorPrice );

	getXY( fPrice_1, fPrice_2, fSum, fAllowErrorPrice );
}


void CgetXYDlg::getXY( float fPrice_1, float fPrice_2, float fSum, float fAllowErrorPrice )
{
	FILE *fp = NULL;
	int i, j;
	int nNum_1 = 0, nNum_2 = 0;

	char szSum[20] = {0};
	char szResult[20] = {0};
	char szTmp[500] = {0};

	int nTotal_1 = (int)(1 + (fSum) / fPrice_1);
	int nTotal_2 = (int)(1 + (fSum) / fPrice_2);
	sprintf_s( szSum, sizeof(szSum)-1, "%.2f", fSum );

	fopen_s( &fp, "result.txt", "a+" );

	fprintf( fp, "ʵ���ܽ��: %s\n", szSum );
	fprintf( fp, szTmp );

	sprintf_s( szTmp, sizeof(szTmp)-1,
	"%-20s%-20s%-20s%-40s\n",
	"�۸�һ", "�۸��", "�ܽ��", "��ע" );

	fprintf( fp, szTmp );

	float fTmp = 0.0;
	for ( i=0; i<nTotal_1; i++ )
	{
		for ( j=nTotal_2; j>=0; j-- )
		{
			fTmp = fPrice_1 * i + fPrice_2 * j;
			sprintf_s( szResult, sizeof(szResult)-1, "%.2f", fTmp );
			if ( strcmp( szSum, szResult ) == 0 )
			{
				sprintf_s( szTmp, sizeof(szTmp)-1,
					"%-20d%-20d%-20.2f%-40s",
					i, j, fTmp, "�ܽ�������");

				if ( !m_bFromFile )
				{
					m_ctlList.InsertString( 0, szTmp );
				}
				
				fprintf( fp, szTmp );
				fprintf( fp, "\n" );
			}
			else if ( labs( fTmp - fSum ) <= fAllowErrorPrice )
			{
				sprintf_s( szTmp, sizeof(szTmp)-1,
					"%-20d%-20d%-20.2f%-40s",
					i, j, fTmp, "�ܽ������Χ���ڣ�" );
				if ( !m_bFromFile )
				{
					m_ctlList.InsertString( 0, szTmp );
				}
				fprintf( fp, szTmp );
				fprintf( fp, "\n" );
			}
		}
		
	}

	sprintf_s( szTmp, sizeof(szTmp)-1,
		"%-20s%-20s%-20s%-40s",
		"�۸�һ", "�۸��", "�ܽ��", "��ע" );

	if ( !m_bFromFile )
	{
		m_ctlList.InsertString( 0, szTmp );
		m_ctlList.InsertString( 0, "\n" );
	}

	fprintf( fp, "\n" );
	fclose( fp );
}

void CgetXYDlg::OnBnClickedClear()
{
	while( m_ctlList.GetCount() )
	{
		m_ctlList.DeleteString( 0 );
	}
}

void CgetXYDlg::OnBnClickedFromFile()
{
	FILE *fp = NULL;

	CString strFilePath;
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	float fPrice_1;
	float fPrice_2;
	float fSum;
	float fAllowErrorPrice;

	UpdateData();

	m_bFromFile = TRUE;
	
	sscanf_s( m_strPrice_1.GetBuffer(0), "%f", &fPrice_1 );
	sscanf_s( m_strPrice_2.GetBuffer(0), "%f", &fPrice_2 );
	sscanf_s( m_strAllowErrorPrice.GetBuffer(0), "%f", &fAllowErrorPrice );

	if ( fileDlg.DoModal() != IDOK )
	{
		return;
	}
	
	strFilePath = fileDlg.GetPathName();

	fopen_s( &fp, strFilePath.GetBuffer(0), "r" );

	if ( fp == NULL )
	{
		return;
	}

	while ( !feof( fp ) )
	{
		fscanf_s( fp, "%f", &fSum );
		getXY( fPrice_1, fPrice_2, fSum, fAllowErrorPrice );
	}

	fclose( fp );

	AfxMessageBox( "������ϣ���鿴�������ļ���resulst.txt����" );
}
