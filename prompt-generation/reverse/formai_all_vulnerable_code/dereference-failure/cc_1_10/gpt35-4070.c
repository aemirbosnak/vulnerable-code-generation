//FormAI DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void add_node(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *cur_node = *head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
}

int remove_node(struct node **head, int data) {
    if (*head == NULL) {
        return -1;
    }
    struct node *cur_node = *head;
    if (cur_node->data == data) {
        *head = cur_node->next;
        free(cur_node);
        return 0;
    }
    while (cur_node->next != NULL && cur_node->next->data != data) {
        cur_node = cur_node->next;
    }
    if (cur_node->next != NULL) {
        struct node *temp_node = cur_node->next;
        cur_node->next = temp_node->next;
        free(temp_node);
        return 0;
    }
    return -1;
}

void print_list(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List: ");
        struct node *cur_node = head;
        while (cur_node != NULL) {
            printf("%d ", cur_node->data);
            cur_node = cur_node->next;
        }
        printf("\n");
    }
}

int main() {
    struct node *head = NULL;
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    add_node(&head, 40);
    add_node(&head, 50);
    print_list(head);
    remove_node(&head, 30);
    remove_node(&head, 10);
    print_list(head);
    return 0;
}