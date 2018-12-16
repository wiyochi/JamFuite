#ifndef _QTE_
#define _QTE_

#include <time.h>
#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MiniGame.hpp"

class QTE : public MiniGame
{
public:
    QTE(int nb, int period, int resNode[2]);
    void start();
    void update(sf::Window& window);
    void newKey(sf::Keyboard::Key except);
    bool isOtherKeyPressed(sf::Keyboard::Key);

    static bool keyPressed;

private:
    sf::Clock m_clock;
    sf::Time m_period;
    std::default_random_engine re;
	std::uniform_int_distribution<int> distribKey{ 0 , 4 };
    sf::Keyboard::Key m_key;
    sf::Text m_graphicKey;
    sf::Font m_font;
    bool m_endQTE;
    bool m_intro;
    bool m_goodKey;
    int m_cpt;
    int m_nbOfKey;
    int nodeWin;
    int nodeLose;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif // !_QTE_