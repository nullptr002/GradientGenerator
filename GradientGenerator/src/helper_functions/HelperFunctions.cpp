#include "HelperFunctions.hpp"

auto to255Color(sf::Glsl::Vec4 color) -> sf::Color
{
	return sf::Color{
		sf::Uint8(color.x * 255),
		sf::Uint8(color.y * 255),
		sf::Uint8(color.z * 255),
		sf::Uint8(color.w * 255)
	};
}
