#include <SFML/Graphics.hpp>
#include <iostream>
#include "Monster.h"
#include "Spell.h"
#include "SpellManager.h"
#include <string>

using namespace std;

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

		ff3j::SpellResult res = ff3j::castSpell(mon, mon);

		// string s = copy
		// string &s = reference
		// string const &s = unchangable reference
		for (string const &s : res.results) {
			string str = s;
		}

		// Draw
		sf::CircleShape monsterShape(mon.size);
		monsterShape.setFillColor(sf::Color::Red);
		window.clear();
		window.draw(shape);
		window.draw(monsterShape);
		window.display();
	}

	return 0;
}
