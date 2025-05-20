//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char* string;
        struct JSON_Node* array;
        struct JSON_Node* object;
    } data;
    struct JSON_Node* next;
} JSON_Node;

JSON_Node* JSON_Parse(char* json_string) {
    JSON_Node* head = NULL;
    JSON_Node* current = NULL;
    int i = 0;
    char* buffer = malloc(MAX_BUFFER_SIZE);

    // Allocate memory for the first node
    if (head == NULL) {
        head = current = malloc(sizeof(JSON_Node));
    } else {
        current = malloc(sizeof(JSON_Node));
        current->next = head;
        head = current;
    }

    // Loop over the JSON string
    while (json_string[i] != '\0') {
        // Handle quotes and strings
        if (json_string[i] == '"') {
            // Allocate memory for the string
            current->data.string = malloc(MAX_BUFFER_SIZE);
            // Copy the string
            int j = 0;
            while (json_string[i + 1] != '"' && json_string[i + 1] != '\0') {
                current->data.string[j] = json_string[i + 1];
                j++;
                i++;
            }
            current->data.string[j] = '\0';
            i++;
        }
        // Handle numbers
        else if (json_string[i] >= '0' && json_string[i] <= '9') {
            // Convert the number to an integer
            current->data.number = atoi(&json_string[i]);
            i++;
        }
        // Handle objects and arrays
        else if (json_string[i] == '{' || json_string[i] == '[') {
            // Allocate memory for the array or object
            current->data.object = malloc(sizeof(JSON_Node));
            current->data.object->next = head;
            head = current->data.object;
            i++;
        }
    }

    free(buffer);

    return head;
}

int main() {
    char* json_string = "{ 'name': 'Sherlock Holmes', 'address': '221B Baker St.' }";
    JSON_Node* head = JSON_Parse(json_string);

    // Print the JSON data
    while (head) {
        switch (head->type) {
            case 'o':
                printf("Object:\n");
                break;
            case 'a':
                printf("Array:\n");
                break;
            case 's':
                printf("String: %s\n", head->data.string);
                break;
            case 'n':
                printf("Number: %d\n", head->data.number);
                break;
            case 'd':
                printf("Decimal: %f\n", head->data.decimal);
                break;
        }
        head = head->next;
    }

    return 0;
}