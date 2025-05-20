//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
};

/* function to create a node */
struct Node* createNode(int key){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* function to insert a node */
struct Node* insertNode(struct Node* node, int key){
    if (node == NULL)
        return createNode(key);
 
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
 
    return node;
}

/* function to search for a node */
struct Node* search(struct Node* node, int key){
    if (node == NULL || node->key == key)
       return node;
    
    if (node->key < key)
       return search(node->right, key);
    
    return search(node->left, key);
}

/* function to print the tree */
void printTree(struct Node* node){
    if(node){
        printTree(node->left);
        printf("%d ", node->key);
        printTree(node->right);
    }
}

/* function to generate random nodes values */
int generateRandom(){
    int n = rand() % 1000 + 1;
    return n;
}

int main(){
    int i, num, searchKey;
    struct Node* root = NULL;
    srand(time(NULL));

    /* insert random nodes into the tree */
    for(i=0; i<50; i++){
        num = generateRandom();
        insertNode(root, num);
    }

    /* print the tree */
    printf("\nThe tree is:\n");
    printTree(root);

    /* search for a node */
    printf("\nEnter a node to search: ");
    scanf("%d", &searchKey);
    struct Node* foundNode = search(root, searchKey);
    
    /* if node is found, print its value */
    if(foundNode)
        printf("\nNode found. It's value is: %d\n", foundNode->key);
    else
        printf("\nNode not found.\n");

    return 0;
}