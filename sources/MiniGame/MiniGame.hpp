#ifndef _MINIGAME_
#define _MINIGAME_

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class MiniGame : public sf::Drawable
{
public:
    MiniGame();
    virtual void start() = 0;
    virtual void update(sf::Window& window) = 0;
    bool end();
    int getScore();

protected:
    int m_id;
    bool m_end;
    int m_score;
    sf::Texture m_bgTexture;
    sf::Sprite m_bg;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};

#endif // !_MINIGAME_