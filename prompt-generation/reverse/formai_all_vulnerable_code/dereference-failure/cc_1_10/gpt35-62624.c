//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256
#define MAXDATA 100

typedef struct IndexNode {
    char keyword[MAXLEN];
    int data[MAXDATA];
    int count;
    struct IndexNode *left, *right;
} IndexNode;

void insert(IndexNode **root, char *keyword, int data) {
    IndexNode *node;
    
    if (*root == NULL) {
        node = (IndexNode *) malloc(sizeof(IndexNode));
        strcpy(node->keyword, keyword);
        node->data[0] = data;
        node->count = 1;
        node->left = node->right = NULL;
        *root = node;
    }
    else {
        int compare = strcmp(keyword, (*root)->keyword);
        
        if (compare < 0) {
            insert(&((*root)->left), keyword, data);
        }
        else if (compare > 0) {
            insert(&((*root)->right), keyword, data);
        }
        else {
            (*root)->data[(*root)->count++] = data;
        }
    }
}

void search(IndexNode *root, char *keyword) {
    if (root != NULL) {
        int compare = strcmp(keyword, root->keyword);
        if (compare < 0) {
            search(root->left, keyword);
        }
        else if (compare > 0) {
            search(root->right, keyword);
        }
        else {
            printf("%s:", keyword);
            for (int i = 0; i < root->count; i++) {
                printf(" %d", root->data[i]);
            }
            printf("\n");
        }
    }
}

int main() {
    IndexNode *root = NULL;
    char keyword[MAXLEN];
    int data;
    
    while (scanf("%s %d", keyword, &data) == 2) {
        insert(&root, keyword, data);
    }
    
    printf("Enter a keyword to search:\n");
    scanf("%s", keyword);
    search(root, keyword);
    
    return 0;
}