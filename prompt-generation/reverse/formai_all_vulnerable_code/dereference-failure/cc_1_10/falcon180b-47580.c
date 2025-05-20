//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Record {
    int key;
    double value;
};

struct Node {
    struct Record data;
    int numRecords;
    int *keys;
};

void insert(struct Node *node, int key, double value) {
    if (node->numRecords == 0) {
        node->data.key = key;
        node->data.value = value;
        node->numRecords = 1;
    } else if (node->numRecords == MAX_SIZE) {
        printf("Error: Node is full.\n");
    } else {
        int i;
        for (i = 0; i < node->numRecords; i++) {
            if (node->keys[i] == key) {
                printf("Error: Key already exists.\n");
                return;
            }
        }
        node->keys[node->numRecords] = key;
        node->data.key = key;
        node->data.value = value;
        node->numRecords++;
    }
}

void search(struct Node *node, int key) {
    int i;
    for (i = 0; i < node->numRecords; i++) {
        if (node->keys[i] == key) {
            printf("Key found: %d\n", key);
            printf("Value: %.2f\n", node->data.value);
            return;
        }
    }
    printf("Error: Key not found.\n");
}

void delete(struct Node *node, int key) {
    int i;
    for (i = 0; i < node->numRecords; i++) {
        if (node->keys[i] == key) {
            node->numRecords--;
            break;
        }
    }
    if (i == node->numRecords) {
        printf("Error: Key not found.\n");
    }
}

void traverse(struct Node *node) {
    int i;
    for (i = 0; i < node->numRecords; i++) {
        printf("Key: %d, Value: %.2f\n", node->keys[i], node->data.value);
    }
}

int main() {
    struct Node root;
    root.numRecords = 0;
    root.keys = (int*)malloc(MAX_SIZE * sizeof(int));
    root.data.key = 0;
    root.data.value = 0.0;

    insert(&root, 1, 10.5);
    insert(&root, 2, 20.5);
    insert(&root, 3, 30.5);

    traverse(&root);

    search(&root, 2);

    delete(&root, 3);

    traverse(&root);

    return 0;
}