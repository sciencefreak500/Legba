#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Legba {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LEGBA_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LEGBA_TRACE(e);
		}
		while (true);
	}
}
