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
#include "Ressources.hpp"

using namespace std;

int main(){

    int delayLaserMoves(5); //in mili seconds
    int pushNumber(1); //Inital

    bool isGame(1); //Two bool for 3 states
    bool hasStart(false);//look up
    int spentTime(0); // For the final string , simple init;

    int hit(0); //Not being hit twice is a nice thing;

    sf::RenderWindow window(sf::VideoMode(500,300),"Leyser");

    sf::Font captureIt;
    if(!captureIt.loadFromFile("Capture it.ttf")){}

    sf::Font hacked;
    if(!hacked.loadFromFile("HACKED.ttf")){}

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("background.png")){}

    sf::Texture laserTexture;
    if(!laserTexture.loadFromFile("laser.png")){}

    sf::Texture characTexture;
    if(!characTexture.loadFromFile("char.png")){}

    sf::Texture shieldTexture;
    if(!shieldTexture.loadFromFile("shield.png")){}



    sf::Text gameOver = genGameOver(captureIt);

    sf::Text timeSpentText = genSpentTime(captureIt);

    sf::Text restartText = genRestart(captureIt);

    sf::Text startText = genStart(hacked);

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
                if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z){
                    player.moveLane(UP);
                }
                if(event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S){
                    player.moveLane(DOWN);
                }
                if(event.key.code == sf::Keyboard::G){
                    isGame = false;
                }
                if(event.key.code == sf::Keyboard::X && !hasStart){
                    hasStart = true;
                    gameClock.restart();
                    pushNumber = 1;
                }
                if(event.key.code == sf::Keyboard::R && !isGame){
                    isGame = true; // Re-Init evrything
                    pushNumber = 1;
                    gameClock.restart();
                    laserClock.restart();
                    spentTime = 0;
                    player.setShield();
                    delete laser;
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
            drawGame(window,charSprite,shieldSprite,player,laserSprite,laser,backgroundSprite);
        }
        if(!isGame){
            drawGameOverScreen(window,gameOver,timeSpentText,restartText,spentTime);
        }
        if(!hasStart){
            window.draw(startText);
        }

        window.display();
	}
    return 0;
}
