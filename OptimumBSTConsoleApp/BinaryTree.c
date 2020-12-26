// Optimum Binary Search Tree
// Created by: Christian Tapnio
// Program that utilizes Binary Tree concepts and alogorithms for sorting and generating Optimum BST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

NodeData newNodeData(int n) {
    NodeData temp;
    temp.num = n;
    return temp;
} //end newNodeData

TreeNodePtr newTreeNode(NodeData d) {
    TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
    p->data = d;
    p->left = p->right = NULL;
    return p;
} //end newTreeNode

TreeNode *buildTree(FILE *in) {
    char str[MaxWordSize + 1];
    fscanf(in, "%s", str);
    if (strcmp(str, "@") == 0) return NULL;
    TreeNode *p = (TreeNode *) malloc(sizeof(TreeNode));
    p->data.num = atoi(str);
    p->left = buildTree(in);
    p->right = buildTree(in);
    return p;
} //end buildTree
TreeNodePtr findOrInsert(BinaryTree bt, NodeData d) {
    //searches for d; if found, return pointer to node containing d
    //else insert a node containing d and return pointer to new node
    TreeNodePtr newTreeNode(NodeData);

    if (bt.root == NULL) return newTreeNode(d);
    TreeNodePtr curr = bt.root;
    int cmp;
    while ((cmp = d.num - curr->data.num) != 0) {
        if (cmp < 0) { //try left
            if (curr->left == NULL) return curr->left = newTreeNode(d);
            curr = curr->left;
        } else { //try right
            if (curr->right == NULL) return curr->right = newTreeNode(d);
            curr = curr->right;
        }
    }
    //d is in the tree; return pointer to the node
    return curr;
} //end findOrInsert

void inOrder(FILE *out, TreeNodePtr node) {
    if (node != NULL) {
        inOrder(out, node->left);
        fprintf(out, " %d", node->data.num);
        inOrder(out, node->right);
    }
} //end inOrder

void serialize(TreeNode *root, FILE *fp) // this is a simplified version of serialize for integer type data
{
    // If current node is NULL, store marker
    if (root == NULL) {
        fprintf(fp, "%c ", MARKER);
        return;
    }
    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->data.num); // if the data is an integer
    serialize(root->left, fp);
    serialize(root->right, fp);
}

//From BestBST.c

int getNodeLevel(int n) {
    //comments required
    int level = 0;
    while (n % 2 == 0) {
        level++;
        n /= 2;
    }
    return level;
}

void insertBestBST(int n, TreeNodePtr lastNode[]) {
    int getNodeLevel(int);
    TreeNodePtr newTreeNode(NodeData);
    NodeData newNodeData(int);
    static int numNodes = 0;

    TreeNodePtr p = newTreeNode(newNodeData(n));
    numNodes++;
    int level = getNodeLevel(numNodes);
    // comments required
    //
    if (level > 0) p->left = lastNode[level - 1];
    // comments required
    if (lastNode[level + 1] != NULL)
        if (lastNode[level + 1]->right == NULL)
            lastNode[level + 1]->right = p;
    // the current node is the last node processed at this level
    lastNode[level] = p;
} //end insertBestBST

TreeNodePtr finalizeBestBST(TreeNodePtr lastNode[]) {
    int m, n = MAX_HEIGHT - 1;
    // find the last entry in lastNode that is non-null
    // this is the root
    while (n > 0 && lastNode[n] == NULL) n--;
    TreeNodePtr root = lastNode[n];

    while (n > 0) {
        //comments required
        if (lastNode[n]->right != NULL) n--;
        else {
            // comments required
            TreeNodePtr tn = lastNode[n]->left;
            m = n - 1;
            // comments required
            while (m >= 0 && tn == lastNode[m]) {
                tn = tn->right;
                m--;
            }
            if (m >= 0) lastNode[n]->right = lastNode[m];
            n = m;
        } //end else
    } //end while
    return root;
} //end finalizeBST

