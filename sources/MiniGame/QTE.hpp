#ifndef _QTE_
#define _QTE_

#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MiniGame.hpp"

class QTE : public MiniGame
{
public:
    QTE();
    void start();
    void update(sf::Window& window);
    void newKey();

private:
    sf::Clock m_clock;
    std::default_random_engine re;
	std::uniform_int_distribution<int> distribPosition{ 10 , 790 };
	std::uniform_int_distribution<int> distribKey{ 0 , 4 };
    sf::Keyboard::Key m_key;
    sf::Text m_graphicKey;
    sf::Font m_font;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif // !_QTE_