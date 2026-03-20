#include <engine.h>

class sandbox : public engine::application
{
public:
	sandbox()
	{

	}
	~sandbox()
	{

	}
};

engine::application* engine::create_application()
{
	return new sandbox();
}