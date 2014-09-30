#include "DrawingManager.hpp"


void drawChar(sf::RenderWindow& window,sf::Sprite& charSprite,sf::Sprite& shieldSprite,Charac& charac){
    charSprite.setPosition(sf::Vector2f(10,26+(charac.getLane()-1)*100));
    if(charac.hasShield()){
        shieldSprite.setPosition(sf::Vector2f(5,21+(charac.getLane()-1)*100));
        window.draw(shieldSprite);
    }
    window.draw(charSprite);
}
void drawLaser(sf::RenderWindow& window,sf::Sprite& laserSprite,Laser* laser){
    laserSprite.setPosition(sf::Vector2f(laser->getCoord(),2+(laser->getLane()-1)*100));
    window.draw(laserSprite);
}
