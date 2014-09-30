#ifndef DRAWINGMANAGER_HPP_INCLUDED
#define DRAWINGMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Charac.hpp"
#include "Laser.hpp"

void drawChar(sf::RenderWindow& window,sf::Sprite& charSprite,sf::Sprite& shieldSprite,Charac& charac);
void drawLaser(sf::RenderWindow& window,sf::Sprite& laserSprite,Laser* laser);
void drawGameOverScreen(sf::RenderWindow& window,sf::Text& gameOver,sf::Text& spentTimeTxt,sf::Text& restart,int spentTime);
void drawGame(sf::RenderWindow& window,sf::Sprite& charSprite,sf::Sprite& shieldSprite,Charac& charac,sf::Sprite& laserSprite,Laser* laser,sf::Sprite& backgroundSprite);

#endif // DRAWINGMANAGER_HPP_INCLUDED
