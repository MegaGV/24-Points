#include <windows.h>
#include "Judge.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	My24PointsJudge::Application::Run(gcnew My24PointsJudge::Judge());
	return 0;
}