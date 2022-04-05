#ifndef RBTREE_H
#define RBTREE_H

// rbtree.h - declaration file for Red-Black Tree class

using namespace std ;

// Note: the following are _not_ used in Red-Black Trees
#define NULL 0
#define NIL 0

typedef int KeyType ; 

typedef class Node * NodePtr ;
// Note: One _could_ replace all "NodePtr"s below with "Node *"


class Node {
public:
   KeyType key ;
   char color ;
   NodePtr p ;
   NodePtr left ;
   NodePtr right ;

   // Constructor
   Node( KeyType k = 0 ) : key(k) {}
} ;


class RBTree {
   // Utility for PrintTree(); could be made public if needed externally
   void inorderTreeWalk( NodePtr x ) ; 

public:
   NodePtr root ;
   NodePtr nil ;

   // Constructor
   RBTree() ;

   // RBTree "dictionary" functions
   void RBinsert( NodePtr z ) ;
   void RBdelete( NodePtr z ) ;
   NodePtr RBsearch( NodePtr x, KeyType key ) ;

   // Other RBTree accessors - not directly used here
   NodePtr Tree_minimum( NodePtr x ) ;
   NodePtr Tree_successor( NodePtr x ) ;

   // Other RBTree mutators - not directly used here
   // But declared here if it is desired to debug them with cmdint.cpp
   void leftRotate( NodePtr x ) ;
   void rightRotate( NodePtr x ) ;
   void insertFixup( NodePtr z ) ;
   void deleteFixup( NodePtr x ) ;
   void RBTransplant( NodePtr u, NodePtr v ) ;

   // RBTree display options
   void ShowTree( NodePtr x, int depth ) ;
   void PrintTree( ) ;
} ;

#endif
