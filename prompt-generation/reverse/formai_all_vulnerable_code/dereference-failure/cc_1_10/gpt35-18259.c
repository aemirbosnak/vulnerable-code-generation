//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Data Structure
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Insert a new node
struct Node *insert(struct Node *node, int data) {
    if(node == NULL) {
        return newNode(data);
    } else {
        if(data <= node->value) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

// Print the tree using a Breadth First Search Approach
void printBFS(struct Node *root) {
    printf("Printing Tree using BFS Approach...\n");
    int queue[MAX], front=0, rear=0;
    struct Node *node = root;
    if(node == NULL) {
        return;
    }
    queue[rear++] = node->value;

    while(front < rear) {
        node = newNode(queue[front]);
        front++;

        if(node->left != NULL) {
            queue[rear++] = node->left->value;
        }
        if(node->right != NULL) {
            queue[rear++] = node->right->value;
        }

        printf("%d ", node->value);
    }
    printf("\n");
}

// Main function
int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printBFS(root);

    return 0;
}

// C Data Structure Visualization...
// .__                                                    
// |__| ____   ____   _____ _____ _______ ___.__. ____  ___.__.
// |  |/ ___\ /    \ /  ___\\__  \\_  __ <   |  |/    \/  <   | 
// |  / /_/  >   |  \\___ \ / __ \|  | \/   |  |   |  \  \___  |
// |__\___  /|___|  /____  (____  /__|  |___|  |___|  / /\___  /
//     /_____/      \/     \/    \/            \/  \/     \/