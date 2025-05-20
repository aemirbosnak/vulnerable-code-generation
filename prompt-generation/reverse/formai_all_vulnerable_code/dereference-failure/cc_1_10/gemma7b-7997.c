//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    Node* head = NULL;
    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    print_list(head);

    // Find the route from a to d
    Node* current = head;
    while (current) {
        if (current->data == 'a') {
            current = current->next;
            while (current && current->data != 'd') {
                current = current->next;
            }
            if (current) {
                printf("The route from a to d is: ");
                print_list(current);
            } else {
                printf("No route found.\n");
            }
        }
        current = current->next;
    }

    return 0;
}