#ifndef _QUESTIONS_
#define _QUESTIONS_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MiniGame.hpp"
#include "Readers/ReaderQuestions.hpp"

class Questions : public MiniGame
{
public:
    Questions(int id);
    void start();
    void update(sf::Window& window);
    void loadTextures();
    void loadStrings();

    static ReaderQuestions m_reader;
    static bool m_keyPressed;

private:
    int m_id;
    sf::Font m_font;
    std::vector<std::string> m_answers;
    std::vector<sf::Text> m_graphicAnswers;
    std::string m_question;
    sf::Text m_graphicQuestion;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};

#endif // !_QUESTIONS_