//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    return head;
}

void insert(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void deleteNode(Node** head_ref) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (*head_ref!= NULL) {
        while (temp->next!= NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Node* head = createList();

    for (int i = 0; i < MAX_SIZE; i++) {
        int rand_num = rand() % 100;
        insert(&head, rand_num);
    }

    printList(head);
    printf("\n");

    deleteNode(&head);
    printList(head);

    return 0;
}