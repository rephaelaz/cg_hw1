// AnimationSpeedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWork.h"
#include "AnimationSpeedDlg.h"
#include "afxdialogex.h"


// AnimationSpeedDlg dialog

IMPLEMENT_DYNAMIC(AnimationSpeedDlg, CDialogEx)

AnimationSpeedDlg::AnimationSpeedDlg(CCGWorkView* parent, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANIMATION_SPEED, pParent), parent(parent)
{
	speed_value = parent->scene.animator.speed;
}

AnimationSpeedDlg::~AnimationSpeedDlg()
{
}

void AnimationSpeedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, speed);
}


BEGIN_MESSAGE_MAP(AnimationSpeedDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AnimationSpeedDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AnimationSpeedDlg message handlers
BOOL AnimationSpeedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;
	str.Format(L"%d", speed_value);
	speed.SetWindowText(str);
	return TRUE;
}

void AnimationSpeedDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
	CString str;
	speed.GetWindowTextW(str);
	parent->scene.animator.speed = std::stoi(str.GetString());
}
