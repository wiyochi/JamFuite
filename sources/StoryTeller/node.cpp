#include "node.hpp"

Node::Node(int nodeId) : nodeId(nodeId) {}

int Node::getNodeId()
{
    return nodeId;
}

std::vector<Node *> Node::getNodes()
{
    return nextNodes;
}

Node *Node::getNode(int nodeId)
{
    std::vector<Node *>::iterator result;

    result = std::find_if(nextNodes.begin(), nextNodes.end(), [&nodeId](Node *n) -> bool {
        return n->getNodeId() == nodeId;
    });

    return result == nextNodes.end() ? nullptr : *result;
}