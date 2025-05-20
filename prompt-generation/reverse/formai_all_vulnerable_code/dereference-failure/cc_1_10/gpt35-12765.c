//FormAI DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void init(struct node **head) {
    *head = NULL;
}

struct node *create_node(int val) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insert_front(struct node **head, int val) {
    struct node *new_node;
    new_node = create_node(val);
    new_node->next = *head;
    *head = new_node;
    printf("Inserted %d at the front\n", val);
}

void insert_end(struct node **head, int val) {
    struct node *new_node, *temp;
    new_node = create_node(val);
    if (*head == NULL) {
        *head = new_node;
        printf("Inserted %d at the end\n", val);
    } else {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        printf("Inserted %d at the end\n", val);
    }
}

void insert_after(struct node **head, int val1, int val2) {
    struct node *new_node, *temp;
    new_node = create_node(val1);
    temp = *head;
    while (temp != NULL) {
        if (temp->data == val2) {
            new_node->next = temp->next;
            temp->next = new_node;
            printf("Inserted %d after %d\n", val1, val2);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the list\n", val2);
}

void delete_node(struct node **head, int val) {
    struct node *temp1, *temp2;
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else if ((*head)->data == val) {
        temp1 = *head;
        *head = (*head)->next;
        free(temp1);
        printf("Deleted %d from the list\n", val);
        return;
    } else {
        temp1 = *head;
        while (temp1 != NULL && temp1->data != val) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == NULL) {
            printf("%d not found in the list\n", val);
            return;
        }
        temp2->next = temp1->next;
        free(temp1);
        printf("Deleted %d from the list\n", val);
        return;
    }
}

void display(struct node *head) {
    if (head == NULL)
        return;
    printf("%d ", head->data);
    display(head->next);
}

void reverse_display(struct node *head) {
    if (head == NULL)
        return;
    reverse_display(head->next);
    printf("%d ", head->data);
}

void cleanup(struct node **head) {
    struct node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct node *head;
    init(&head);
    insert_front(&head, 5);
    insert_end(&head, 10);
    insert_front(&head, 3);
    insert_after(&head, 7, 5);
    printf("Original list : ");
    display(head);
    printf("\nReversed list : ");
    reverse_display(head);
    printf("\n");
    delete_node(&head, 3);
    delete_node(&head, 5);
    delete_node(&head, 10);
    delete_node(&head, 15);
    printf("List after deletion : ");
    display(head);
    printf("\n");
    cleanup(&head);
    return 0;
}