//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insert_at_tail(struct Node* head, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {

    struct Node* head = NULL;

    char input[MAX_BUFFER_SIZE] = "";

    printf("Enter a string: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove all special characters from the input string
    char* ptr = input;
    while (*ptr) {
        if (!isalnum(*ptr)) {
            *ptr = '\0';
        }
        ptr++;
    }

    // Insert each character of the sanitized string into the linked list
    for (ptr = input; *ptr; ptr++) {
        insert_at_tail(head, *ptr);
    }

    // Print the sanitized string
    printf("Sanitized string: ");
    for (struct Node* node = head; node; node = node->next) {
        printf("%c ", node->data);
    }

    printf("\n");

    return 0;
}