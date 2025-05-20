//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON data structure
typedef struct json_data {
    char key[50];
    char value[50];
    struct json_data *next;
} JSON_DATA;

// Function to create a new JSON data node
JSON_DATA *create_node(char *key, char *value) {
    JSON_DATA *new_node = (JSON_DATA*) malloc(sizeof(JSON_DATA));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = NULL;
    return new_node;
}

// Function to add new data to the JSON object
void add_new_data(JSON_DATA **head, char *key, char *value) {
    JSON_DATA *new_node = create_node(key, value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        JSON_DATA *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the JSON object
void print_json_data(JSON_DATA *head) {
    printf("{\n");
    while (head != NULL) {
        printf("\t\"%s\": \"%s\",\n", head->key, head->value);
        head = head->next;
    }
    printf("}\n");
}

int main() {
    char json_string[100] = "{\"name\": \"John\", \"age\": 28, \"country\": \"USA\"}";
    char *token = strtok(json_string, "{\":,}");
    JSON_DATA *head = NULL;
    char *key = (char*) malloc(50 * sizeof(char));
    char *value = (char*) malloc(50 * sizeof(char));
    int count = 0;
    while (token != NULL) {
        if (count % 2 == 0) {
            strcpy(key, token);
        } else {
            strcpy(value, token);
            add_new_data(&head, key, value);
        }
        token = strtok(NULL, "{\":,}");
        count++;
    }
    print_json_data(head);
    return 0;
}