#ifndef _READER_QUESTIONS_
#define _READER_QUESTIONS_

#include <rapidjson/document.h>
#include <rapidjson/reader.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ReaderQuestions
{
public:
    ReaderQuestions();
    void read(std::string filename);
    void debug();
    std::string getQuestion();
    std::string getAnswer(int index);
    int nbAnswer();
    std::string getBgPath();

private:
    std::string m_name;
    std::string m_question;
    std::vector<std::string> m_answers;
    std::string m_bgPath;
};


#endif // !_READER_QUESTIONS_