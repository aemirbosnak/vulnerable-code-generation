//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void enqueue(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }
    int data = head->data;
    struct node *temp = head;
    head = head->next;
    free(temp);
    return data;
}

void display() {
    struct node *curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    printf("%d ", dequeue());
    display();
    printf("%d ", dequeue());
    display();
    printf("%d ", dequeue());
    display();
    printf("%d ", dequeue());
    display();
    printf("%d ", dequeue());
    display();
    printf("%d ", dequeue());
    display();
    return 0;
}