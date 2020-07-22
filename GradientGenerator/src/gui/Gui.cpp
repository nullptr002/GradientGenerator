#include "Gui.hpp"
#include "imgui-SFML.h"

Gui::Gui(sf::RenderWindow& window)
{
	ImGui::SFML::Init(window);
}

Gui::~Gui()
{
	ImGui::SFML::Shutdown();
}

auto Gui::pollEvents(sf::Event& evnt) -> void
{
	ImGui::SFML::ProcessEvent(evnt);
}

auto Gui::update(sf::RenderWindow& window, sf::Time deltaTime) -> void
{
	ImGui::SFML::Update(window, deltaTime);
	renderMainWidget();
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	ImGui::SFML::Render(target);
}

auto Gui::renderMainWidget() -> void
{
	ImGui::ShowDemoWindow();
}
