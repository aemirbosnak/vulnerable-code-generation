//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 10

typedef struct Node {
    int data;
    struct Node *forward[MAX_LEVEL];
} Node;

typedef struct SkipList {
    Node *header;
    int level;
} SkipList;

// Function to create a new node
Node* createNode(int level, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    for (int i = 0; i < MAX_LEVEL; i++) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

// Function to create a skip list
SkipList* createSkipList() {
    SkipList *list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = createNode(MAX_LEVEL, 0);
    return list;
}

// Function to generate a random level for a new node
int randomLevel() {
    int level = 1;
    while (rand() % 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Function to insert a new element into the skip list
void insert(SkipList *list, int data) {
    Node *current = list->header;
    Node *update[MAX_LEVEL];

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->data < data) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == NULL || current->data != data) {
        int newLevel = randomLevel();
        if (newLevel > list->level) {
            for (int i = list->level + 1; i <= newLevel; i++) {
                update[i] = list->header;
            }
            list->level = newLevel;
        }

        Node *newNode = createNode(newLevel, data);
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
        printf("Inserted %d into the skip list.\n", data);
    }
}

// Function to search for an element in the skip list
Node* search(SkipList *list, int data) {
    Node *current = list->header;
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->data < data) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return (current != NULL && current->data == data) ? current : NULL;
}

// Function to delete an element from the skip list
void delete(SkipList *list, int data) {
    Node *current = list->header;
    Node *update[MAX_LEVEL];

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->data < data) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL && current->data == data) {
        for (int i = 0; i <= list->level; i++) {
            if (update[i]->forward[i] != current) break;
            update[i]->forward[i] = current->forward[i];
        }

        free(current);

        while (list->level > 0 && list->header->forward[list->level] == NULL) {
            list->level--;
        }

        printf("Deleted %d from the skip list.\n", data);
    }
}

// Function to display the skip list
void displaySkipList(SkipList* list) {
    printf("Skip List:\n");
    for (int i = 0; i <= list->level; i++) {
        Node *current = list->header->forward[i];
        printf("Level %d: ", i);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->forward[i];
        }
        printf("\n");
    }
}

// Main function to demonstrate the skip list operations
int main() {
    SkipList *list = createSkipList();

    insert(list, 3);
    insert(list, 6);
    insert(list, 7);
    insert(list, 9);
    insert(list, 12);
    insert(list, 19);
    
    displaySkipList(list);

    delete(list, 3);
    displaySkipList(list);

    Node *found = search(list, 6);
    if (found) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Not found 6.\n");
    }

    found = search(list, 15);
    if (found) {
        printf("Found: %d\n", found->data);
    } else {
        printf("Not found 15.\n");
    }

    // Clean up memory
    while (list->header->forward[0] != NULL) {
        delete(list, list->header->forward[0]->data);
    }
    free(list->header);
    free(list);

    return 0;
}