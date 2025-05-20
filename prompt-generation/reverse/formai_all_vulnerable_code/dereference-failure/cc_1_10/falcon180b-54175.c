//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
};

void insert(struct node** head, char* str) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->size = strlen(str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void search(struct node* head, char* str) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Element found with size %d\n", temp->size);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

int main() {
    struct node* head = NULL;

    insert(&head, "apple");
    insert(&head, "banana");
    insert(&head, "orange");
    insert(&head, "pear");

    search(head, "banana");
    search(head, "grape");

    return 0;
}