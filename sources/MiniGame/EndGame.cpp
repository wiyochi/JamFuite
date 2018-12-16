#include "EndGame.hpp"

ReaderEndGame EndGame::reader;

EndGame::EndGame(int id) : m_id(id)
{
    std::cout << "KALASH" << std::endl;
    std::stringstream ss;
    ss << "resources/scenes/" << m_id << ".json";
    std::string str = ss.str();

    reader.read(str);

    m_message = reader.getMessage();
    std::vector<int> c = reader.getColor();

    m_bgTexture.loadFromFile(reader.getBgPath());
    m_bg.setTexture(m_bgTexture);

    m_font.loadFromFile("resources/font/unispace.ttf");

    m_graphicMessage.setCharacterSize(15);
    m_graphicMessage.setFont(m_font);
    m_graphicMessage.setPosition(100, 50);
    m_graphicMessage.setFillColor(sf::Color(c[0], c[1], c[2]));
    m_graphicMessage.setString(m_message);
}

void EndGame::start()
{

}

void EndGame::update(sf::Window& window)
{

}

void EndGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    MiniGame::draw(target, states);
    target.draw(m_graphicMessage);
}