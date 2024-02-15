#include "stpch.h"

#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Soft {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1980, 1080);
		ST_TRACE(e);

		while (true);
	}
}