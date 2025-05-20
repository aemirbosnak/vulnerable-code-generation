//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
// This is a unique C data structures visualization example program in a cryptic style.
// It will create a linked list and perform various operations on it.
// Be prepared for some mind-bending code!

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void create_list(Node** head, int n) {
    Node* curr = *head;
    for (int i = 0; i < n; i++) {
        curr->data = i;
        curr->next = malloc(sizeof(Node));
        curr = curr->next;
    }
    curr->next = NULL;
}

void print_list(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sort_list(Node** head) {
    Node* curr = *head;
    while (curr!= NULL && curr->next!= NULL) {
        if (curr->data > curr->next->data) {
            int temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
            curr = curr->next;
        } else {
            curr = curr->next;
        }
    }
}

int main() {
    Node* head = NULL;
    create_list(&head, 5);
    print_list(head);
    reverse_list(&head);
    print_list(head);
    sort_list(&head);
    print_list(head);
    free(head);
    return 0;
}