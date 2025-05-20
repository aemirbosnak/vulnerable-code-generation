//FormAI DATASET v1.0 Category: Linked list operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_at_beginning(int item) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at beginning of the linked list\n", item);
}

void insert_at_end(int item) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at end of the linked list\n", item);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at end of the linked list\n", item);
}

void delete_from_beginning() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("%d deleted from the beginning of the linked list\n", temp->data);
    free(temp);
}

void delete_from_end() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from the end of the linked list\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("%d deleted from the end of the linked list\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void print_linked_list() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(5);
    insert_at_end(10);
    insert_at_end(15);
    insert_at_beginning(3);
    print_linked_list();
    delete_from_beginning();
    delete_from_end();
    print_linked_list();
    return 0;
}