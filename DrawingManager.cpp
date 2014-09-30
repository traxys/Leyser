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
void drawGameOverScreen(sf::RenderWindow& window,sf::Text& gameOver,sf::Text& spentTimeTxt,sf::Text& restart,int spentTime){
        window.draw(gameOver);
        spentTimeTxt.setString("Time spent : " + std::to_string(spentTime));
        window.draw(spentTimeTxt);
        window.draw(restart);
}
void drawGame(sf::RenderWindow& window,sf::Sprite& charSprite,sf::Sprite& shieldSprite,Charac& charac,sf::Sprite& laserSprite,Laser* laser,sf::Sprite& backgroundSprite){
        window.draw(backgroundSprite);

        drawChar(window,charSprite,shieldSprite,charac);
        drawLaser(window,laserSprite,laser);
}
