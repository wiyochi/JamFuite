#include "MiniGame.hpp"

MiniGame::MiniGame() :
    m_end(false),
    m_score(0)
{

}

bool MiniGame::end()
{
    return m_end;
}

int MiniGame::getScore()
{
    return m_score;
}