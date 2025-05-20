//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSON_Node *object;
        struct JSON_Node *array;
    } data;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *tail = NULL;

    // Allocate memory for the JSON node.
    JSON_Node *node = malloc(sizeof(JSON_Node));

    // Set the node's type to 'object'.
    node->type = 'o';

    // Set the node's data to the JSON string.
    node->data.string = strdup(json_string);

    // Add the node to the head of the JSON tree.
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    return head;
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";

    JSON_Node *head = parse_json(json_string);

    // Traverse the JSON tree and print the data.
    JSON_Node *node = head;
    while (node) {
        switch (node->type) {
            case 'o':
                printf("Object:\n");
                printf("  Name: %s\n", node->data.string);
                printf("  Age: %d\n", node->data.number);
                break;
            case 'a':
                printf("Array:\n");
                break;
            case 'n':
                printf("Number: %d\n", node->data.number);
                break;
            case 'd':
                printf("Decimal: %lf\n", node->data.decimal);
                break;
            case 's':
                printf("String: %s\n", node->data.string);
                break;
        }

        node = node->next;
    }

    return 0;
}