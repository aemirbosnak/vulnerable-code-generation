//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* parse_c_syntax(char* input_string) {
    Node* head = NULL;
    Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(Node));
    tail = head;

    // Iterate over the input string
    int i = 0;
    for (; input_string[i] != '\0'; i++) {
        // Check if the character is a letter
        if (input_string[i] >= 'a' && input_string[i] <= 'z') {
            // Allocate memory for a new node
            tail->next = malloc(sizeof(Node));
            tail = tail->next;

            // Store the character in the new node
            tail->data = input_string[i];
        }
    }

    // Return the head node
    return head;
}

int main() {
    char* input_string = "Hello, world!";
    Node* syntax_tree = parse_c_syntax(input_string);

    // Print the syntax tree
    Node* current = syntax_tree;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}