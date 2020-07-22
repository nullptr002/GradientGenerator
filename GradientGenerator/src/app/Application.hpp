#pragma once

#include "../gui/Gui.hpp"

class Application final
{
public:
	static auto get() -> Application&;

	Application(const Application&) = delete;
	auto operator=(const Application&)	-> Application& = delete;

	auto run()							-> void;

private:
	Application();

	auto pollEvents(sf::Event& evnt)	-> void;
	auto update(sf::Time deltaTime)		-> void;
	auto draw()							-> void;

private:
	sf::RenderWindow	m_window;

	sf::RectangleShape	m_background;
};