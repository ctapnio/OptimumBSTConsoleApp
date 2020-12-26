// Optimum Binary Search Tree
// Created by Christian on 2020-12-09.
// Program that utilizes Binary Tree concepts and alogorithms for sorting and generating Optimum BST

#ifndef CHRISTIANTAPNIOASSIGN04_BINARYTREE_H
#define CHRISTIANTAPNIOASSIGN04_BINARYTREE_H
#define MARKER '@'
#define MaxWordSize 10
#define MAX_HEIGHT 10 // max height for an optimum BST, total number of nodes must be less than 2 ^ (MAX_HEIGHT +1) - 1

typedef struct {
    int num;
} NodeData;

typedef struct treeNode_def {
    NodeData data;
    struct treeNode_def *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct {
    TreeNode* root;
} BinaryTree;

TreeNode* buildTree(FILE *);
NodeData newNodeData(int n);
TreeNodePtr newTreeNode(NodeData d);
TreeNodePtr findOrInsert(BinaryTree bt, NodeData d);

void inOrder(FILE * out, TreeNodePtr node);

// OptimumBST functions
int getNodeLevel(int n);
void insertBestBST(int n, TreeNodePtr lastNode[]);
TreeNodePtr finalizeBestBST(TreeNodePtr lastNode[]);


void serialize(TreeNode* root, FILE *fp);
// This function stores a tree in a file pointed by fp

#endif //CHRISTIANTAPNIOASSIGN04_BINARYTREE_H
