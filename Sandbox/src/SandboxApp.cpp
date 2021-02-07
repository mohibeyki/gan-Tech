#include <GanTech.h>

class Sandbox : public GanTech::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

GanTech::Application* GanTech::CreateApplication() {
	return new Sandbox();
}
