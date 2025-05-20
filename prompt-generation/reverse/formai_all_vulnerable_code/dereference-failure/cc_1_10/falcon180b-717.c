//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head, int data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void pop(struct Node **head) {
    struct Node *temp = *head;
    if (temp!= NULL) {
        *head = temp->next;
        free(temp);
    }
}

void stack_traversal(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main() {
    struct Node *head = NULL;
    int choice, data;
    while (1) {
        printf("\n1. PUSH\n2. POP\n3. STACK TRAVERSAL\n4. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("ENTER THE DATA TO BE PUSHED: ");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            stack_traversal(head);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("INVALID CHOICE");
        }
    }
}