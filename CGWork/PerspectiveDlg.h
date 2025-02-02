#pragma once


// PerspectiveDlg dialog

class PerspectiveDlg : public CDialog
{
	DECLARE_DYNAMIC(PerspectiveDlg)

public:
	PerspectiveDlg(CWnd* pParent = nullptr, float depth = 2.0f);   // standard constructor
	virtual ~PerspectiveDlg();
	float depth;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSPECTIVE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeDepthControl();
	virtual BOOL OnInitDialog();
	CEdit edit_depth;
};
