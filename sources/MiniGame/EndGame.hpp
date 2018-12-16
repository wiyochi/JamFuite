#if !defined(_END_GAME_)
#define _END_GAME_

#include "MiniGame.hpp"
#include "Readers/ReaderEndGame.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class EndGame : public MiniGame
{
public:
    EndGame(int id);

    static ReaderEndGame reader;
    virtual void start();
    virtual void update(sf::Window& window);

private:
    int m_id;
    std::string m_message;
    std::vector<int> m_color;
    sf::Text m_graphicMessage;
    sf::Font m_font;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

} ;

#endif // _END_GAME_