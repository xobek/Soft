#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Soft {

	class SOFT_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}


