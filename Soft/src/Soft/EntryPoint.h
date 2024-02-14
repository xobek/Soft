#pragma once


#ifdef ST_PLATFORM_WINDOWS

extern Soft::Application* Soft::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Soft::CreateApplication();
	app->Run();
	delete app;
}

#endif