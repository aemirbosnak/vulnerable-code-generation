//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSON_Node *object;
        struct JSON_Node **array;
    } data;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JSON_Node));
    tail = head;

    // Loop over the JSON string
    int i = 0;
    for (i = 0; json_string[i] != '\0'; i++) {
        // Check if the current character is a key-value pair delimiter
        if (json_string[i] == ':' || json_string[i] == ',') {
            // Allocate memory for a new node
            tail = malloc(sizeof(JSON_Node));
            tail->next = NULL;

            // Set the node's type and data
            switch (json_string[i - 1]) {
                case '"':
                    tail->type = 's';
                    tail->data.string = strdup(json_string + i + 1);
                    break;
                case 'n':
                    tail->type = 'n';
                    tail->data.number = atoi(json_string + i + 1);
                    break;
                case 'f':
                    tail->type = 'd';
                    tail->data.decimal = atof(json_string + i + 1);
                    break;
                case '{':
                    tail->type = 'o';
                    tail->data.object = parse_json(json_string + i + 1);
                    break;
                case '[':
                    tail->type = 'a';
                    tail->data.array = parse_json(json_string + i + 1);
                    break;
            }

            // Update the tail of the linked list
            tail = tail->next;
        }
    }

    // Return the head of the linked list
    return head;
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *json_parser = parse_json(json_string);

    // Print the JSON data
    printf("Name: %s\n", json_parser->data.object->data.string);
    printf("Age: %d\n", json_parser->data.object->data.number);

    return 0;
}