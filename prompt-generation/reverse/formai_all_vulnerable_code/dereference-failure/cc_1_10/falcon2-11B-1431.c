//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct node* temp = *head_ref;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int dequeue(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    return temp->data;
}

void print_queue(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    print_queue(head);
    printf("Dequeued: %d\n", dequeue(&head));
    print_queue(head);
    printf("Dequeued: %d\n", dequeue(&head));
    print_queue(head);
    return 0;
}