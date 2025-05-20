//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node;

node *create_node(char *key, char *value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;
    return new_node;
}

node *parse_json(char *json_data) {
    node *head = NULL;
    node *current = NULL;
    char *key = NULL;
    char *value = NULL;
    char *start = NULL;
    char *end = NULL;

    start = strchr(json_data, '{');
    if (start == NULL) {
        printf("Invalid JSON format\n");
        return NULL;
    }

    end = strrchr(json_data, '}');
    if (end == NULL) {
        printf("Invalid JSON format\n");
        return NULL;
    }

    current = create_node(start, end);
    head = current;

    while (current!= NULL) {
        start = strchr(current->value, ':');
        if (start == NULL) {
            printf("Invalid JSON format\n");
            return NULL;
        }

        key = start + 1;
        value = strchr(key, ',');
        if (value == NULL) {
            printf("Invalid JSON format\n");
            return NULL;
        }

        *value = '\0';
        current->key = strdup(key);

        start = strchr(current->value, ':');
        if (start == NULL) {
            printf("Invalid JSON format\n");
            return NULL;
        }

        value = strchr(start + 1, ',');
        if (value == NULL) {
            printf("Invalid JSON format\n");
            return NULL;
        }

        *value = '\0';
        current->value = strdup(start + 1);

        current = current->next;
    }

    return head;
}

int main() {
    char *json_data = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    node *head = parse_json(json_data);
    if (head!= NULL) {
        node *current = head;
        while (current!= NULL) {
            printf("Key: %s\nValue: %s\n", current->key, current->value);
            current = current->next;
        }
    }
    return 0;
}