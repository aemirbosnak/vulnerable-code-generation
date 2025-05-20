//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

typedef struct Node {
    int key;
    float value;
    char symbol;
    struct Node *left, *right;
} Node;

Node* newNode(int key, float value, char symbol) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->symbol = symbol;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node *root, int key, float value, char symbol) {
    if (root == NULL)
        return newNode(key, value, symbol);

    if (key < root->key)
        root->left = insert(root->left, key, value, symbol);
    else if (key > root->key)
        root->right = insert(root->right, key, value, symbol);

    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("Key : %d, Value : %f, Symbol : %c\n", root->key, root->value, root->symbol);
    inorder(root->right);
}

Node* readTreeFromFile(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return NULL;
    }

    Node *root = NULL;
    char line[1024];
    while (fgets(line, sizeof(line), fd) != NULL) {
        char *token = strtok(line, ",");
        int key = atoi(token);

        token = strtok(NULL, ",");
        float value = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            root = insert(root, key, value, *token);
    }

    close(fd);
    return root;
}

int main() {
    srand(time(NULL));

    Node *tree = NULL;
    int choice;

    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Read Tree From File\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key, value;
                char symbol;
                printf("Enter key : ");
                scanf("%d", &key);
                printf("Enter value : ");
                scanf("%f", &value);
                printf("Enter symbol : ");
                scanf(" %c", &symbol);
                tree = insert(tree, key, value, symbol);
                break;
            }

            case 2: {
                printf("\nInorder Traversal:\n");
                inorder(tree);
                break;
            }

            case 3: {
                char filename[1024];
                printf("Enter filename : ");
                scanf("%s", filename);
                tree = readTreeFromFile(filename);
                printf("\nTree Read Successfully\n");
                break;
            }

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}