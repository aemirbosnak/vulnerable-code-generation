//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>

/* Create a structure for holding a node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function definitions */
void traverse(Node* list);
void insert_beg(Node** list, int data);
void insert_end(Node** list, int data);
void insert_after(Node** list, int insertAfter, int data);
void delete_node(Node** list, int deleteData);

/* Function to traverse the linked list */
void traverse(Node* list) {
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

/* Function to insert a node at the beginning of the list */
void insert_beg(Node** list, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = *list;
    *list = temp;
}

/* Function to insert a node at the end of the list */
void insert_end(Node** list, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    Node* current = *list;
    if(*list == NULL) {
        *list = temp;
    } else {
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

/* Function to insert a node after a specific node */
void insert_after(Node** list, int insertAfter, int data) {
    Node* current = *list;
    while(current != NULL) {
        if(current->data == insertAfter) {
            Node* temp = (Node*) malloc(sizeof(Node));
            temp->data = data;
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    }
    printf("Node %d not found in the list.\n", insertAfter);
}

/* Function to delete a node */
void delete_node(Node** list, int deleteData) {
    Node* temp = *list;
    Node* prev;

    if(temp != NULL && temp->data == deleteData) {
        *list = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != deleteData) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node %d not found in the list.\n", deleteData);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Main function */
int main() {
    Node* list = NULL;

    /* Insert nodes at the beginning */
    insert_beg(&list, 3);
    insert_beg(&list, 2);
    insert_beg(&list, 1);

    printf("List after inserting nodes at the beginning: ");
    traverse(list);

    /* Insert nodes at the end */
    insert_end(&list, 4);
    insert_end(&list, 5);
    insert_end(&list, 6);

    printf("List after inserting nodes at the end: ");
    traverse(list);

    /* Insert nodes after a specific node */
    insert_after(&list, 3, 7);
    insert_after(&list, 5, 8);
    insert_after(&list, 10, 9);

    printf("List after inserting nodes after specific nodes: ");
    traverse(list);

    /* Delete nodes */
    delete_node(&list, 1);
    delete_node(&list, 5);
    delete_node(&list, 10);

    printf("List after deleting nodes: ");
    traverse(list);

    return 0;
}