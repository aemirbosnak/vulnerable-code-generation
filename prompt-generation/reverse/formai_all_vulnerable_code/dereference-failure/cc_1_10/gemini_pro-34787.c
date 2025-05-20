//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_node {
    char *key;
    char *value;
    struct json_node *next;
    struct json_node *children;
} json_node;

json_node *json_parse(char *json) {
    json_node *root = malloc(sizeof(json_node));
    root->key = NULL;
    root->value = NULL;
    root->next = NULL;
    root->children = NULL;

    char *token = strtok(json, ":");
    while (token != NULL) {
        char *key = token;
        token = strtok(NULL, ":");
        if (token == NULL) {
            break;
        }
        char *value = token;
        token = strtok(NULL, "}");

        json_node *node = malloc(sizeof(json_node));
        node->key = key;
        node->value = value;
        node->next = NULL;
        node->children = NULL;

        if (root->children == NULL) {
            root->children = node;
        } else {
            json_node *child = root->children;
            while (child->next != NULL) {
                child = child->next;
            }
            child->next = node;
        }
    }

    return root;
}

void json_print(json_node *node) {
    if (node == NULL) {
        return;
    }

    if (node->key != NULL) {
        printf("%s: %s\n", node->key, node->value);
    }

    if (node->children != NULL) {
        json_print(node->children);
    }

    if (node->next != NULL) {
        json_print(node->next);
    }
}

int main() {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"occupation\": \"programmer\" }";

    json_node *root = json_parse(json);
    json_print(root);

    return 0;
}