//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_node(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
    } else {
        if (temp == *head_ref) {
            *head_ref = temp->next;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void reverse_list(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

void print_list(struct Node* head) {
    struct Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);
    insert_node(&head, 6);
    insert_node(&head, 7);
    insert_node(&head, 8);
    insert_node(&head, 9);
    insert_node(&head, 10);

    print_list(head);
    printf("\n");

    delete_node(&head, 5);
    print_list(head);
    printf("\n");

    reverse_list(&head);
    print_list(head);
    printf("\n");

    return 0;
}