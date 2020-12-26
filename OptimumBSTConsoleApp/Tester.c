/** Optimum Binary Search Tree
 * Created by: Christian Tapnio
 * Program that utilizes Binary Tree concepts and alogorithms for sorting and generating Optimum BST
 * Following is the step-by-step guide to the solution of Assignment 4. Several of the steps have already been
completed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

#define MAXNODE 10 // Warning! make sure MAXNODE is always set smaller than the range
#define RANGE 100 //for distinct set of random integers
#define OFFSET 10


int main() {
    char word[MaxWordSize + 1];
    int data;
    FILE *in = fopen("..//data//randomintegers.txt", "w");
    FILE *out = fopen("..//data//normalbst.txt", "w");


    BinaryTree bst;
    bst.root = NULL;

    while (fscanf(in, "%s", word) != EOF) {
        data = atoi(word);
        if (bst.root == NULL)
            bst.root = newTreeNode(newNodeData(data));
        else {
            TreeNodePtr node = findOrInsert(bst, newNodeData(data));
        }
    }

    serialize(bst.root, out);


    FILE *sBst = fopen("..//data//sortedBST.txt", "w");
    inOrder(sBst, bst.root);


    fclose(out);
    fclose(sBst);


    sBst = fopen("..//data//sortedBST.txt", "r");


    int i;
    TreeNodePtr lastNode[MAXNODE];
    for (i = 0; i < MAXNODE; i++)
        lastNode[i] = NULL;

    FILE *oBst = fopen("..//data//optimumBST.txt", "w");
    BinaryTree obst;
    while (fscanf(sBst, "%d", &i) == 1)
        insertBestBST(i, lastNode);

    obst.root = finalizeBestBST(lastNode);

    serialize(obst.root, oBst);
    fclose(oBst);
    fclose(sBst);

} // end main
