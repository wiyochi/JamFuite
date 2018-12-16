
#if !defined(STORY_TELLER__H)
#define STORY_TELLER__H

#include "node.hpp"

#include <algorithm>
#include <vector>
#include <vector>

class StoryTeller
{
  std::vector<Node *> storyLine;

public:
  Node *createNode(int);
  Node *getNode(int);
  void createNodeAndDependencies(int, std::vector<int>);
  void createDependencies(int, std::vector<int>);
  std::vector<Node *> accesCaca();
  ~StoryTeller();
};

#endif // STORY_TELLER__H