//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 16

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;
    char previous_char = current->data;

    while (current->next) {
        if (current->data == previous_char) {
            count++;
        } else {
            if (previous) {
                printf("%c", previous_char);
                printf("%d", count);
                previous = current;
            } else {
                previous = current;
            }
            count = 1;
            previous_char = current->data;
        }
        current = current->next;
    }

    if (previous) {
        printf("%c", previous_char);
        printf("%d", count);
    }
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 'a';

    Node* second = malloc(sizeof(Node));
    second->data = 'a';

    Node* third = malloc(sizeof(Node));
    third->data = 'b';

    Node* fourth = malloc(sizeof(Node));
    fourth->data = 'b';

    head->next = second;
    second->next = third;
    third->next = fourth;

    compress(head);

    return 0;
}