#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace sf;
class save{
	private:
		 float W = 650;
		 float H = 650;
	public:
		save(){

		}
bool smain()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "Chess The Game Of Kings!");
    sf::Texture texture[2];
    sf::Sprite sprite[2];
    texture[0].loadFromFile("images/save-disk.png");
    texture[1].loadFromFile("images/gameOver.png");


        sprite[0].setTexture(texture[0]);
        sprite[0].setScale(2.0f,2.0f);
        sprite[0].setPosition(250,20);
        sprite[1].setTexture(texture[1]);
        sprite[1].setScale(0.73f,0.73f);
        sprite[1].setPosition(0,0);

    while (window.isOpen())
    {   Vector2i pos= Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
              window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
            if (sprite[0].getGlobalBounds().contains(pos.x,pos.y)){
              return true;
              window.close();

              }
            }
          
      }

     window.clear();
     window.draw(sprite[1]);
     window.draw(sprite[0]);
     window.display();
  }
    
    
    return 0;
}
};
