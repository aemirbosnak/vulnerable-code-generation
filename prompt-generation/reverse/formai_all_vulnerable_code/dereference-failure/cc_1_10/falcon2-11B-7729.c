//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *children;
};

struct JsonValue *parse_json(const char *json) {
    struct JsonValue *root = NULL;
    char *current_key = NULL;
    char *current_value = NULL;

    char *token = strtok(json, ":");
    while (token!= NULL) {
        if (strcmp(token, "{") == 0) {
            struct JsonValue *new_root = (struct JsonValue*)malloc(sizeof(struct JsonValue));
            new_root->key = strdup("");
            new_root->value = strdup("");
            new_root->children = NULL;
            root = new_root;
        } else if (strcmp(token, "}") == 0) {
            free(root->key);
            free(root->value);
            struct JsonValue *child = root->children;
            while (child!= NULL) {
                free(child->key);
                free(child->value);
                struct JsonValue *next_child = child->children;
                free(child);
                child = next_child;
            }
            free(root);
            root = NULL;
        } else if (strcmp(token, "\"") == 0) {
            current_key = strdup(token);
        } else {
            current_value = strdup(token);
        }

        token = strtok(NULL, ":");
    }

    if (strcmp(current_key, "")!= 0 && strcmp(current_value, "")!= 0) {
        struct JsonValue *new_root = (struct JsonValue*)malloc(sizeof(struct JsonValue));
        new_root->key = strdup(current_key);
        new_root->value = strdup(current_value);
        new_root->children = NULL;
        root = new_root;
    }

    return root;
}

int main() {
    const char *json = "{\"name\":\"John\",\"age\":30}";
    struct JsonValue *root = parse_json(json);
    printf("Parsed JSON:\n");
    struct JsonValue *current = root;
    while (current!= NULL) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->children;
    }
    return 0;
}