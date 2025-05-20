//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    head = insertNode(head, 5);
    head = insertNode(head, 3);
    head = insertNode(head, 7);
    head = insertNode(head, 2);
    head = insertNode(head, 4);
    head = insertNode(head, 6);
    head = insertNode(head, 8);

    int searchData = 7;
    struct node* searchResult = searchNode(head, searchData);

    if (searchResult!= NULL) {
        printf("Element %d found in the list\n", searchData);
    } else {
        printf("Element %d not found in the list\n", searchData);
    }

    display(head);

    return 0;
}