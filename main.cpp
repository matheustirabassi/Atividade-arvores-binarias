#include <iostream>
#include <stdio.h>
using namespace std;


struct tree {
    char info;
    struct tree* left;
    struct tree* right;
};
typedef struct tree Tree;

tree *createTreeNode(char value, tree *left, tree *right) {
    tree *n = (tree *) malloc(sizeof(tree));
    if(n == NULL) {
        fprintf(stderr, "memória esgotada na função %s - (%d)\n", __FUNCTION__, __LINE__);
        exit(0);
    }
    n->info = value;
    n->left = left;
    n->right = right;
    return n;
}
void destroyTreeNode(tree *node) {
    free(node);
}

tree* createExample() {
    Tree *a0 = createTreeNode('a', NULL, NULL);
    Tree *a1 = createTreeNode('b', NULL, NULL);
    Tree *a2 = createTreeNode('c', NULL, NULL);
    Tree *a3 = createTreeNode('d', NULL, NULL);

    Tree *a4 = createTreeNode('e', a0, NULL);
    Tree *a5 = createTreeNode('f', a1, a2);
    Tree *a6 = createTreeNode('g', a3, a4);

    Tree *raiz = createTreeNode('M', a5, a6);

    return raiz;
}

void printCenter (Tree* a) {
    if (a != NULL) {
        printf("%c ", a->info); /* mostra raiz */
        printCenter(a->left); /* mostra sae */
        printCenter(a->right); /* mostra sad */
    }
    // cout << "This tree is NULL" << endl;
}
void printPostOrder(Tree *root){
    if(root != NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%c, ", root->info);
    }
}

void printSimetricOrder(Tree *root){
    if(root != NULL){
        printSimetricOrder(root->left);
        printf("%c, ", root->info);
        printSimetricOrder(root->right);
    }
}
void printPreOrder(Tree *root){
    if(root != NULL){
        printf("%c, ", root->info);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int treeHeight(Tree *root){
    if(root == NULL){
        return -1;
    }
    else{
        int heightLeft = treeHeight(root->left);
        int heightRight = treeHeight(root->right);
        if(heightLeft < heightRight){
            return heightRight + 1;
        }
        else{
            return heightLeft + 1;
        }
    }
}
int main() {
    Tree *tree1 = createExample();
    cout << "---------TESTE 1 : Pré-Ordem---------------" << endl;
    printPreOrder(tree1);
    cout << endl << endl;
    cout << "---------TESTE 2 : Ordem simétrica----------" << endl;
    printSimetricOrder(tree1);
    cout << endl << endl;
    cout << "---------TESTE 3 : Pós-ordem----------------" << endl;
    printPostOrder(tree1);
    cout << endl << endl;

    cout << "---------TESTE 4 : Altura da árvore----------" << endl;
    cout << treeHeight(tree1);
    cout << endl << endl;
    return 0;
}
