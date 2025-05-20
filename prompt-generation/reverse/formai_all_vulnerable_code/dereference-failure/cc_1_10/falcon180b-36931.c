//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insert_at_end(int data) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node *lastnode = head;
    while (lastnode->next!= NULL) {
        lastnode = lastnode->next;
    }
    lastnode->next = newnode;
}

void insert_at_position(int data, int position) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (position == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range\n");
            exit(0);
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_element(int data) {
    struct node *temp = head;
    struct node *prev = NULL;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100;
        insert_at_end(data);
    }
    display();
    delete_element(50);
    display();
    insert_at_position(77, 5);
    display();
    return 0;
}