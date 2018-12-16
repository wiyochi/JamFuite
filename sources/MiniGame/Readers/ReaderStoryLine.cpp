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

    std::vector<std::string> keys;

    for (auto it = d.MemberBegin(); it != d.MemberEnd(); it++)
    {
        std::string key = it->name.GetString();
        keys.push_back(key);

        storyTeller.createNode(std::stoi(key));
    }

    for(std::string k : keys)
    {
        rapidjson::Value &tab = d[k.c_str()];
        std::vector<int> values;

        if (!tab.IsNull())
        {
            //Remplissage tableau des nextNodes
            for (rapidjson::SizeType i = 0; i < tab.Size(); i++)
            {
                values.push_back(tab[i].GetInt());
            }
        }

        storyTeller.createDependencies(std::stoi(k), values);
    }

/*
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

        std::cout << "cle: " << key << " :" << std::endl;
        for(int i : values)
        {
            std::cout << "\t" << values[i] << std::endl;
        }
        std::cout << std::endl;

        storyTeller.createDependencies(std::stoi(key), values);
    }*/
}