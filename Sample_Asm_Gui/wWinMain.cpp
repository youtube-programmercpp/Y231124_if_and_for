#include "Dialog1.h"
#include "resource.h"

int WINAPI wWinMain
( _In_     HINSTANCE hInstance
, _In_opt_ HINSTANCE hPrevInstance
, _In_     LPWSTR    lpCmdLine
, _In_     int       nCmdShow
)
{
	(void)Dialog1::DialogBoxParamW
	( nullptr
	, {}
	);
}
