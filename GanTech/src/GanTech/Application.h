#pragma once

#include "Core.h"

namespace GanTech {
	class GT_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/// Client should return this!
	Application* CreateApplication();
}
