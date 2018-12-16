#include "storyTeller.hpp"
#include <iostream>

Node *StoryTeller::createNode(int nodeId)
{
    Node *n = new Node(nodeId);
    storyLine.push_back(n);

    return n;
}

Node *StoryTeller::getNode(int nodeId)
{
    return nodeId < storyLine.size() ? storyLine[nodeId-1] : nullptr;
}

std::vector<Node *> StoryTeller::accesCaca()
{
    return storyLine;
}

void StoryTeller::createNodeAndDependencies(int node, std::vector<int> nextNodes)
{
    std::vector<Node *>::iterator it;

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

        n->getNodes().push_back(tmp); //On insere le ptr dans la liste de noeuds suivants
    }
}

void StoryTeller::createDependencies(int indexNode, std::vector<int> indexNextNodes)
{
    for(int i : indexNextNodes)
    {
        storyLine[indexNode-1]->getNodes().push_back(storyLine[i-1]);
    }
}

StoryTeller::~StoryTeller()
{
    std::vector<Node *>::iterator it;

    for (it = storyLine.begin(); it != storyLine.end(); it++)
    {
        delete *it;
    }
}
