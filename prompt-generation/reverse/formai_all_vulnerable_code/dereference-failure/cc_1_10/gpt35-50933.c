//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

/* Define the struct node which will contains the data and next element pointer */
struct node {
    int data;
    struct node* next;
};

/* Define the function to insert the data at the end of the linked list */
void insertEnd(struct node **head, int data) {
    /* Create the new node to add data */
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    /* Check if the linked list is empty */
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    /* If the linked list is not empty then find the last node */
    struct node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    /* Add the new node to the last element */
    lastNode->next = newNode;
}

/* Define the function to delete a given node from the linked list */
void deleteNode(struct node **head, int key) {
    /* Check if the linked list is empty */
    if (*head == NULL) {
        return;
    }

    /* If the key is present at head node */
    if ((*head)->data == key) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    /* If the key is not present at the head node then find the node to delete */
    struct node *current = *head, *prev;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    /* If the key is not present in the linked list */
    if (current == NULL) {
        return;
    }

    /* Unlink the node from the linked list */
    prev->next = current->next;

    /* Free the memory used by deleted node */
    free(current);
}

/* Define the function to print the linked list */
void printList(struct node *node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Define the main function to test the linked list */
int main() {
    printf("C Linked List Program Example\n");
    printf("=============================\n");

    /* Initialize an empty linked list */
    struct node* head = NULL;

    /* Add some elements at the end of the linked list */
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    /* Print the linked list */
    printList(head);

    /* Delete 40 from the linked list */
    deleteNode(&head, 40);

    /* Print the updated linked list */
    printList(head);

    /* Delete 10 from the linked list */
    deleteNode(&head, 10);

    /* Print the updated linked list */
    printList(head);

    /* Delete 50 from the linked list */
    deleteNode(&head, 50);

    /* Print the updated linked list */
    printList(head);

    return 0;
}