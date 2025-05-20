//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10

typedef struct Node {
    char type;
    union {
        int number;
        char* string;
        struct Node** array;
    } data;
    struct Node* next;
} Node;

Node* parseJson(char* json, int depth) {
    Node* head = NULL;
    Node* current = NULL;
    int i = 0;

    for (; json[i] != '\0' && depth < MAX_DEPTH; i++) {
        switch (json[i]) {
            case '"':
                current = malloc(sizeof(Node));
                current->type = 's';
                current->data.string = strdup(json + i + 1);
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case ' ':
            case ',':
            case ':':
            case ']':
                current = malloc(sizeof(Node));
                current->type = 'a';
                current->data.array = NULL;
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case '{':
            case '[':
                current = malloc(sizeof(Node));
                current->type = 'o';
                current->data.number = -1;
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                depth++;
                parseJson(json + i + 1, depth);
                depth--;
                break;
            default:
                break;
        }
    }

    return head;
}

int main() {
    char json[] = "{ 'name': 'Dennis Ritchie', 'age': 90 }";
    Node* head = parseJson(json, 0);

    printf("Name: %s\n", head->data.string);
    printf("Age: %d\n", head->next->data.number);

    return 0;
}