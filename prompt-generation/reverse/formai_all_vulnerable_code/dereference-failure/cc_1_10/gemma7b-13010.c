//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* parse_c_syntax(char* source) {
    Node* head = NULL;
    Node* tail = NULL;
    char* buffer = malloc(MAX_BUFFER_SIZE);
    char* current_position = buffer;
    int buffer_size = MAX_BUFFER_SIZE;

    // Eat the first parenthesis
    source++;

    // Loop over the remaining characters
    while (*source) {
        // If the buffer is full, expand it
        if (current_position - buffer >= buffer_size - 1) {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
            current_position = buffer + (current_position - buffer);
        }

        // Add the character to the buffer
        *current_position++ = *source;

        // If the character is a parenthesis, parse the nested syntax
        if (*source == ')') {
            Node* node = malloc(sizeof(Node));
            node->data = '(';
            node->next = NULL;

            if (tail) {
                tail->next = node;
                tail = node;
            } else {
                head = tail = node;
            }

            // Eat the parenthesis and move to the next character
            source++;
        }
    }

    return head;
}

int main() {
    char* source = "((())())";
    Node* head = parse_c_syntax(source);

    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}