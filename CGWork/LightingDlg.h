#pragma once
#include "Light.h"
#include "CGWorkView.h"

// LightingDlg dialog

class LightingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LightingDlg)

public:
	LightingDlg(CCGWorkView* parent, CWnd* pParent = nullptr);   // standard constructor
	virtual ~LightingDlg();

	CCGWorkView* pview;
	LightParams lights[LIGHT_NUM];
	AmbiantLightParams ambiant;
	int index;
	virtual BOOL OnInitDialog();
	void display_light();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIGHTING_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton enabled;
	CMFCColorButton light_color;
	CEdit light_x;
	CEdit light_y;
	CEdit light_z;
	CEdit diffuse;
	CEdit specular;
	CMFCColorButton ambiant_color;
	CEdit intensity;
	CEdit exponent;
	CComboBox light_n;
	CComboBox light_type;
	afx_msg void OnCbnSelchangeLightN();
	afx_msg void OnBnClickedLightEnabled();
	afx_msg void OnCbnSelchangeLightType();
	afx_msg void OnBnClickedLightColor();
	afx_msg void OnEnChangeLightPosX();
	afx_msg void OnEnChangeLightPosY();
	afx_msg void OnEnChangeLightPosZ();
	afx_msg void OnEnChangeLightDiffuse();
	afx_msg void OnEnChangeLightSpecular();
	afx_msg void OnBnClickedAmbiantColor();
	afx_msg void OnEnChangeAmbiantIntensity();
	afx_msg void OnEnChangeAmbiantExponent();
};
