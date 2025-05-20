//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define SHOUT(fmt, ...) printf("\033[1;31m" fmt "\033[0m\n", ##__VA_ARGS__)
#define WHISPER(fmt, ...) printf("\033[0;33m" fmt "\033[0m\n", ##__VA_ARGS__)

typedef struct node {
    int data;
    struct node *next;
} node_t;

void insert_at_head(node_t **head, int data) {
    WHISPER("HEY! I'm adding %d to the HEAD of the list!", data);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
    WHISPER("YO! I'm tagging %d to the TAIL of the list!", data);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_node(node_t **head, int data) {
    SHOUT("WATCH OUT! I'm gonna DELETE %d from the list!", data);
    if (*head == NULL) {
        WHISPER("Dude, the list is already EMPTY!");
        return;
    }
    node_t *current = *head;
    node_t *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        WHISPER("Sorry, but %d is NOT in the list!", data);
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void print_list(node_t *head) {
    SHOUT("BADA-BOOM! Here's the list:");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node_t *head = NULL;

    SHOUT("HEY THERE! Let's play with linked lists!");

    insert_at_head(&head, 10);
    insert_at_head(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);

    print_list(head);

    delete_node(&head, 20);
    delete_node(&head, 30);
    delete_node(&head, 50);

    print_list(head);

    return 0;
}