//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    struct node* next;
};

void insert(struct node** head, char* data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    strcpy(new_node->data, data);

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(struct node* head, char* key) {
    struct node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, key) == 0) {
            printf("Key found!\n");
            return;
        }
        current = current->next;
    }
    printf("Key not found.\n");
}

int main() {
    struct node* head = NULL;

    insert(&head, "apple");
    insert(&head, "banana");
    insert(&head, "cherry");

    search(head, "banana");
    search(head, "orange");

    return 0;
}