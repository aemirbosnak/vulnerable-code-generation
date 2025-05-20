//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void parseJSON(char* json) {
    Node* head = newNode('\0');
    Node* current = head;
    int i = 0;

    for (; json[i] != '\0'; i++) {
        switch (json[i]) {
            case '"':
                current->next = newNode('"');
                current = current->next;
                break;
            case '{' :
                current->next = newNode('{');
                current = current->next;
                break;
            case '}':
                current->next = newNode('}');
                current = current->next;
                break;
            case ',':
                current->next = newNode(',');
                current = current->next;
                break;
            default:
                current->next = newNode(json[i]);
                current = current->next;
                break;
        }
    }

    // Print the JSON structure
    current = head->next;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    free(head);
}

int main() {
    char json[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJSON(json);

    return 0;
}