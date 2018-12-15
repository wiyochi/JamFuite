#ifndef _QTE_
#define _QTE_

#include <SFML/Graphics.hpp>
#include "MiniGame.hpp"

class QTE : public MiniGame
{
public:
    QTE();
    void start();
    void update(sf::Window& window);

private:
    sf::Clock m_clock;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif // !_QTE_