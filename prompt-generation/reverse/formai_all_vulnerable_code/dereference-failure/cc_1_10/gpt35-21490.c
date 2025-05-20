//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Cyberpunk struct
typedef struct CyberPunk{
    int val;
    struct CyberPunk *left;
    struct CyberPunk *right;
} CyberPunk;

CyberPunk* createCyberPunkNode(int val){
    CyberPunk* node = (CyberPunk*) malloc(sizeof(CyberPunk));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

CyberPunk* insertCyberPunkNode(CyberPunk* root, int val){
    if(!root){
        root = createCyberPunkNode(val);
        return root;
    }
    if(val < root -> val){
        root -> left = insertCyberPunkNode(root -> left, val);
    }else if(val > root -> val){
        root -> right = insertCyberPunkNode(root -> right, val);
    }
    return root;
}

CyberPunk* generateCyberPunkTree(int n){
    CyberPunk* root = NULL;
    srand(time(0));
    for(int i = 0; i < n; i++){
        int val = rand() % 50 + 1;
        root = insertCyberPunkNode(root, val);
    }
    return root;
}

CyberPunk* findCyberPunkNode(CyberPunk* root, int val){
    if(root == NULL || root -> val == val){
        return root;
    }
    if(root -> val > val){
        return findCyberPunkNode(root -> left, val);
    }
    return findCyberPunkNode(root -> right, val);
}

// Function to print the Tree
void printCyberPunkTree(CyberPunk* root) {
    if(root == NULL){
        return;
    }
    printf("( val = %d ", root -> val);
    if(root -> left){
        printf(" left = ");
        printCyberPunkTree(root -> left);
    }
    if(root -> right){
        printf(" right = ");
        printCyberPunkTree(root -> right);
    }
    printf(" )");
}

int main(){
    int n = 10;
    CyberPunk* root = generateCyberPunkTree(n);
    printf("\n\n** CyberPunk Tree **\n\n");
    printCyberPunkTree(root);
    int val = 10;
    CyberPunk* found = findCyberPunkNode(root, val);
    if(found){
        printf("\n\nThe CyberPunk with value %d was found!", found -> val);
    }else{
        printf("\n\nThe CyberPunk with value %d was not found!", val);
    }
    return 0;
}