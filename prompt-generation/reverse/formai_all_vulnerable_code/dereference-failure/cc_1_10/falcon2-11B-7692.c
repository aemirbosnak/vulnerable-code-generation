//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024
#define MAX_ARRAY_SIZE 10

typedef struct node {
    char *key;
    char *value;
    int is_array;
    struct node *next;
} node_t;

void error(const char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

int parse_json(const char *json, int start, node_t *head) {
    char *endptr;
    char *token;
    int i;
    node_t *new_node;

    token = strsep(&json, ":");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    if (strcmp(token, "null") == 0) {
        new_node = malloc(sizeof(node_t));
        new_node->key = "null";
        new_node->value = "null";
        new_node->is_array = 0;
        new_node->next = head;
        return 1;
    }
    token = strsep(&json, ":");
    if (strcmp(token, "true") == 0) {
        new_node = malloc(sizeof(node_t));
        new_node->key = "true";
        new_node->value = "true";
        new_node->is_array = 0;
        new_node->next = head;
        return 1;
    }
    if (strcmp(token, "false") == 0) {
        new_node = malloc(sizeof(node_t));
        new_node->key = "false";
        new_node->value = "false";
        new_node->is_array = 0;
        new_node->next = head;
        return 1;
    }
    token = strsep(&json, ":");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    new_node = malloc(sizeof(node_t));
    new_node->key = token;
    token = strsep(&json, ":");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    new_node->value = token;
    new_node->is_array = 0;
    new_node->next = head;

    return 1;
}

node_t *parse_json_recursive(const char *json, int start) {
    node_t *head = NULL;
    node_t *new_node = NULL;
    char *endptr;
    char *token;
    int i;

    token = strsep(&json, "{");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    if (parse_json(json, start, &head)) {
        new_node = malloc(sizeof(node_t));
        new_node->is_array = 1;
        new_node->next = head;
        return new_node;
    }
    token = strsep(&json, "}");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    if (parse_json(json, start, &head)) {
        new_node = malloc(sizeof(node_t));
        new_node->is_array = 1;
        new_node->next = head;
        return new_node;
    }
    token = strsep(&json, " ");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    new_node = malloc(sizeof(node_t));
    new_node->key = token;
    token = strsep(&json, ":");
    if (token == NULL) {
        error("Unexpected end of JSON");
    }
    new_node->value = token;
    new_node->is_array = 0;
    new_node->next = head;
    return new_node;
}

void print_json(node_t *node) {
    while (node!= NULL) {
        printf("%s : %s\n", node->key, node->value);
        node = node->next;
    }
}

int main() {
    const char *json = "{ \"name\": \"John\", \"age\": 30, \"is_student\": true, \"is_married\": false, \"address\": \"123 Main St\", \"phone\": \"555-1234\", \"interests\": [\"coding\", \"reading\"] }";
    node_t *head = parse_json_recursive(json, 0);
    print_json(head);
    free(head);
    return 0;
}