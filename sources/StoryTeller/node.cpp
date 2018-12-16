#include "node.hpp"

Node::Node(int nodeId) : nodeId(nodeId) {}

int Node::getNodeId() const
{
    return nodeId;
}

std::vector<Node *> &Node::getNodes()
{
    return nextNodes;
}

Node *Node::getNode(int nodeId)
{
    return (nodeId-1) < nextNodes.size() ? nextNodes[nodeId-1] : nullptr;
}

bool Node::operator==(const Node &n)
{
    return getNodeId() == n.getNodeId();
}