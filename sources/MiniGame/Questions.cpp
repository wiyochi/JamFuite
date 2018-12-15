#include "Questions.hpp"

ReaderQuestions Questions::m_reader;

Questions::Questions(int id) : m_id(id)
{
    std::stringstream ss;
    ss << "resources/jsonGame/" << m_id << ".json";
    std::string str = ss.str();

    std::cout << "FILE: " << str << std::endl;

    m_reader.read(str);

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
    if(!m_bgTexture.loadFromFile(m_reader.getBgPath()))
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
    m_question = m_reader.getQuestion();
    m_graphicQuestion.setString(m_question);

    for(int i = 0; i < m_reader.nbAnswer(); i++)
    {
        m_answers.push_back(m_reader.getAnswer(i));
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