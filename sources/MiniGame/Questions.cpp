#include "Questions.hpp"

Questions::Questions()
{
    loadTextures();
    loadStrings();
    m_bg.setTexture(m_bgTexture);
    m_graphicQuestion.setFont(m_font);
    m_graphicQuestion.setCharacterSize(15);
    m_graphicQuestion.setPosition(100, 50);
    m_graphicQuestion.setFillColor(sf::Color::White);
    for(uint i = 0; i < m_graphicAnswers.size(); i++)
    {
        m_graphicAnswers[i].setFont(m_font);
        m_graphicAnswers[i].setPosition(100, 100 + i*50);
        m_graphicAnswers[i].setCharacterSize(15);
        m_graphicAnswers[i].setFillColor(sf::Color::White);
    }
}

void Questions::start()
{

}

void Questions::update(sf::Window& window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
    {
        m_score = 1;
        m_end = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
    {
        m_score = 2;
        m_end = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
    {
        m_score = 3;
        m_end = true;
    }
}

void Questions::loadTextures()
{
    if(!m_bgTexture.loadFromFile("resources/textures/Brick.png"))
    {
        std::cout << "Fail load brick" << std::endl;
    }
    if(!m_font.loadFromFile("resources/font/unispace.ttf"))
    {
        std::cout << "Fail load font" << std::endl;
    }
}

void Questions::loadStrings()
{
    m_question = "Test ?";
    m_graphicQuestion.setString(m_question);
    
    m_answers.push_back("reponse 1");
    m_answers.push_back("reponse 2");
    m_answers.push_back("reponse 3");

    for(uint i = 0; i < m_answers.size(); i++)
    {
        m_graphicAnswers.push_back(sf::Text());
        m_graphicAnswers[i].setString(m_answers[i]);
    }
}


void Questions::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(m_bg, states);
    window.draw(m_graphicQuestion, states);
    for(uint i = 0; i < m_graphicAnswers.size(); i++)
    {
        window.draw(m_graphicAnswers[i], states);
    }
}