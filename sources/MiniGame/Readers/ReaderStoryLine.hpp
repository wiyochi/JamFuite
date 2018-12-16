#if !defined(READER_STORY_LINE__H)
#define READER_STORY_LINE__H

#include <rapidjson/document.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "../../StoryTeller/storyTeller.hpp"

class ReaderStoryLine
{
public:
  void loadAndInjectData(std::string, StoryTeller &);
};

#endif // READER_STORY_LINE__H
