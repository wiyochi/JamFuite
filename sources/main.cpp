#include <SFML/Graphics.hpp>
#include "MiniGame/MiniGame.hpp"
#include "MiniGame/Questions.hpp"
#include "MiniGame/Readers/ReaderQuestions.hpp"
#include "MiniGame/QTE.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Fuit Billy!!");

    MiniGame* testQ = new Questions(1);
    int ind = 0;
    MiniGame* testQTE = new QTE(10);
    testQTE->start();

    std::default_random_engine re;
	std::uniform_int_distribution<int> distribKey{ 0 , 4 };

    for(int i = 0; i < 20; i++)
    {
        std::cout << distribKey(re) << std::endl;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        testQTE->update(window);
        /*
        if(!testQ->end())
        {
            testQ->update(window);
        }
        else
        {
            std::cout << "[" << ind << "]Score final: " << testQ->getScore() << std::endl;
            ind = (ind+1)%2;
            delete testQ;
            testQ = new Questions(ind+1);
        }*/

        window.clear();

        window.draw(*testQTE);
        //window.draw(*testQ);

        window.display();
    }

    return 0;
}