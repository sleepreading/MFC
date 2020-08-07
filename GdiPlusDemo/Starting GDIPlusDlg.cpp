// Starting GDIPlusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Starting GDIPlus.h"
#include "Starting GDIPlusDlg.h"

#include "Global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStartingGDIPlusDlg dialog

CStartingGDIPlusDlg::CStartingGDIPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStartingGDIPlusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStartingGDIPlusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStartingGDIPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStartingGDIPlusDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStartingGDIPlusDlg, CDialog)
	//{{AFX_MSG_MAP(CStartingGDIPlusDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStartingGDIPlusDlg message handlers

BOOL CStartingGDIPlusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStartingGDIPlusDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 0xFFF0) == SC_CLOSE)
    {
        GetDesktopWindow()->Invalidate(TRUE);
		CDialog::OnSysCommand(nID, lParam);
   }
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStartingGDIPlusDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStartingGDIPlusDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStartingGDIPlusDlg::OnButton1() 
{
	AfxBeginThread(ThreadFun,GetDC()->m_hDC);
}

UINT __cdecl CStartingGDIPlusDlg::ThreadFun( LPVOID lpParam )
{
	HDC hdc = (HDC)lpParam;

	Graphics graphics(hdc);

	// There is a second parameter - a width which defaults to 1.0f
	Pen	blue (Color(255, 0, 0, 255));
	Pen red  (Color(255, 255, 0, 0));

	int y = 256;
	for (int x = 0; x < 256; x += 5)
	{
		graphics.DrawLine(&blue, 0, y, x, 0);
		graphics.DrawLine(&red, 256, x, y, 256);  
		y -= 5;
	}		

	for (y = 0; y < 256; y++)
	{
		Pen pen(Color(y, 0, 255,0));  // A green pen with shifting alpha
		graphics.DrawLine(&pen, 0, y, 256, y);
		// The sleep is to slow it down so you can watch the effect
		Sleep(20);
	}

	for (x = 0; x < 256; x++)
	{
		Pen pen(Color(x, 255, 0, 255));  // A green pen with shifting alpha
		graphics.DrawLine(&pen, x, 100, x, 200);
		// The sleep is to slow it down so you can watch the effect
		Sleep(20);
	}

	return 0;
}

void CStartingGDIPlusDlg::OnButton2() 
{
	Graphics graphic(GetDC()->m_hDC);
	graphic.SetSmoothingMode(SmoothingModeHighQuality); //是绘画尽可能的平滑

	Pen pen(Color(255,0,0,255),8); //8 :粗细,float类型
	graphic.DrawRectangle(&pen,20,20,200,100);

	HatchBrush hbr(HatchStyle90Percent,Color::Green,Color::Silver); //纹理线颜色,纹理线背景色
	graphic.FillRectangle(&hbr,20,20,200,100);

/*		   | -->这半截代表线
		   |
-----------|-------------> x
		   | 0
		   |
		   v y

	线冒所使用的坐标系
*/
	pen.SetStartCap(LineCapRoundAnchor); //设置线起点的线冒
	pen.SetEndCap(LineCapArrowAnchor);
	graphic.DrawLine(&pen,20,20,200,100);


	/*
	 * Text
	 */
	Font font(&FontFamily(L"Arial"),24,FontStyleRegular,UnitPixel); //大小,样式,字体尺寸采用像素来度量
	// len, Font*, PointF& StringPos, Brush* StringColor
	graphic.DrawString(L"hello world",-1,&font,PointF(20.0f,120.0f),&SolidBrush(Color(255,200,200,0)));


	/*
	 * image
	 */
	Image img(L"sea.jpg");
	TextureBrush tbr(&img);
	tbr.RotateTransform(30); //旋转30度（注意单位为度,而非弧度）
	tbr.TranslateTransform(30, 30); //平移(30, 30),右下
	tbr.ScaleTransform(3, 1); //水平放大3倍
	
	Pen tpen(&tbr,16); //16: width
	tpen.SetAlignment(PenAlignmentInset); //内对齐,外界矩形
	graphic.DrawEllipse(&tpen,180,10,420,220);

	SolidBrush sbr(Color(200,0,255,255));
	graphic.FillEllipse(&sbr,200,20,400,200);

	// file save
	CLSID imgClsid;
	GetImageEncoderClsid(L"image/png",&imgClsid);
	img.Save(L"sea.png",&imgClsid,NULL);


	/*
	 * path
	 */
	Point pt[] = {
		Point(0,250),
		Point(50,230),
		Point(100,170),
		Point(150,230),
		Point(200,250),
	};
	graphic.DrawCurve(&Pen(Color(255,0,0,0),4),pt,5,0.5f); //0.5 :张力参数,0为直线


	GraphicsPath path;
	path.AddEllipse(200,20,400,200);
	PathGradientBrush pthbr(&path);
	pthbr.SetCenterColor(Color(255,255,0,0));
	Color cls[] = {Color(255,0,0,255)};
	int cnt = 1;
	pthbr.SetSurroundColors(cls,&cnt); //设置boundary颜色
	graphic.FillEllipse(&pthbr,200,20,400,200);

//	graphic.Clear(Color(200,0,200,0));	//清空当前画布
}

