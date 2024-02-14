#pragma once


#ifdef ST_PLATFORM_WINDOWS

extern Soft::Application* Soft::CreateApplication();

int main(int argc, char** argv)
{
	Soft::Log::Init();
	ST_CORE_WARN("Initialized Log!");
	int test = 1;
	ST_INFO("Hello var={0}", test);

	auto app = Soft::CreateApplication();
	app->Run();
	delete app;
}

#endif