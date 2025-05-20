//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct node {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node *next;
} Node;

Node *table[MAX_NODES];

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]) {
        sum += key[i];
        i++;
    }
    return sum % MAX_NODES;
}

void insert(char *key, char *value) {
    int index = hash(key);
    Node *node = table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            strcpy(node->value, value);
            return;
        }
        node = node->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = table[index];
    table[index] = new_node;
}

char *search(char *key) {
    int index = hash(key);
    Node *node = table[index];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char key[MAX_KEY_SIZE];
        char value[MAX_VALUE_SIZE];
        scanf("%s %s", key, value);
        insert(key, value);
    }
    char query[MAX_KEY_SIZE];
    while (1) {
        printf("Enter query (or 'exit' to quit): ");
        scanf("%s", query);
        if (strcmp(query, "exit") == 0) {
            break;
        }
        char *result = search(query);
        if (result!= NULL) {
            printf("%s\n", result);
        } else {
            printf("Not found\n");
        }
    }
    return 0;
}