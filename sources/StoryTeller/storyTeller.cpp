#include "storyTeller.hpp"
#include <iostream>

Node *StoryTeller::createNode(int nodeId)
{
    Node *n = new Node(nodeId);
    storyLine.insert(n);

    return n;
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

void StoryTeller::createNodeAndDependencies(int node, std::vector<int> nextNodes)
{
    std::set<Node *>::iterator it;

    it = std::find_if(storyLine.begin(), storyLine.end(), [node](Node *n) -> bool {
        return n->getNodeId() == node;
    });

    Node *n;

    if (it == storyLine.end()) //Le noeud n'existe pas
        n = createNode(node);
    else //Le noeud existe
        n = *it;

    Node *tmp; //Noeud temporaire pour stocker le noeud suivant à créer
    for (auto nextNode : nextNodes)
    {
        it = std::find_if(storyLine.begin(), storyLine.end(), [nextNode](Node *n) -> bool {
            return n->getNodeId() == nextNode;
        });

        if (it == storyLine.end()) //Le noeud n'existe pas
            tmp = createNode(nextNode);
        else //Le noeud existe
            tmp = *it;

        n->getNodes().insert(tmp); //On insere le ptr dans la liste de noeuds suivants
    }
}

StoryTeller::~StoryTeller()
{
    std::set<Node *>::iterator it;

    for (it = storyLine.begin(); it != storyLine.end(); it++)
    {
        delete *it;
    }
}
