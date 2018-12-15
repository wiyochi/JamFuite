#ifndef _SPACE_INVADER_
#define _SPACE_INVADER_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "MiniGame.hpp"

class SpaceInvader : public MiniGame
{
public:
    SpaceInvader();
    void start();
    void update(sf::Window& window);
    bool end();

private:

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};

#endif // !_SPACE_INVADER_