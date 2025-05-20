//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node* next;
};

struct node* newNode(char data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct node* insert(struct node* head, char data) {
    struct node* node = newNode(data);
    if (head == NULL) {
        head = node;
        return head;
    }
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

void search(struct node* head, char data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("%c is found in the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%c is not found in the list\n", data);
}

int main() {
    struct node* head = NULL;
    head = insert(head, 'a');
    head = insert(head, 'b');
    head = insert(head, 'c');
    head = insert(head, 'd');
    search(head, 'c');
    search(head, 'e');
    return 0;
}