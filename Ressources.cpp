#include "Ressources.hpp"

sf::Text genGameOver(sf::Font& font){
    sf::Text text;
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(85);
    text.setColor(sf::Color::White);
    text.move(sf::Vector2f(15,85));
    return text;
}
sf::Text genSpentTime(sf::Font& font){
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setColor(sf::Color::Red);
    text.move(sf::Vector2f(150,200));
    return text;
}
sf::Text genRestart(sf::Font& font){
    sf::Text text;
    text.setFont(font);
    text.setString("Press R to restart");
    text.setCharacterSize(15);
    text.setColor(sf::Color::White);
    text.move(sf::Vector2f(160,10));
    return text;
}
sf::Text genStart(sf::Font& font){
    sf::Text text;
    text.setFont(font);
    text.setString("Press X to Start");
    text.setCharacterSize(70);
    text.setColor(sf::Color::White);
    text.move(sf::Vector2f(15,85));
    return text;
}
