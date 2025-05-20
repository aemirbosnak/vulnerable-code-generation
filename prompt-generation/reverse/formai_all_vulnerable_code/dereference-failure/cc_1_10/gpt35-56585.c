//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data);
void append(struct Node** head_ref, int data);
void display(struct Node* head);
void insert(struct Node** head_ref, int position, int data);
void delete(struct Node** head_ref, int position);

int main() {
    struct Node* head = NULL;
    // append some data to the linked list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    // display the linked list
    printf("Initial Linked List:\n");
    display(head);
    // insert some data at position 2
    insert(&head, 2, 25);
    // display the linked list after insertion
    printf("\nLinked List after Insertion:\n");
    display(head);
    // delete some data at position 0
    delete(&head, 0);
    // display the linked list after deletion
    printf("\nLinked List after Deletion:\n");
    display(head);
    return 0;
}

struct Node* create_node(int data) {
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(struct Node** head_ref, int data) {
    struct Node* temp = create_node(data);
    struct Node* current;
    if (*head_ref == NULL) {
        *head_ref = temp;
    } else {
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void insert(struct Node** head_ref, int position, int data) {
    struct Node* temp = create_node(data);
    struct Node* current = *head_ref;
    if (position == 0) {
        temp->next = current;
        *head_ref = temp;
    } else {
        int i;
        for (i = 0; i < position-1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("\nInvalid position\n");
        } else {
            temp->next = current->next;
            current->next = temp;
        }
    }
}

void delete(struct Node** head_ref, int position) {
    struct Node* current = *head_ref;
    struct Node* temp;
    if (position == 0) {
        *head_ref = current->next;
        free(current);
    } else {
        int i;
        for (i = 0; i < position-1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("\nInvalid position\n");
        } else {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}