#pragma once

#ifdef LEGBA_PLATFORM_WINDOWS

extern Legba::Application* Legba::CreateApplication();

int main(int argc, char** argv) {
	Legba::Log::Init();
	LEGBA_CORE_WARN("Initialized Logger");
	LEGBA_INFO("Initialized Logger: {0}", 5);
	auto app = Legba::CreateApplication();
	app->Run();
	delete app;
}

#endif
