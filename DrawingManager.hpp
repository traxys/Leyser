#ifndef DRAWINGMANAGER_HPP_INCLUDED
#define DRAWINGMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Charac.hpp"
#include "Laser.hpp"

void drawChar(sf::RenderWindow& window,sf::Sprite& charSprite,sf::Sprite& shieldSprite,Charac& charac);
void drawLaser(sf::RenderWindow& window,sf::Sprite& laserSprite,Laser* laser);

#endif // DRAWINGMANAGER_HPP_INCLUDED
