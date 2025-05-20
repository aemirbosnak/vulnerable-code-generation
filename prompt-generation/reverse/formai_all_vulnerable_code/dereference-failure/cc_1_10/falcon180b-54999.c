//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char *data;
    struct node *next;
};

struct node *head = NULL;

void push(char *data) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;

        while (temp->next!= NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct node *temp = head;

    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    push("Hello");
    push("World");
    display();
    pop();
    display();

    return 0;
}