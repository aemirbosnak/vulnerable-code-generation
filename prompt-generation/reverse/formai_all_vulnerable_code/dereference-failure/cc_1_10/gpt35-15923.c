//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_VALUE_LEN 256
#define MAX_BUFFER 2048

typedef struct Node Node;
typedef struct Index Index;

struct Node {
    char key[MAX_KEY_LEN + 1];
    char value[MAX_VALUE_LEN + 1];
    Node* next;
};

struct Index {
    Node* head;
    Index* next;
};

Index* index_root = NULL;

void insert(char* key, char* value) {
    // Find the index for the key
    Index* index = index_root;
    while (index != NULL && strcmp(index->head->key, key) < 0) {
        index = index->next;
    }

    // Create a new index if none exists, or if the existing index is for a different key
    if (index == NULL || strcmp(index->head->key, key) != 0) {
        Index* new_index = malloc(sizeof(Index));
        new_index->head = malloc(sizeof(Node));
        strncpy(new_index->head->key, key, MAX_KEY_LEN);
        new_index->head->key[MAX_KEY_LEN] = '\0';
        new_index->head->value[0] = '\0';
        new_index->next = index;
        index_root = new_index;
        index = new_index;
    }

    // Find the node for the key, or insert a new node
    Node* node = index->head;
    while (node->next != NULL && strcmp(node->next->key, key) <= 0) {
        node = node->next;
    }

    if (strcmp(node->key, key) == 0) {
        strncpy(node->value, value, MAX_VALUE_LEN);
        node->value[MAX_VALUE_LEN] = '\0';
    } else {
        Node* new_node = malloc(sizeof(Node));
        strncpy(new_node->key, key, MAX_KEY_LEN);
        new_node->key[MAX_KEY_LEN] = '\0';
        strncpy(new_node->value, value, MAX_VALUE_LEN);
        new_node->value[MAX_VALUE_LEN] = '\0';
        new_node->next = node->next;
        node->next = new_node;
    }
}

char* get(char* key) {
    Index* index = index_root;
    while (index != NULL && strcmp(index->head->key, key) != 0) {
        index = index->next;
    }

    if (index == NULL) {
        return NULL;
    }

    Node* node = index->head;
    while (node != NULL && strcmp(node->key, key) < 0) {
        node = node->next;
    }

    if (node == NULL || strcmp(node->key, key) != 0) {
        return NULL;
    }

    return node->value;
}

void delete(char* key) {
    Index* index = index_root;
    while (index != NULL && strcmp(index->head->key, key) != 0) {
        index = index->next;
    }

    if (index == NULL) {
        return;
    }

    Node* node = index->head;
    while (node->next != NULL && strcmp(node->next->key, key) < 0) {
        node = node->next;
    }

    if (node->next == NULL || strcmp(node->next->key, key) != 0) {
        return;
    }

    Node* temp = node->next;
    node->next = temp->next;
    free(temp);
}

void print() {
    char buffer[MAX_BUFFER];
    Index* index = index_root;

    while (index != NULL) {
        Node* node = index->head;
        while (node != NULL) {
            sprintf(buffer, "%s:%s\n", node->key, node->value);
            fputs(buffer, stdout);
            node = node->next;
        }
        index = index->next;
    }
}

int main() {
    insert("key1", "value1");
    insert("key2", "value2");
    insert("key3", "value3");
    insert("key4", "value4");
    print();

    char* value = get("key2");
    if (value != NULL) {
        printf("key2 = %s\n", value);
    }

    delete("key3");
    print();

    return 0;
}