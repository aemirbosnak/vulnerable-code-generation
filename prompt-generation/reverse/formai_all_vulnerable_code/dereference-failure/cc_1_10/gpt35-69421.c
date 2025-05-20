//FormAI DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// defining structure for our linked list node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node_ptr;  // defining node_ptr to avoid writing struct Node* again and again

// printing the linked list iteratively
void PrintList(node_ptr head) {
    printf("Printing the list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// recursively printing the linked list in reverse order
void PrintReverseList(node_ptr head) {
    if (head == NULL) {
        return;
    }
    PrintReverseList(head->next);
    printf("%d ", head->data);
}

// inserting a new node at the end of the linked list
void AppendNode(node_ptr* headRef, int data) {
    node_ptr newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        node_ptr temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// inserting a new node at the beginning of the linked list
void PushNode(node_ptr* headRef, int data) {
    node_ptr newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// deleting a node with the given key from the linked list
void DeleteNode(node_ptr* headRef, int key) {
    node_ptr temp = *headRef;
    node_ptr prev = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with key %d not found!\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// deleting the entire linked list and freeing the memory
void DeleteList(node_ptr* headRef) {
    node_ptr current = *headRef;
    node_ptr next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;
}

int main() {
    node_ptr head = NULL;
    AppendNode(&head, 1);
    AppendNode(&head, 2);
    AppendNode(&head, 3);
    PushNode(&head, 0);
    printf("List after inserting 1, 2, 3 at the end and 0 at the beginning: ");
    PrintList(head);
    DeleteNode(&head, 5);
    DeleteNode(&head, 2);
    printf("List after deleting node with key 5 and 2: ");
    PrintList(head);
    printf("Printing the list in reverse order: ");
    PrintReverseList(head);
    DeleteList(&head);
    printf("List after deleting all the nodes: ");
    PrintList(head);
    return 0;
}