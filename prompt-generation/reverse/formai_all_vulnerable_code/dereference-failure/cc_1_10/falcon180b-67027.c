//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    int key;
    struct Node* next;
};

struct Node* create_node(int data, int key) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct Node** head, int data, int key) {
    struct Node* new_node = create_node(data, key);
    struct Node* temp = *head;

    if (*head == NULL || new_node->key < temp->key) {
        new_node->next = temp;
        *head = new_node;
    } else {
        while (temp->next!= NULL && temp->next->key < new_node->key) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_node(struct Node** head, int key) {
    struct Node* temp = *head;

    if (temp!= NULL && temp->key == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp!= NULL && temp->key!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search_node(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp!= NULL) {
        if (temp->key == key) {
            printf("Data found: %d\n", temp->data);
            return;
        }
        temp = temp->next;
    }

    printf("Data not found\n");
}

int main() {
    struct Node* head = NULL;

    insert_node(&head, 10, 100);
    insert_node(&head, 20, 200);
    insert_node(&head, 30, 300);
    insert_node(&head, 40, 400);
    insert_node(&head, 50, 500);

    search_node(head, 20);
    search_node(head, 25);

    delete_node(&head, 30);

    search_node(head, 30);

    return 0;
}