void CStartingGDIPlusDlg::OnButton3() 
{
	CDC* pDC = GetDC();
	HDC hdc = pDC->m_hDC; //<==>
	hdc = ::GetDC(m_hWnd);

	/*
	 * brush & pen
	 */
	CPen Pen(PS_SOLID,5,RGB(233,34,34)); //<==>
	//Pen.CreatePen(PS_SOLID | PS_COSMETIC, 1, RGB(0, 0, 255));
	HPEN pen = ::CreatePen(PS_SOLID,4,RGB(0,0,0));
	//HPEN OldPen = (HPEN)SelectObject(hdc,Pen);

	CBrush br(RGB(255,0,255));
	HBRUSH brush = ::CreateSolidBrush(RGB(255,216,156));
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)); //透明画刷
	//HBRUSH OldBrush = (HBRUSH)::SelectObject (hdc,brush);

	RECT rect = {100,100,300,300};
	pDC->FillRect(&rect,pBrush);
	// rectangle
	pDC->Rectangle(0,0,100,24);
	::Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
	// arc
	POINT pt1 = {100,100};
	POINT pt2 = {300,300};
	pDC->Arc(&rect,pt1,pt2);
	// line
	POINT polyline[] = {{70,240},{20,190},{70,190},{20,240}};
	POINT polyPolyline[9] = {{95,160},{120,185},{120,250},{145,160},{120,185},{90,185},{150,185},{80,210},{160,120}};
	DWORD dwPolyPoints[4]={3,2,2,2};
	pDC->Polyline(polyline,sizeof(polyline)/sizeof(POINT));
	pDC->PolyPolyline(polyPolyline,dwPolyPoints,4);
	// region
	HRGN hrgn = CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
	hrgn = CreateEllipticRgn(0, 0, 75, 48);
	// SelectClipRgn(hdc, hrgn);
	// BitBlt()
	// SelectClipRgn(hdc,NULL);


	/*
	 * Text
	 */
	int OldBkMode = ::SetBkMode(hdc,TRANSPARENT);
	char buf[100] = "Hello world!";
	::SetTextColor(hdc,RGB(255,0,0));

	::DrawText(hdc,"buf",strlen(buf),&rect,DT_EXPANDTABS|DT_LEFT|DT_END_ELLIPSIS);
	::TextOut(hdc,90,90,buf,strlen(buf)); //简单的Text,(90,90)为坐标
	::SetBkMode(hdc,OldBkMode);


	/*
	 * cleanup
	 */
	::DeleteObject(pen);
	::DeleteObject(brush);
	::ReleaseDC(m_hWnd,hdc);
}

void CStartingGDIPlusDlg::OnButton4() 
{
	HDC hdc = ::GetDC(NULL); //get desktop dc
	HPEN penBlue = CreatePen(PS_SOLID,4,RGB(0,0,255));
	HPEN penRed = CreatePen(PS_SOLID,4,RGB(255,0,0));
	HPEN penBlack = (HPEN)GetStockObject(BLACK_PEN);
	HBRUSH brBlack = CreateSolidBrush(RGB(0,0,0));
	HBRUSH brGreen = CreateSolidBrush(RGB(0,255,0));
	HBRUSH brOrange= CreateSolidBrush(RGB(255,165,0));
	HBRUSH brHatch = CreateHatchBrush(HS_DIAGCROSS,RGB(184,134,11));
#if 0
	::SelectObject(hdc,penBlue);
	::MoveToEx(hdc,0,0,NULL);
	::LineTo(hdc,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));

#endif
	/*
	 * Region
	 * 无论什么region都有一个包括这个区域的最小矩形,使用GetRgnBox()来获取
	 */
	RECT rt = {36,36,512,256};
	HRGN rg = CreateEllipticRgnIndirect(&rt);
	PaintRgn(hdc,rg); //使用当前的画刷绘制区域
	Sleep(500);
	FillRgn(hdc,rg,brGreen); //使用指定的画刷的画刷绘制
	Sleep(500);
	InvertRgn(hdc,rg); //对区域的填充色取反
	Sleep(500);
	FrameRgn(hdc,rg,brHatch,4,4); //填充区域的外围,4,4表示周边的宽度

#if 1
	OffsetRgn(rg,32,32); //移动区域
	FillRgn(hdc,rg,brOrange);
	Sleep(500);
	HRGN rg2 = CreateRoundRectRgn(100,80,400,800,32,32);
	HRGN rgDest = CreateRectRgn(0,0,0,0); //必须先存在
	CombineRgn(rgDest,rg,rg2,RGN_AND);
	FillRgn(hdc,rgDest,brBlack);
	
#endif
	::DeleteObject(penBlue);
	::DeleteObject(penRed);
	::DeleteObject(brBlack);
	::DeleteObject(brGreen);
	::DeleteObject(brOrange);
	::DeleteObject(brHatch);
	::DeleteObject(rg);
	::ReleaseDC(NULL,hdc);
}
