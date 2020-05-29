#include <windows.h>
#include "twentyFour_Points.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	My24Points::Application::Run(gcnew My24Points::twentyFour_Points());
	return 0;
}


