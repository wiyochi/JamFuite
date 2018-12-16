#include "node.hpp"

Node::Node(int nodeId) : nodeId(nodeId) {}

int Node::getNodeId() const
{
    return nodeId;
}

std::set<Node *> &Node::getNodes()
{
    return nextNodes;
}

Node *Node::getNode(int nodeId)
{
    std::set<Node *>::iterator result;

    result = std::find_if(nextNodes.begin(), nextNodes.end(), [&nodeId](Node *n) -> bool {
        return n->getNodeId() == nodeId;
    });

    return result == nextNodes.end() ? nullptr : *result;
}

bool Node::operator==(const Node &n)
{
    return getNodeId() == n.getNodeId();
}