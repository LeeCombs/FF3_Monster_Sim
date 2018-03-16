#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Monster.h"
#include "Spell.h"
#include "SpellManager.h"

using namespace std;
using namespace ff3j;

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

        Spell spell;
        spell.setLevel(1);

        Monster mon;
        SpellResult res = castSpell(spell, mon, mon);

        // string s = copy
        // string &s = reference
        // string const &s = unchangable reference
        for (string const &s : res.results) {
            string str = s;
        }

        // Draw
        sf::CircleShape monsterShape(75);
        monsterShape.setFillColor(sf::Color::Red);
        window.clear();
        window.draw(shape);
        window.draw(monsterShape);
        window.display();
    }

    return 0;
}
