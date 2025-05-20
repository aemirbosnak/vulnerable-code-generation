//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct SListNode {
    int data;
    size_t next;
} SListNode;

void print_list(SListNode *head) {
    SListNode *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = (SListNode *)current->next;
    }
    printf("\b\n");
}

SListNode *create_node(int data) {
    SListNode *new_node = (SListNode *)malloc(sizeof(SListNode));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new node.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = 0;
    return new_node;
}

void insert_at_end(SListNode **head, int data) {
    SListNode *new_node = create_node(data);
    SListNode *current = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (current->next != 0) {
        current = (SListNode *)current->next;
    }

    current->next = (size_t)new_node;
}

void free_list(SListNode *head) {
    SListNode *current = head;
    SListNode *next;

    while (current != NULL) {
        next = (SListNode *)current->next;
        free(current);
        current = next;
    }
}

int main() {
    SListNode *head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);

    print_list(head);

    free_list(head);

    return 0;
}