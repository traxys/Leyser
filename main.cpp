#include <iostream>
#include <string>
#include <random>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Charac.hpp"
#include "Laser.hpp"
#include "DrawingManager.hpp"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(500,300),"Leyser");

    sf::Font captureIt;
    if(!captureIt.loadFromFile("Capture it.ttf")){//No Game Over

    }
    sf::Text gameOver;
    gameOver.setFont(captureIt);
    gameOver.setString("Game Over");
    gameOver.setCharacterSize(85);
    gameOver.setColor(sf::Color::White);
    gameOver.move(sf::Vector2f(15,85));

    sf::Text timeSpentText;
    timeSpentText.setFont(captureIt);
    timeSpentText.setCharacterSize(25);
    timeSpentText.setColor(sf::Color::Red);
    timeSpentText.move(sf::Vector2f(150,200));

    sf::Font hacked;
    if(!hacked.loadFromFile("HACKED.ttf")){//No start screen

    }
    sf::Text startText;
    startText.setFont(hacked);
    startText.setString("Press S to Start");
    startText.setCharacterSize(70);
    startText.setColor(sf::Color::White);
    startText.move(sf::Vector2f(15,85));

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("background.png")){ //Handle FATAL error;

    }
    sf::Texture laserTexture;
    if(!laserTexture.loadFromFile("laser.png")){//Still a fatal error

    }
    sf::Texture characTexture;
    if(!characTexture.loadFromFile("char.png")){//And fatal again

    }
    sf::Texture shieldTexture;
    if(!shieldTexture.loadFromFile("shield.png")){//You could play , maybe.

    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Sprite charSprite;
    charSprite.setTexture(characTexture);
    sf::Sprite laserSprite;
    laserSprite.setTexture(laserTexture);
    sf::Sprite shieldSprite;
    shieldSprite.setTexture(shieldTexture);

    sf::Clock gameClock;

    sf::Clock laserClock;
    int delayLaserMoves(5); //in mili seconds
    int pushNumber(1);

    bool isGame(1);
    bool hasStart(false);
    int spentTime(0);

    int hit(0);

    Charac player;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    Laser* laser;
    laser = new Laser(dis(gen));

    while(window.isOpen()){
        sf::Event event;

        if(window.pollEvent(event)){
             if(event.type == sf::Event::Closed){

                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    player.moveLane(UP);
                }
                if(event.key.code == sf::Keyboard::Down){
                    player.moveLane(DOWN);
                }
                if(event.key.code == sf::Keyboard::G){
                    isGame = false;
                }
                if(event.key.code == sf::Keyboard::S && !hasStart){
                    hasStart = true;
                    gameClock.restart();
                    pushNumber = 1;
                }
            }
        }
        if(hasStart && isGame){
            if(laser->getCoord() <= 0){
                laser =  new Laser(dis(gen));
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 10){
                pushNumber = 2;
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 25){
                pushNumber = 3;
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 40){
                pushNumber = 5;
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 60){
                pushNumber = 9;
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 90){
                pushNumber = 17;
            }
            if( (int) gameClock.getElapsedTime().asSeconds() == 100){
                pushNumber = 25;
            }


            if( (int) laserClock.getElapsedTime().asMilliseconds() >= delayLaserMoves){
                laser->pushLaser(pushNumber);
                laserClock.restart();
            }
            if(laser->getCoord() <= 60 && laser->getLane() == player.getLane() && hit == 0){
                if(player.hasShield()){
                    player.removeShield();
                }
                else{
                    isGame = false;
                    spentTime = gameClock.getElapsedTime().asSeconds();
                }

                hit = 1;
            }
            if(laser->getCoord() > 60){
                hit = 0;
            }

            player.checkShield();
        }

        window.clear(sf::Color::Black);

        if(isGame && hasStart){
        window.draw(backgroundSprite);

        drawChar(window,charSprite,shieldSprite,player);
        drawLaser(window,laserSprite,laser);
        }
        if(!isGame){
            window.draw(gameOver);
            timeSpentText.setString("Time spent : " + std::to_string(spentTime));
            window.draw(timeSpentText);
        }
        if(!hasStart){
            window.draw(startText);
        }

        window.display();
	}
    return 0;
}
