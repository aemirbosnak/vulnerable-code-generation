//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node *temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void delete(int data) {
    node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    node *prev = temp->next;
    temp->next = prev->next;
    free(prev);
}

void search(int data) {
    node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found\n");
}

void display() {
    node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    search(30);

    delete(20);

    display();

    return 0;
}