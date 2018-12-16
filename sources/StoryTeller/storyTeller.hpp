
#if !defined(STORY_TELLER__H)
#define STORY_TELLER__H

#include "node.hpp"

#include <algorithm>
#include <vector>
#include <set>

class StoryTeller
{
  std::set<Node *> storyLine;

public:
  Node *createNode(int);
  Node *getNode(int);
  void createNodeAndDependencies(int, std::vector<int>);
  std::set<Node *> accesCaca();
  ~StoryTeller();
};

#endif // STORY_TELLER__H