#include <Legba.h>

class Sandbox : public Legba::Application {
public:
	Sandbox(){}
	~Sandbox(){}
};

Legba::Application* Legba::CreateApplication() {
	return new Sandbox();
}