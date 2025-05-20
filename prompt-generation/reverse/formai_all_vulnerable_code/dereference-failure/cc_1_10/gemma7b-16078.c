//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Beautifier {
    Node* head;
    int current_position;
    char buffer[MAX_BUFFER_SIZE];
} Beautifier;

void insert_node(Beautifier* beautifier, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (beautifier->head == NULL) {
        beautifier->head = new_node;
    } else {
        beautifier->head->next = new_node;
    }

    beautifier->current_position++;
}

void format_string(Beautifier* beautifier) {
    int i = 0;
    char* str = beautifier->buffer;

    for (i = 0; i < beautifier->current_position; i++) {
        Node* node = beautifier->head;

        for (node = beautifier->head; node->next != NULL; node = node->next) {
            if (node->data == str[i]) {
                str[i] = ' ';
            }
        }
    }

    str[beautifier->current_position] = '\0';
}

int main() {
    Beautifier* beautifier = malloc(sizeof(Beautifier));
    beautifier->head = NULL;
    beautifier->current_position = 0;

    insert_node(beautifier, 'a');
    insert_node(beautifier, 'b');
    insert_node(beautifier, 'c');
    insert_node(beautifier, 'd');
    insert_node(beautifier, 'e');

    format_string(beautifier);

    printf("%s", beautifier->buffer);

    return 0;
}