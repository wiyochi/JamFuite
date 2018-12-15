#ifndef _MINIGAME_
#define _MINIGAME_

#include <SFML/Graphics.hpp>

class MiniGame : public sf::Drawable
{
public:
    MiniGame();
    void start();
    void update();

private:
    

    void draw(sf::RenderWindow& window, sf::RenderStates states) const;

};

#endif // !_MINIGAME_