#include "ReaderQuestions.hpp"

ReaderQuestions::ReaderQuestions()
{

}

void ReaderQuestions::read(std::string filename)
{
    std::ifstream file(filename, std::ios::in);
    std::string str;

    m_answers.clear();

    if(file)
    {
        char c;
        while(file.get(c))
            str.push_back(c);

        file.close();
    }
    else
    {
        std::cout << "Erreur load file" << std::endl;
    }

    const char * json = str.c_str();

    rapidjson::Document d;
    d.Parse(json);

    m_name = d["name"].GetString();
    m_question = d["question"].GetString();
    m_bgPath = d["bgpath"].GetString();

    rapidjson::Value& tab = d["answers"];
    for(rapidjson::SizeType i = 0; i < tab.Size(); i++)
    {
        m_answers.push_back(tab[i].GetString());
    }

}

void ReaderQuestions::debug()
{
    std::cout << "name: " << m_name << std::endl;
    std::cout << "question: " << m_question << std::endl;
    std::cout << "answers: " << std::endl;
    for(uint i = 0; i < m_answers.size(); i++)
    {
        std::cout << m_answers[i] << std::endl;
    }
    std::cout << "bgpath: " << m_bgPath << std::endl;
}

std::string ReaderQuestions::getQuestion()
{
    return m_question;
}

std::string ReaderQuestions::getAnswer(int index)
{
    return m_answers[index];
}

int ReaderQuestions::nbAnswer()
{
    return m_answers.size();
}

std::string ReaderQuestions::getBgPath()
{
    return m_bgPath;
}