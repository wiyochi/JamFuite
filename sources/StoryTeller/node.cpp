#include "node.hpp"

Node::Node(int nodeId) : nodeId(nodeId) {}

int Node::getNodeId()
{
    return nodeId;
}

std::vector<Node*> Node::getNodes()
{
    return nextNodes;
}