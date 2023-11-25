#include "Dialog1.h"
#include "resource.h"
#include "sub_cmp.h"
#include "sub_test.h"

extern "C" extern HINSTANCE__ __ImageBase;

INT_PTR Dialog1::DialogBoxParamW
( _In_opt_ HWND      hWndParent    
, _In_     LPARAM    dwInitParam   
) noexcept
{
	return /*WINUSERAPI INT_PTRWINAPI*/::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */&__ImageBase
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG1)
	, /*_In_opt_ HWND      hWndParent    */hWndParent    
	, /*_In_opt_ DLGPROC   lpDialogFunc  */[]
		( HWND   hDlg
		, UINT   Msg
		, WPARAM wParam
		, LPARAM lParam
		) noexcept->INT_PTR
		{
			if (Msg == WM_INITDIALOG) {
				const auto pThis = new Dialog1;
				SetWindowLongPtrW(hDlg, DWLP_DLGPROC, LONG_PTR(DialogProc));
				SetWindowLongPtrW(hDlg, DWLP_USER   , LONG_PTR(pThis     ));
				CheckDlgButton(hDlg, IDC_RADIO_CMP, BST_CHECKED);
				return true;
			}
			else
				return false;
		}
	, /*_In_     LPARAM    dwInitParam   */dwInitParam   
	);
}
Dialog1* Dialog1::FromHandle(HWND hDlg) noexcept
{
	return (Dialog1*)GetWindowLongPtrW(hDlg, DWLP_USER);
}
void Dialog1::UpdateUI(HWND hDlg) noexcept
{
	const auto read_value = [hDlg](_In_ int nIDDlgItem)
	{
		char buf[256];
		GetDlgItemTextA(hDlg, nIDDlgItem, buf, sizeof buf);
#ifdef _WIN64
		return strtoll(buf, nullptr, 0);
#else
		return strtol(buf, nullptr, 0);
#endif
	};
	const auto flags = (*(IsDlgButtonChecked(hDlg, IDC_RADIO_CMP)
		? sub_cmp
		: sub_test
		))
		( read_value(IDC_EDIT_a)
		, read_value(IDC_EDIT_b)
		);
	CheckDlgButton(hDlg, IDC_CHECK_CF, flags & 0x0001 ? BST_CHECKED : 0);
	CheckDlgButton(hDlg, IDC_CHECK_ZF, flags & 0x0040 ? BST_CHECKED : 0);
	CheckDlgButton(hDlg, IDC_CHECK_SF, flags & 0x0080 ? BST_CHECKED : 0);
	CheckDlgButton(hDlg, IDC_CHECK_OF, flags & 0x0800 ? BST_CHECKED : 0);
}
INT_PTR CALLBACK Dialog1::DialogProc
( HWND   hDlg
, UINT   Msg
, WPARAM wParam
, LPARAM lParam
) noexcept
{
	switch (Msg) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_EDIT_a:
		case IDC_EDIT_b:
			if (HIWORD(wParam) == EN_CHANGE) {
				FromHandle(hDlg)->UpdateUI(hDlg);
				return true;
			}
			else
				return false;
		case IDC_RADIO_CMP:
		case IDC_RADIO_TEST:
			if (HIWORD(wParam) == BN_CLICKED) {
				FromHandle(hDlg)->UpdateUI(hDlg);
				return true;
			}
			else
				return false;
		case IDCANCEL:
			EndDialog(hDlg, IDOK);
			return true;
		default:
			return false;
		}
	case WM_NCDESTROY:
		delete FromHandle(hDlg);
		return true;
	default:
		return false;
	}
}
