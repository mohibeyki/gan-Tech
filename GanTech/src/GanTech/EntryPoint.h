#pragma once

#ifdef GT_PLATFORM_WINDOWS

extern GanTech::Application* GanTech::CreateApplication();

int main(int argc, char** argv) {
	printf("Powered by ganTech\n");
	auto app = GanTech::CreateApplication();
	app->Run();
	delete app;
}

#endif
