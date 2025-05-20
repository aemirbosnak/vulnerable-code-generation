//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert_front(struct node **head, int value) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void insert_end(struct node **head, int value) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (*head == NULL) {
        *head = temp;
    }
    else {
        struct node *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = temp;
    }
}

void delete_front(struct node **head) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }
    else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_end(struct node **head) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }
    else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        struct node *second_last_node = *head;
        while (second_last_node->next->next != NULL) {
            second_last_node = second_last_node->next;
        }
        free(second_last_node->next);
        second_last_node->next = NULL;
    }
}

int main() {
    struct node *head = NULL;
    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_front(&head, 0);
    display(head);
    delete_end(&head);
    delete_front(&head);
    display(head);
    return 0;
}