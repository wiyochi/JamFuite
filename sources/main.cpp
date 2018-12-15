#include <SFML/Graphics.hpp>
#include "MiniGame/MiniGame.hpp"
#include "MiniGame/Questions.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    
    MiniGame* testQ = new Questions();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if(!testQ->end())
        {
            testQ->update(window);
        }
        else
        {
            std::cout << "Score final: " << testQ->getScore() << std::endl;
        }

        window.clear();

        window.draw(*testQ);

        window.display();
    }

    return 0;
}