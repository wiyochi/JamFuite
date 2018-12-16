#ifndef _READER_END_GAME_
#define _READER_END_GAME_

#include <rapidjson/document.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ReaderEndGame
{
public:
    ReaderEndGame();
    void read(std::string filename);
    void debug();
    std::string getName();
    std::string getMessage();
    std::vector<int> getColor();
    std::string getBgPath();

private:
    std::string m_name;
    std::string m_message;
    std::vector<int> m_color;
    std::string m_bgPath;
};


#endif // !_READER_END_GAME_