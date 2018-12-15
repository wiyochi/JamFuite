#include "QTE.hpp"

QTE::QTE()
{
    if(!m_font.loadFromFile("resources/font/unispace.ttf"))
    {
        std::cout << "Fail to load font in QTE" << std::endl;
    }
}

void QTE::start()
{
    m_graphicKey.setFillColor(sf::Color::White);
    m_graphicKey.setCharacterSize(15);
    m_graphicKey.setFont(m_font);
    
    newKey();
    m_clock.restart();
}

void QTE::update(sf::Window& window)
{

}


void QTE::newKey()
{
    int rKey = distribKey(re);

    switch(rKey)
    {
    case 0:
        m_key = sf::Keyboard::A;
        m_graphicKey.setString("A");
        break;
    case 1:
        m_key = sf::Keyboard::Z;
        m_graphicKey.setString("Z");
        break;
    case 2:
        m_key = sf::Keyboard::E;
        m_graphicKey.setString("E");
        break;
    case 3:
        m_key = sf::Keyboard::R;
        m_graphicKey.setString("R");
        break;
    case 4:
        m_key = sf::Keyboard::T;
        m_graphicKey.setString("T");
        break;
    }

    m_graphicKey.setPosition(distribPosition(re), distribPosition(re));
}

void QTE::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    MiniGame::draw(window, states);
    window.draw(m_graphicKey, states);
}