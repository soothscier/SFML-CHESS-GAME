#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "ChessBoard.h"
using namespace sf;
const float w = 650;
const float h = 650;
class play{
  private:
    sf::Texture texture[3];
      sf::Sprite sprite[3];
      sf::RectangleShape rectangle;
    public:
    play()
  {
    sf::RenderWindow window(sf::VideoMode(w, h), "Chess The Game Of Kings!");
    
    texture[0].loadFromFile("images/play-button.png");
    texture[1].loadFromFile("images/refresh-button.png");
    texture[2].loadFromFile("images/board.png");

      rectangle.setSize(sf::Vector2f(w, h));
        sprite[0].setTexture(texture[0]);
        sprite[1].setTexture(texture[1]);
        sprite[2].setTexture(texture[2]);
        sprite[0].setScale(2.0f,2.0f);
        sprite[1].setScale(2.0f,2.0f);
        sprite[2].setScale(0.73f,0.73f);
        sprite[0].setPosition(120,20);
        sprite[1].setPosition(400,20);
        sprite[2].setPosition(0,0);
        rectangle.setFillColor(sf::Color::White);
    

    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
              window.close();
              }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            if (sprite[0].getGlobalBounds().contains(pos.x,pos.y)){
              window.close();
              ChessBoard graphics;
              graphics.MainFunctions(1);
            }
            if (sprite[1].getGlobalBounds().contains(pos.x,pos.y)){
              window.close();
              ifstream in,in2;
              in.open("spritepositions.txt");
              in2.open("boardpositions.txt");
              for(int j=0;j<64;j++){
                int a,b;
                char c,d;
                in>>a>>c;
                spritepositions[j]=a;
                in2>>b>>d;
                board[j]=b;}
              ChessBoard graphics;
              graphics.MainFunctions(0);
            }
            }
      }

     window.clear();
     window.draw(rectangle);
     window.draw(sprite[2]);
     window.draw(sprite[0]);
     window.draw(sprite[1]);
     window.display();
  } 

}
};