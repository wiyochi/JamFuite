#include "storyTeller.hpp"

void StoryTeller::insertNode(int nodeId)
{
    Node *n = new Node(nodeId);
    storyLine.insert(n);
}

Node* StoryTeller::getNode(int nodeId)
{
    Node* result = nullptr;

    for(Node* n : storyLine)
    {
        if(n->getNodeId() == nodeId)
        {
            result = n;
            break;
        }
    }

    return result;
}