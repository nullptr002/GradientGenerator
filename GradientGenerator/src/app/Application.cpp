#include "Application.hpp"


auto Application::get() -> Application&
{
	static Application app;

	return app;
}

auto Application::run() -> void
{
	sf::Event evnt;
	sf::Clock deltaClock;

	while (m_window.isOpen())
	{
		sf::Time deltaTime = deltaClock.restart();

		pollEvents(evnt);
		update(deltaTime);
		draw();
	}
}

Application::Application()
	:	m_window(sf::VideoMode(1280, 720), "Gradient Generator"),
		m_background(static_cast<sf::Vector2f>(m_window.getSize())),
		m_gui(m_window)
{
	// defaulting the background color, only in use when no points exist
	m_background.setFillColor(sf::Color(30, 30, 30));
}

auto Application::pollEvents(sf::Event& evnt) -> void
{
	while (m_window.pollEvent(evnt))
	{
		m_gui.pollEvents(evnt);

		if (evnt.type == sf::Event::Closed)
			m_window.close();
	}
}

auto Application::update(sf::Time deltaTime) -> void
{
	m_gui.update(m_window, deltaTime);
}

auto Application::draw() -> void
{
	m_window.clear();
	m_window.draw(m_background);
	m_window.draw(m_gui);
	m_window.display();
}
