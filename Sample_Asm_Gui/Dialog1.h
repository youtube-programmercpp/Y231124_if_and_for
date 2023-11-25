#pragma once
#include <Windows.h>
class Dialog1
{
	static Dialog1* FromHandle(HWND hDlg) noexcept;
	void UpdateUI(HWND hDlg) noexcept;
	static INT_PTR CALLBACK DialogProc
	( HWND   hDlg
	, UINT   Msg
	, WPARAM wParam
	, LPARAM lParam
	) noexcept;
public:
	static INT_PTR DialogBoxParamW
	( _In_opt_ HWND      hWndParent    
	, _In_     LPARAM    dwInitParam   
	) noexcept;
};

