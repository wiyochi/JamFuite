
#if !defined(STORY_TELLER__H)
#define STORY_TELLER__H

#include "node.hpp"

#include <algorithm>
#include <vector>
#include <set>

class StoryTeller 
{
    std::set<Node*> storyLine;

    public:
        void insertNode(int);
        Node* getNode(int);
};

#endif // STORY_TELLER__H