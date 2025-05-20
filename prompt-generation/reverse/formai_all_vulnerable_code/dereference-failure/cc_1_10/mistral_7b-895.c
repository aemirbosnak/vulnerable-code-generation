//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME_LENGTH 50
#define NODE_SIZE sizeof(struct Node)
struct Node {
    int key;
    char name[MAX_NAME_LENGTH];
    struct Node *left, *right;
};
struct Node *root = NULL;
void insertNode(int key, const char *name) {
    struct Node *newNode = (struct Node *) malloc(NODE_SIZE);
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
    } else {
        struct Node *currentNode = root;
        struct Node *parentNode;
        while (1) {
            if (key < currentNode->key) {
                parentNode = currentNode;
                currentNode = currentNode->left;
                if (currentNode == NULL) {
                    parentNode->left = newNode;
                    break;
                }
            } else if (key > currentNode->key) {
                parentNode = currentNode;
                currentNode = currentNode->right;
                if (currentNode == NULL) {
                    parentNode->right = newNode;
                    break;
                }
            } else {
                // Key already exists in the tree, do not insert it again
                free(newNode);
                return;
            }
        }
    }
}
void printTreeInOrder(struct Node *node) {
    if (node == NULL) {
        return;
    }
    printTreeInOrder(node->left);
    printf("%d %s\n", node->key, node->name);
    printTreeInOrder(node->right);
}
int main() {
    const char names[][MAX_NAME_LENGTH] = {
        "Dr. Watson", "Prof. Moriarty", "Inspector Lestrade", "Mrs. Hudson",
        "Sherlock Holmes", "Mycroft Holmes", "Mrs. Hudson's Nephew", "James Moriarty's Henchman"
    };
    int keys[] = {11, 23, 4, 15, 25, 8, 28, 12, 17, 30};
    int i;
    for (i = 0; i < 10; i++) {
        insertNode(keys[i], names[i]);
    }
    printf("Binary Search Tree:\n");
    printTreeInOrder(root);
    return 0;
}