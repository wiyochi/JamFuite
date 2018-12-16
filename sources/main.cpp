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
        type = 3;
    else if (state == 31 ||state == 11 || state == 48 || state == 15)
        type = 3;
    else if (state == 38)
        type = 3;
    else if (state == 23 || state == 43)
        type = 3;
    else if (state == 3 || state == 7 || state == 8 
            || state == 12 || state == 13 || state == 19
            || state == 21 || state == 22 || state == 24
            || state == 26 || state == 28 || state == 29
            || state == 30 || state == 32 || state == 33
            || state == 36 || state == 37 || state == 39 || state == 40 || state == 42
            || state == 44 || state == 47 || state == 49 || state == 50)
        type = 2;
    return type;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Fuit Billy!!");
    bool debug = true;
    int state = 1;
    StoryTeller st;
    ReaderStoryLine rs;
    Node * n;

    rs.loadAndInjectData("./resources/story.json", st);

    n = st.getNode(state);

    MiniGame * game = new Questions(state);
    game->start();

    std::cout << "KALASH1" << std::endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyReleased)
                if (event.key.code == sf::Keyboard::D)
                {
                    debug = !debug;
                    std::cout << "debug switch" << std::endl;
                }
        }
        if (!game->end())
        {
            game->update(window);
        } else
        {
            std::cout << "Score:" << game->getScore() << std::endl;
            n = n->getNode(game->getScore());
            state = n->getNodeId();
            delete game;
            std::cout << "tYPE //// " << getGameType(state) << std::endl;
            switch (getGameType(state))
            {
                case 0:
                    game = new Questions(state);
                    break;
                case 2:
                    game = new EndGame(state);
                    break;
                case 3:
                    switch (state)
                    {
                        case 11:
                            game = new QTE(5, 3000, new int[2]{14, 13});
                            break;
                        case 15: 
                            game = new QTE(5, 3000, new int[2]{17, 16});
                            break;
                        case 31: 
                            game = new QTE(5, 3000, new int[2]{33, 32});
                            break;
                        case 48:
                            game = new QTE(5, 3000, new int[2]{49, 50});
                            break;
                        case 23:
                            game = new QTE(5, 3000, new int[2]{25, 24});
                            break;
                        case 43:
                            game = new QTE(5, 3000, new int[2]{45, 44});
                            break;
                        case 38:
                            game = new QTE(5, 3000, new int[2]{40, 39});
                            break;
                        case 20:
                            game = new QTE(5, 3000, new int[2]{22, 21});
                            break;
                        case 34:
                            game = new QTE(5, 3000, new int[2]{35, 36});
                            break;

                    }
                    break;
            }
            game->start();
        }

        window.clear();
        window.draw(*game);

        sf::Text t;
        std::stringstream ss;
        ss << "Etat " << state;
        std::string str = ss.str();
        sf::Font m_font;
        if(!m_font.loadFromFile("resources/font/unispace.ttf"))
        {
            std::cout << "Fail load font" << std::endl;
        }

        t.setString(str);
        t.setFont(m_font);
        t.setPosition(10, 10);
        t.setFillColor(sf::Color::Red);
        t.setCharacterSize(15);

        if (debug)
        {
            window.draw(t);
        }

        window.display();
    }

    return 0;
}