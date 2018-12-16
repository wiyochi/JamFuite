#include "ReaderStoryLine.hpp"

void ReaderStoryLine::loadAndInjectData(std::string fileName, StoryTeller &storyTeller)
{
    std::ifstream file(fileName, std::ios::in);
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

    for (auto it = d.MemberBegin(); it != d.MemberEnd(); it++)
    {
        std::string key = it->name.GetString();
        rapidjson::Value &tab = it->value;
        std::vector<int> values = {};

        if (!tab.IsNull())
        {
            //Remplissage tableau des nextNodes
            for (rapidjson::SizeType i = 0; i < tab.Size(); i++)
            {
                values.push_back(tab[i].GetInt());
            }
        }

        storyTeller.createNodeAndDependencies(std::stoi(key), values);
    }
}