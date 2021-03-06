#if !defined(NODE__H)
#define NODE__H

#include <vector>
#include <algorithm>

class Node
{
  int nodeId;
  std::vector<Node *> nextNodes;

public:
  Node(int);
  int getNodeId() const;
  std::vector<Node *> &getNodes(); //Tous les noeuds partants de ce noeud
  Node *getNode(int);           //Obtenir le noeud n°X
  bool operator==(const Node &);
};

#endif // NODE__H
