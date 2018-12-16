#include "ReaderEndGame.hpp"

ReaderEndGame::ReaderEndGame()
{
}

void ReaderEndGame::read(std::string filename)
{
    std::ifstream file(filename, std::ios::in);
    std::string str;

    if (file)
    {
        char c;
        while (file.get(c))
            str.push_back(c);

        file.close();
    }
    else
    {
        std::cout << "Erreur load file" << std::endl;
    }

    const char *json = str.c_str();
    rapidjson::Document d;
    d.Parse(json);

    m_message = d["message"].GetString();
    m_name = d["name"].GetString();
    m_bgPath = d["bgpath"].GetString();

    rapidjson::Value &tab = d["color"];
    for (rapidjson::SizeType i = 0; i < tab.Size(); i++)
    {
        m_color.push_back(tab[i].GetInt());
    }

    debug();
}

void ReaderEndGame::debug()
{
    std::cout << "name: " << m_name << std::endl;
    std::cout << "message: " << m_message << std::endl;
    std::cout << "bgpath: " << m_bgPath << std::endl;
    for(int i = 0; i < m_color.size(); i++)
    {
        std::cout << m_color[i];
    }
    std::cout << std::endl;
}

std::string ReaderEndGame::getName()
{
    return m_name;
}

std::string ReaderEndGame::getMessage()
{
    return m_message;   
}

std::vector<int> ReaderEndGame::getColor()
{
    return m_color;
}

std::string ReaderEndGame::getBgPath()
{
    return m_bgPath;
}