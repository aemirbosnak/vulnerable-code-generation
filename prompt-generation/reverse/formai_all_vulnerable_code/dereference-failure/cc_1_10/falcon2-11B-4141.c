//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void delete(Node** head_ref, int data) {
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (*head_ref == NULL)
        return;
    else {
        while(temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
    }
}

int search(Node* head, int data) {
    Node* temp = head;
    while(temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if(temp == NULL)
        return -1;
    else
        return 1;
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    delete(&head, 4);
    printf("Linked list after deletion of 4: ");
    while(head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
    int result = search(head, 4);
    printf("Search result: %d\n", result);
    return 0;
}