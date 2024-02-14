#include <Soft.h>

class Sandbox : public Soft::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Soft::Application* Soft::CreateApplication()
{
	return new Sandbox();
}