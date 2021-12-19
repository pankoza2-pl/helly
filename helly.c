#include <windows.h>
static ULONGLONG r, n;
int randy() { return n = r, n ^= 0x8ebf635bee3c6d25, n ^= n << 5 | n >> 26, n *= 0xf3e05ca5c43e376b, r = n, n & 0x7fffffff;}

DWORD
WINAPI
helly1(

) {
	HDC hdcScreen = GetDC(0);
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	for (int i = 0;; i++) {
		int(a) = randy() % w, b = randy() % h;
		BitBlt(hdcScreen, a, b, 200, 200, hdcScreen, a + randy() % 21 - 10, b + randy() % 21 - 10, !(randy() & 3) ? 0xEE0086 : 0xCC0020);
	}
}

DWORD
WINAPI
helly2(

) {
	int tymez = GetTickCount();
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* pRGBQUAD = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	for (int i = 0;; i++, i %= 3) {
		if (!1)RedrawWindow(0, 0, 0, 133);
		HDC hdcSource = GetDC(0), hdcScreen = CreateCompatibleDC(hdcSource); HBITMAP hBitmapData = CreateBitmap(w, h, 1, 32, pRGBQUAD);
		SelectObject(hdcScreen, hBitmapData);
		BitBlt(hdcScreen, 0, 0, w, h, hdcSource, 0, 0, 0x330008); GetBitmapBits(hBitmapData, w * h * 4, pRGBQUAD);
		int Vortex = 0;
		BYTE hByteData = 0;
		if ((GetTickCount() - tymez) > 60000)
			hByteData = randy() & 0xff;
		for (int i = 0; w * h > i; i++) {
			if (i % h == 0 && randy() % 100 == 0)
				Vortex = randy() % 50;
			((BYTE*)(pRGBQUAD + i))[Vortex % 3] += ((BYTE*)(pRGBQUAD + i + Vortex))[Vortex] ^ hByteData;
		}
		SetBitmapBits(hBitmapData, w * h * 4, pRGBQUAD); BitBlt(hdcSource, randy() % 3 - 1, randy() % 3 - 1, w, h, hdcScreen, 0, 0, 0xCC0020);
		DeleteObject(hBitmapData); DeleteObject(hdcScreen);
		DeleteObject(hdcSource);
	}
}

int main(HINSTANCE(a), HINSTANCE(b), LPSTR(c), int(d))
{

       CreateThread(0, 0, helly1, 0, 0, 0);
       CreateThread(0, 0, helly2, 0, 0, 0);
       Sleep(INFINITE);
}