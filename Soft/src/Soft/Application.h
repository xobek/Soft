#pragma once

#include "Core.h"

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


