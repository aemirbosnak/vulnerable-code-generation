//FormAI DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_beginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) 
        last = last->next;
    last->next = new_node;
    return;
}

void insert_at_index(struct Node** head_ref, int index, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (index == 0) {
        insert_at_beginning(head_ref, new_data);
        return;
    }
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr == NULL) {
            printf("Given index does not exist.\n");
            return;
        }
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return;
}

void delete_at_index(struct Node** head_ref, int index) {
    struct Node* temp = *head_ref;
    if (*head_ref == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }
    if (index == 0) {
        (*head_ref) = (*head_ref)->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Given index does not exist.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert_at_end(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_end(&head, 40);
    insert_at_index(&head, 2, 50);
    delete_at_index(&head, 2);
    display(head);
    return 0;
}