// FogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWork.h"
#include "FogDlg.h"
#include "afxdialogex.h"


// FogDlg dialog

IMPLEMENT_DYNAMIC(FogDlg, CDialogEx)

FogDlg::FogDlg(CCGWorkView* parent, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FOG, pParent), pview(parent)
{

}

FogDlg::~FogDlg()
{
}

void FogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FOG_ENABLED, enable);
	DDX_Control(pDX, IDC_FOG_COLOR, color);
	DDX_Control(pDX, IDC_FOG_INTENSITY, intensity);
	DDX_Control(pDX, IDC_FOG_NEAR, near_bound);
	DDX_Control(pDX, IDC_FOG_FAR, far_bound);
}

BOOL FogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	enable.SetCheck(pview->scene.display_fog);
	color.SetColor(pview->scene.fog_color);
	
	CString str;
	str.Format(L"%.2f", pview->scene.fogIntensity);
	intensity.SetWindowText(str);
	str.Format(L"%.2f", pview->scene.minBoundFog);
	near_bound.SetWindowText(str);
	str.Format(L"%.2f", pview->scene.maxBoundFog);
	far_bound.SetWindowText(str);

	return TRUE;
}


BEGIN_MESSAGE_MAP(FogDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FogDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// FogDlg message handlers


void FogDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();

	pview->scene.display_fog = enable.GetCheck() == BST_CHECKED;
	pview->scene.fog_color = color.GetColor();

	CString str;
	intensity.GetWindowTextW(str);
	pview->scene.fogIntensity = std::stof(str.GetString());
	near_bound.GetWindowTextW(str);
	pview->scene.minBoundFog = std::stof(str.GetString());
	far_bound.GetWindowTextW(str);
	pview->scene.maxBoundFog = std::stof(str.GetString());
}
