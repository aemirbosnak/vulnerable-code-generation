//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *insert_at_tail(Node *head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void parse_json(char *json_string) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int index = 0;
    Node *head = NULL;

    while (1) {
        switch (json_string[index]) {
            case '"':
                insert_at_tail(head, json_string + index);
                index++;
                break;
            case ':':
                insert_at_tail(head, ":");
                index++;
                break;
            case ',':
                insert_at_tail(head, ",");
                index++;
                break;
            case '}':
                insert_at_tail(head, "}");
                index++;
                break;
            case ' ':
                insert_at_tail(head, " ");
                index++;
                break;
            default:
                index++;
                break;
        }

        if (json_string[index] == '\0') {
            break;
        }
    }

    free(buffer);
    free(head);
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    parse_json(json_string);

    return 0;
}