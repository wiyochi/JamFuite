#include "QTE.hpp"

bool QTE::keyPressed = false;

QTE::QTE(int nb, int period, int resNode[2]) :
    m_period(sf::milliseconds(period)),
    m_endQTE(false),
    m_intro(true),
    m_cpt(0),
    m_nbOfKey(nb),
    m_goodKey(false),
    nodeWin(resNode[0]),
    nodeLose(resNode[1])
{
    srand(time(NULL));

    if(!m_font.loadFromFile("resources/font/unispace.ttf"))
    {
        std::cout << "Fail to load font in QTE" << std::endl;
    }
}

void QTE::start()
{
    m_graphicKey.setPosition(250, 250);
    m_graphicKey.setFillColor(sf::Color::White);
    m_graphicKey.setCharacterSize(15);
    m_graphicKey.setFont(m_font);
    m_clock.restart();
}

void QTE::update(sf::Window& window)
{
    if(m_intro && m_clock.getElapsedTime().asMilliseconds() < 1000)
    {
        m_graphicKey.setString("QTE!");
    }
    else if(m_intro && m_clock.getElapsedTime().asMilliseconds() < 2000)
    {
        m_graphicKey.setString("3");
    }
    else if(m_intro && m_clock.getElapsedTime().asMilliseconds() < 3000)
    {
        m_graphicKey.setString("2");
    }
    else if(m_intro && m_clock.getElapsedTime().asMilliseconds() < 4000)
    {
        m_graphicKey.setString("1");
    }
    else if(m_intro && m_clock.getElapsedTime().asMilliseconds() >= 4000)
    {
        m_intro = false;
        m_clock.restart();
        newKey(sf::Keyboard::LAlt);
    }
    else
    {
        if(!m_endQTE && m_cpt < m_nbOfKey)
        {
            if(!keyPressed && sf::Keyboard::isKeyPressed(m_key) && m_clock.getElapsedTime().asMilliseconds() < m_period.asMilliseconds())
            {
                keyPressed = true;
                newKey(m_key);
                m_clock.restart();
                m_cpt++;
            }
            else if((!keyPressed && isOtherKeyPressed(m_key)) || (m_clock.getElapsedTime().asMilliseconds() > m_period.asMilliseconds()))
            {
                m_endQTE = true;
            }
            else if(!sf::Keyboard::isKeyPressed(m_key) && !isOtherKeyPressed(m_key))
            {
                keyPressed = false;
            }
        }
    }

    if(m_endQTE)
    {
        m_graphicKey.setString("PERDU!");
        m_score = nodeLose;
        m_end = true;
    }

    if(m_cpt >= m_nbOfKey)
    {
        m_score = nodeWin;
        m_graphicKey.setString("GAGNE!");
        m_end = true;
    }
}


void QTE::newKey(sf::Keyboard::Key except)
{
    int rKey = rand()%5;

    switch(rKey)
    {
    case 0:
        m_key = sf::Keyboard::A;
        if(except == sf::Keyboard::A)
            m_key = sf::Keyboard::Z;
        break;
    case 1:
        m_key = sf::Keyboard::Z;
        if(except == sf::Keyboard::Z)
            m_key = sf::Keyboard::E;
        break;
    case 2:
        m_key = sf::Keyboard::E;
        if(except == sf::Keyboard::E)
            m_key = sf::Keyboard::R;
        break;
    case 3:
        m_key = sf::Keyboard::R;
        if(except == sf::Keyboard::R)
            m_key = sf::Keyboard::T;
        break;
    case 4:
        m_key = sf::Keyboard::T;
        if(except == sf::Keyboard::T)
            m_key = sf::Keyboard::A;
        break;
    }

    switch(m_key)
    {
    case sf::Keyboard::A:
        m_graphicKey.setString("A");
        break;
    case sf::Keyboard::Z:
        m_graphicKey.setString("Z");
        break;
    case sf::Keyboard::E:
        m_graphicKey.setString("E");
        break;
    case sf::Keyboard::R:
        m_graphicKey.setString("R");
        break;
    case sf::Keyboard::T:
        m_graphicKey.setString("T");
        break;
    }
}

bool QTE::isOtherKeyPressed(sf::Keyboard::Key k)
{
    if(k == sf::Keyboard::A)
    {
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::E)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Keyboard::isKeyPressed(sf::Keyboard::T));
    }
    else if(k == sf::Keyboard::Z)
    {
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::E)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Keyboard::isKeyPressed(sf::Keyboard::T));
    }
    else if(k == sf::Keyboard::E)
    {
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Keyboard::isKeyPressed(sf::Keyboard::T));
    }
    else if(k == sf::Keyboard::R)
    {
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::E)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::T));
    }
    else if(k == sf::Keyboard::T)
    {
        return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::E)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::R) || sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    }
}

void QTE::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    MiniGame::draw(window, states);
    window.draw(m_graphicKey, states);
}