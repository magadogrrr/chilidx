#include <Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreviousInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	const auto pClassName = "chilidxbw";
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIcon = nullptr;
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(0, pClassName, "Manifest Viewport", 
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, SW_SHOW);

	while (true);
	
	return 0;
}