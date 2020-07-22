#pragma once

#include <SFML\Graphics.hpp>
#include <imgui.h>

class Gui : public sf::Drawable
{
public:
	Gui(sf::RenderWindow& window);
	~Gui();

	auto pollEvents(sf::Event &evnt) -> void;
	auto update(sf::RenderWindow &window, sf::Time deltaTime) -> void;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	auto renderMainWidget() -> void;

private:
};