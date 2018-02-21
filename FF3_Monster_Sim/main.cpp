#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "Spell.h"
#include <iostream>

int WinMain()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		ff3j::Spell spell;
		spell.setLevel(1);
		

		Monster mon;
		sf::CircleShape monsterShape(mon.size);
		monsterShape.setFillColor(sf::Color::Red);

		window.clear();
		window.draw(shape);
		window.draw(monsterShape);
		window.display();
	}

	return 0;
}
