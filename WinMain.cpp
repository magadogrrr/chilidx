#include <Windows.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	default: ;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

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
	wc.lpfnWndProc = WndProc;
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

	MSG msg;
	while(GetMessage(&msg, nullptr, 0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}