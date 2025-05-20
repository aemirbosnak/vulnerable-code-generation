//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_to_front(node** head, int value) {
    node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node** head, int value) {
    node* current = *head;
    node* prev = NULL;

    while (current!= NULL && current->value!= value) {
        prev = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

node* search_for_value(node* head, int value) {
    node* current = head;

    while (current!= NULL && current->value!= value) {
        current = current->next;
    }

    if (current!= NULL) {
        return current;
    } else {
        return NULL;
    }
}

int main() {
    node* head = NULL;

    add_to_front(&head, 5);
    add_to_front(&head, 10);
    add_to_front(&head, 15);
    add_to_front(&head, 20);

    printf("Linked list: ");
    node* current = head;

    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    delete_node(&head, 15);

    printf("Linked list after deleting 15: ");
    current = head;

    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    node* found = search_for_value(head, 20);

    if (found!= NULL) {
        printf("Found 20 in the linked list!\n");
    } else {
        printf("Value not found in the linked list.\n");
    }

    return 0;
}