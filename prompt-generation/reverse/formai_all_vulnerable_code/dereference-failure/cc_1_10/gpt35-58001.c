//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

/* Define struct for a node in linked list */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function to add a new Node to the end of a Linked List */
void append(Node **head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d added to linked list\n", data);
}

/* Function to insert a new Node at a specified position in Linked List */
void insert(Node **head, int data, int position) {
    /* Check if position is valid */
    if (position < 0) {
        printf("Invalid position %d\n", position);
        return;
    }

    /* Create new Node */
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        /* If linked list is empty, insert at beginning */
        if (position == 0) {
            newNode->next = NULL;
            *head = newNode;
        } else {
            printf("Invalid position %d\n", position);
            return;
        }
    } else {
        if (position == 0) {
            /* Insert at beginning */
            newNode->next = *head;
            *head = newNode;
        } else {
            Node *temp = *head;
            Node *prev = NULL;
            int i = 0;

            /* Traverse linked list to find insertion position */
            while (temp->next != NULL && i < position) {
                prev = temp;
                temp = temp->next;
                i++;
            }

            /* Insert Node at specified position */
            if (i == position) {
                prev->next = newNode;
                newNode->next = temp;
            } else {
                printf("Invalid position %d\n", position);
                return;
            }
        }
    }
    printf("%d added to linked list at position %d\n", data, position);
}

/* Function to remove a Node from a Linked List */
void removeNode(Node **head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    /* Traverse linked list to find Node to be deleted */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        /* If Node is not found */
        printf("Node with value %d not found\n", key);
    } else {
        /* Remove Node */
        if (prev == NULL) {
            /* If Node to be deleted is first Node */
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Node with value %d removed from linked list\n", key);
    }
}

/* Function to print all Nodes in a Linked List */
void printList(Node *head) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    Node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    /* Add Nodes to Linked List */
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    /* Insert Node at position 2 */
    insert(&head, 10, 2);

    /* Remove Node with value 3 */
    removeNode(&head, 3);

    /* Print Linked List */
    printList(head);

    return 0;
}