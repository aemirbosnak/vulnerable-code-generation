//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char string_value[MAX_BUFFER_SIZE];
        struct JSON_Node* array_value;
        struct JSON_Node* object_value;
    } data;
    struct JSON_Node* next;
} JSON_Node;

JSON_Node* json_parse(char* json_string) {
    JSON_Node* head = NULL;
    JSON_Node* current = NULL;
    char* token = NULL;
    char* key = NULL;
    int i = 0;

    // Allocate memory for the first node
    head = (JSON_Node*)malloc(sizeof(JSON_Node));
    current = head;
    current->type = 'o';

    // Tokenize the JSON string
    token = strtok(json_string, ",");

    // Loop over the tokens
    while (token) {
        // Create a new node if necessary
        if (current->next == NULL) {
            current->next = (JSON_Node*)malloc(sizeof(JSON_Node));
            current = current->next;
        }

        // Set the node's type and data
        switch (token[0]) {
            case 'n':
                current->type = 'n';
                current->data.number = atoi(token);
                break;
            case 'd':
                current->type = 'd';
                current->data.decimal = atof(token);
                break;
            case '"':
                current->type = 's';
                strcpy(current->data.string_value, token);
                break;
            case 'a':
                current->type = 'a';
                current->data.array_value = json_parse(token);
                break;
            case 'o':
                current->type = 'o';
                current->data.object_value = json_parse(token);
                break;
        }

        // Move to the next token
        token = strtok(NULL, ",");
    }

    return head;
}

int main() {
    char* json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JSON_Node* parsed_json = json_parse(json_string);

    // Print the parsed JSON data
    printf("Name: %s\n", parsed_json->data.object_value->data.string_value);
    printf("Age: %d\n", parsed_json->data.object_value->data.number);
    printf("Interests: ");
    for (JSON_Node* interest = parsed_json->data.object_value->data.array_value; interest; interest = interest->next) {
        printf("%s, ", interest->data.string_value);
    }
    printf("\n");

    return 0;
}