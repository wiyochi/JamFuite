#include <SFML/Graphics.hpp>
#include "MiniGame/MiniGame.hpp"
#include "MiniGame/Questions.hpp"
#include "MiniGame/Readers/ReaderQuestions.hpp"
#include "MiniGame/QTE.hpp"
#include "MiniGame/Readers/ReaderStoryLine.hpp"
#include "StoryTeller/storyTeller.hpp"
#include "MiniGame/EndGame.hpp"


int getGameType(int state)
{
    int type = 0;
    if (state == 34 || state == 20)
        type = 6;
    else if (state == 31 ||state == 11 || state == 48 || state == 15)
        type = 3;
    else if (state == 38)
        type = 5;
    else if (state == 23 || state == 43)
        type = 4;
    else if (state == 3 || state == 7 || state == 8 
            || state == 12 || state == 13 || state == 19
            || state == 21 || state == 22 || state == 24
            || state == 26 || state == 28 || state == 29
            || state == 30 || state == 32 || state == 33
            || state == 37 || state == 39 || state == 42
            || state == 44 || state == 47 || state == 50)
        type = 2;
    
    return type;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Fuit Billy!!");

    int state = 1;
    StoryTeller st;
    ReaderStoryLine rs;
    Node * n;

    rs.loadAndInjectData("./resources/story.json", st);

    std::cout << "####################################################" << std::endl;
    for(auto node : st.accesCaca())
    {
        std::cout << "Node: " << node->getNodeId() << " :" << std::endl;
        for(auto child : node->getNodes())
        {
            std::cout << "\t" << child->getNodeId();
        }
        std::cout << std::endl;
    }

    n = st.getNode(state);

    for(auto no : n->getNodes())
    {
        std::cout << "Child: " << no->getNodeId() << std::endl;
    }

    MiniGame * game = new Questions(state);
    game->start();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!game->end())
        {
            game->update(window);
        }
        else
        {
            std::cout << "Input : " << game->getScore() << std::endl;;
            n = n->getNode(game->getScore());
            //n = st.getNode(game->getScore());
            n = st.accesCaca()[49];

            if(n == nullptr)
            {
                std::cout << "NULL" << std::endl;
            }

            std::cout << "NodeInfo: " << n->getNodeId() << "[";
            for(Node* child : n->getNodes())
            {
                std::cout << child->getNodeId() << ",";
            }
            std::cout << "]" << std::endl;

            state = n->getNodeId();
            std::cout << "STATE new : " << state << std::endl;
            delete game;
            switch (getGameType(state))
            {
                case 0:
                    game = new Questions(state);
                    break;
                case 2:
                    game = new EndGame(state);
                    break;
                case 3:
                    game = new QTE(10, 3000, new int[2]{33, 32});
                    break;
                case 4:
                    //game = new CodeGame(state);
                    break;
                case 5:
                    //game = new Sokoban(state);
                    break;
                case 6:
                    //game = new Clicker(state);
                    break;
            }
            game->start();
        }

        window.clear();
        window.draw(*game);

        window.display();
    }

    return 0;
}
    //MiniGame* testQ = new Questions(1);
    //int ind = 0;
   // MiniGame* testQTE = new QTE(10);
    //testQTE->start();


        /*
        testQTE->update(window);
        
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
       // window.draw(*testQTE);
        //window.draw(*testQ);