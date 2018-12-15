#if !defined(NODE__H)
#define NODE__H

#include <vector>

class Node
{ 
    int nodeId;
    std::vector<Node*> nextNodes;

    public:
        Node(int);  
        int getNodeId();
        std::vector<Node*> getNodes();
};

#endif // NODE__H
