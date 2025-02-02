// LightingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWork.h"
#include "LightingDlg.h"
#include "afxdialogex.h"


// LightingDlg dialog

IMPLEMENT_DYNAMIC(LightingDlg, CDialogEx)

LightingDlg::LightingDlg(CCGWorkView* parent, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIGHTING_DLG, pParent), pview(parent)
{
	for (int i = 0; i < LIGHT_NUM; i++) {
		lights[i] = pview->scene.renderer.lights[i];
	}
	ambiant = pview->scene.renderer.ambiant;
	index = 0;
}

LightingDlg::~LightingDlg()
{
}

BOOL LightingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	light_n.SetCurSel(index);

	display_light();

	// Ambiant light
	ambiant_color.SetColor(ambiant.color);

	CString str;
	str.Format(L"%.2f", ambiant.intensity);
	intensity.SetWindowText(str);
	str.Format(L"%d", (int)ambiant.exponent);
	exponent.SetWindowText(str);
	return TRUE;
}

void LightingDlg::display_light()
{
	enabled.SetCheck(lights[index].enabled);
	light_type.SetCurSel(lights[index].type);
	light_color.SetColor(lights[index].color);

	CString str;
	str.Format(L"%.2f", lights[index].data.x);
	light_x.SetWindowText(str);
	str.Format(L"%.2f", lights[index].data.y);
	light_y.SetWindowText(str);
	str.Format(L"%.2f", lights[index].data.z);
	light_z.SetWindowText(str);
	str.Format(L"%.3f", lights[index].diffuse);
	diffuse.SetWindowText(str);
	str.Format(L"%.3f", lights[index].specular);
	specular.SetWindowText(str);
}

void LightingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIGHT_ENABLED, enabled);
	DDX_Control(pDX, IDC_LIGHT_COLOR, light_color);
	DDX_Control(pDX, IDC_LIGHT_POS_X, light_x);
	DDX_Control(pDX, IDC_LIGHT_POS_Y, light_y);
	DDX_Control(pDX, IDC_LIGHT_POS_Z, light_z);
	DDX_Control(pDX, IDC_LIGHT_DIFFUSE, diffuse);
	DDX_Control(pDX, IDC_LIGHT_SPECULAR, specular);
	DDX_Control(pDX, IDC_AMBIANT_COLOR, ambiant_color);
	DDX_Control(pDX, IDC_AMBIANT_INTENSITY, intensity);
	DDX_Control(pDX, IDC_AMBIANT_EXPONENT, exponent);
	DDX_Control(pDX, IDC_LIGHT_N, light_n);
	DDX_Control(pDX, IDC_LIGHT_TYPE, light_type);
}


BEGIN_MESSAGE_MAP(LightingDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_LIGHT_N, &LightingDlg::OnCbnSelchangeLightN)
	ON_BN_CLICKED(IDC_LIGHT_ENABLED, &LightingDlg::OnBnClickedLightEnabled)
	ON_CBN_SELCHANGE(IDC_LIGHT_TYPE, &LightingDlg::OnCbnSelchangeLightType)
	ON_BN_CLICKED(IDC_LIGHT_COLOR, &LightingDlg::OnBnClickedLightColor)
	ON_EN_CHANGE(IDC_LIGHT_POS_X, &LightingDlg::OnEnChangeLightPosX)
	ON_EN_CHANGE(IDC_LIGHT_POS_Y, &LightingDlg::OnEnChangeLightPosY)
	ON_EN_CHANGE(IDC_LIGHT_POS_Z, &LightingDlg::OnEnChangeLightPosZ)
	ON_EN_CHANGE(IDC_LIGHT_DIFFUSE, &LightingDlg::OnEnChangeLightDiffuse)
	ON_EN_CHANGE(IDC_LIGHT_SPECULAR, &LightingDlg::OnEnChangeLightSpecular)
	ON_BN_CLICKED(IDC_AMBIANT_COLOR, &LightingDlg::OnBnClickedAmbiantColor)
	ON_EN_CHANGE(IDC_AMBIANT_INTENSITY, &LightingDlg::OnEnChangeAmbiantIntensity)
	ON_EN_CHANGE(IDC_AMBIANT_EXPONENT, &LightingDlg::OnEnChangeAmbiantExponent)
END_MESSAGE_MAP()


// LightingDlg message handlers


void LightingDlg::OnCbnSelchangeLightN()
{
	index = light_n.GetCurSel();
	display_light();
}


void LightingDlg::OnBnClickedLightEnabled()
{
	lights[index].enabled = !lights[index].enabled;
}


void LightingDlg::OnCbnSelchangeLightType()
{
	if (light_type.GetCurSel() == 0) {
		lights[index].type = LIGHT_POINT;
	}
	else {
		lights[index].type = LIGHT_PARALLEL;
	}
}


void LightingDlg::OnBnClickedLightColor()
{
	lights[index].color = light_color.GetColor();
}


void LightingDlg::OnEnChangeLightPosX()
{
	CString str;
	light_x.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			lights[index].data.x = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnEnChangeLightPosY()
{
	CString str;
	light_y.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			lights[index].data.y = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnEnChangeLightPosZ()
{
	CString str;
	light_z.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			lights[index].data.z = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnEnChangeLightDiffuse()
{
	CString str;
	diffuse.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			lights[index].diffuse = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnEnChangeLightSpecular()
{
	CString str;
	specular.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			lights[index].specular = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnBnClickedAmbiantColor()
{
	ambiant.color = ambiant_color.GetColor();
}


void LightingDlg::OnEnChangeAmbiantIntensity()
{
	CString str;
	intensity.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			ambiant.intensity = std::stof(str.GetString());
		}
		catch (...) {}
	}
}


void LightingDlg::OnEnChangeAmbiantExponent()
{
	CString str;
	exponent.GetWindowTextW(str);
	if (!str.IsEmpty()) {
		try {
			ambiant.exponent = std::stof(str.GetString());
		}
		catch (...) {}
	}
}
