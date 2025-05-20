//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_node {
    char *key;
    char *value;
    struct json_node *next;
    struct json_node *child;
} json_node;

json_node *json_parse(char *json) {
    json_node *root = NULL;
    json_node *current = NULL;
    char *key = NULL;
    char *value = NULL;
    char *next = json;
    while (*next) {
        switch (*next) {
            case '{':
                if (root == NULL) {
                    root = malloc(sizeof(json_node));
                    root->key = NULL;
                    root->value = NULL;
                    root->next = NULL;
                    root->child = NULL;
                    current = root;
                } else {
                    current->next = malloc(sizeof(json_node));
                    current->next->key = NULL;
                    current->next->value = NULL;
                    current->next->next = NULL;
                    current->next->child = NULL;
                    current = current->next;
                }
                next++;
                break;
            case '}':
                current = current->next;
                next++;
                break;
            case '"':
                next++;
                key = next;
                while (*next != '"') {
                    next++;
                }
                *next = '\0';
                current->key = strdup(key);
                next++;
                break;
            case ':':
                next++;
                value = next;
                while (*next != ',' && *next != '}') {
                    next++;
                }
                *next = '\0';
                current->value = strdup(value);
                next++;
                break;
            case '[':
                if (root == NULL) {
                    root = malloc(sizeof(json_node));
                    root->key = NULL;
                    root->value = NULL;
                    root->next = NULL;
                    root->child = NULL;
                    current = root;
                } else {
                    current->next = malloc(sizeof(json_node));
                    current->next->key = NULL;
                    current->next->value = NULL;
                    current->next->next = NULL;
                    current->next->child = NULL;
                    current = current->next;
                }
                next++;
                break;
            case ']':
                current = current->next;
                next++;
                break;
            default:
                next++;
                break;
        }
    }
    return root;
}

void json_free(json_node *root) {
    if (root == NULL) {
        return;
    }
    json_free(root->next);
    json_free(root->child);
    free(root->key);
    free(root->value);
    free(root);
}

void json_print(json_node *root) {
    if (root == NULL) {
        return;
    }
    if (root->key != NULL) {
        printf("%s: %s\n", root->key, root->value);
    } else {
        printf("[\n");
        json_node *child = root->child;
        while (child != NULL) {
            json_print(child);
            child = child->next;
        }
        printf("]\n");
    }
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"address\": {\"street\": \"123 Main Street\", \"city\": \"Anytown\", \"state\": \"CA\", \"zip\": \"12345\"}, \"phone\": [\"123-456-7890\", \"234-567-8901\"], \"email\": \"johndoe@example.com\"}";
    json_node *root = json_parse(json);
    json_print(root);
    json_free(root);
    return 0;
}