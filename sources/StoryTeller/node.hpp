#if !defined(NODE__H)
#define NODE__H

#include <set>
#include <algorithm>

class Node
{
  int nodeId;
  std::set<Node *> nextNodes;

public:
  Node(int);
  int getNodeId() const;
  std::set<Node *> &getNodes(); //Tous les noeuds partants de ce noeud
  Node *getNode(int);           //Obtenir le noeud n°X
  bool operator==(const Node &);
};

#endif // NODE__H
