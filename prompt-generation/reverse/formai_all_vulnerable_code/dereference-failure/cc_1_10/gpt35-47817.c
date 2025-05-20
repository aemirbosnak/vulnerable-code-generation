//FormAI DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertFirst(struct node **head, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        new_node->next = *head;
        *head = new_node;
    }
}

void insertLast(struct node* head, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertNth(struct node** head, int data, int n) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    else if (n == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    struct node* temp = *head;
    int count = 0;
    while (temp != NULL && count < n - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteFirst(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteNth(struct node** head, int n) {
    if (*head == NULL) {
        printf("List is already empty!\n");
        return;
    }
    else if (n == 0) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    struct node* temp = *head;
    int count = 0;
    while (temp != NULL && count < n - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }
    struct node* extra = temp->next;
    temp->next = extra->next;
    free(extra);
}

void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    
    printf("Empty List: ");
    printList(head);
    
    insertFirst(&head, 5);
    insertFirst(&head, 3);
    insertFirst(&head, 7);
    printf("After insertFirst: ");
    printList(head);
    
    insertLast(head, 10);
    insertLast(head, 15);
    printf("After insertLast: ");
    printList(head);
    
    insertNth(&head, 2, 1);
    insertNth(&head, 12, 7);
    printf("After insertNth: ");
    printList(head);
    
    deleteFirst(&head);
    deleteFirst(&head);
    printf("After deleteFirst: ");
    printList(head);
    
    deleteLast(head);
    deleteLast(head);
    printf("After deleteLast: ");
    printList(head);
    
    deleteNth(&head, 2);
    deleteNth(&head, 7);
    printf("After deleteNth: ");
    printList(head);
    
    return 0;
}