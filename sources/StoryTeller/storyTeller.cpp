#include "storyTeller.hpp"

void StoryTeller::createNode(int nodeId)
{
    Node *n = new Node(nodeId);
    storyLine.insert(n);
}

Node *StoryTeller::getNode(int nodeId)
{
    std::set<Node *>::iterator result;

    result = std::find_if(storyLine.begin(), storyLine.end(), [&nodeId](Node *n) -> bool {
        return n->getNodeId() == nodeId;
    });

    return result == storyLine.end() ? nullptr : *result;
}

std::set<Node *> StoryTeller::accesCaca()
{
    return storyLine;
}

StoryTeller::~StoryTeller()
{
    std::set<Node *>::iterator it;

    for (it = storyLine.begin(); it != storyLine.end(); it++)
    {
        delete *it;
    }
}