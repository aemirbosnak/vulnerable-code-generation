//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100
#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct Node {
    Record record;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Node* createNode(int id, const char* name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->record.id = id;
    strncpy(newNode->record.name, name, NAME_LENGTH);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(int id, const char* name) {
    Node *node = createNode(id, name);
    if (root == NULL) {
        root = node;
        return;
    }
    Node *current = root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (id < current->record.id) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (id < parent->record.id) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

Node* search(Node *node, int id) {
    if (node == NULL || node->record.id == id) {
        return node;
    }
    if (id < node->record.id) {
        return search(node->left, id);
    }
    return search(node->right, id);
}

void display(Node *node) {
    if (node) {
        display(node->left);
        printf("ID: %d, Name: %s\n", node->record.id, node->record.name);
        display(node->right);
    }
}

void freeTree(Node *node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);  // Read string with spaces
                insert(id, name);
                printf("Record Inserted!\n");
                break;
            case 2:
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                Node *result = search(root, id);
                if (result) {
                    printf("Found Record - ID: %d, Name: %s\n", result->record.id, result->record.name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                printf("\nAll Records:\n");
                display(root);
                break;
            case 4:
                freeTree(root);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}