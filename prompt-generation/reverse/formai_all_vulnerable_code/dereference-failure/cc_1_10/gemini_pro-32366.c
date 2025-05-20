//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int n) {
    struct node *head = NULL;
    struct node *temp = NULL;
    for (int i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    return head;
}

void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

struct node *insert_at_index(struct node *head, int data, int index) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

struct node *delete_at_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *delete_at_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node *delete_at_index(struct node *head, int index) {
    if (head == NULL) {
        return NULL;
    }
    if (index == 0) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    struct node *to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
    return head;
}

int main() {
    struct node *head = create_list(5);
    print_list(head);
    head = insert_at_beginning(head, 10);
    print_list(head);
    head = insert_at_end(head, 20);
    print_list(head);
    head = insert_at_index(head, 15, 2);
    print_list(head);
    head = delete_at_beginning(head);
    print_list(head);
    head = delete_at_end(head);
    print_list(head);
    head = delete_at_index(head, 2);
    print_list(head);
    return 0;
}