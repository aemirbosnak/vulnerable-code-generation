//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 10000

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} Node;

Node *createNode(char *key, char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void printJson(Node *root) {
    while (root!= NULL) {
        printf("%s: %s\n", root->key, root->value);
        root = root->next;
    }
}

int main() {
    Node *root = NULL;

    char json[BUF_SIZE];
    FILE *file = fopen("example.json", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fread(json, sizeof(char), BUF_SIZE, file);
    fclose(file);

    char *ptr = strtok(json, "{");
    while (ptr!= NULL) {
        Node *temp = root;
        while (temp->key!= NULL && strcmp(temp->key, ptr)) {
            temp = temp->next;
        }

        if (temp->key == NULL) {
            temp->key = strdup(ptr);
            temp->value = strdup(strtok(NULL, ":"));
            temp->next = createNode(strtok(NULL, ","), strtok(NULL, "}"));
        } else {
            printf("Error: duplicate key '%s'\n", temp->key);
            return 1;
        }

        ptr = strtok(NULL, ",");
    }

    printJson(root);

    return 0;
}