//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void print_node(Node* node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Data: %d, Next: %p, Prev: %p\n", node->data, node->next, node->prev);
}

void print_list(Node* head) {
    Node* current = head;

    printf("Linked List:\n");
    while (current != NULL) {
        print_node(current);
        usleep(50000); // Delay for better visualization
        current = current->next;
    }
}

void create_list(Node** head, int size) {
    Node* current = *head;
    Node* new_node;

    for (int i = 0; i < size; i++) {
        if (!*head) {
            *head = (Node*)malloc(sizeof(Node));
            (*head)->data = i;
            (*head)->next = NULL;
            (*head)->prev = NULL;
            current = *head;
        } else {
            new_node = (Node*)malloc(sizeof(Node));
            new_node->data = i;
            new_node->next = current;
            new_node->prev = current->prev;

            if (current->prev)
                current->prev->next = new_node;

            current->prev = new_node;
            current = new_node;
        }
    }
}

int main() {
    Node* head = NULL;
    int size = 10;

    create_list(&head, size);
    print_list(head);

    free(head);

    return 0;
}