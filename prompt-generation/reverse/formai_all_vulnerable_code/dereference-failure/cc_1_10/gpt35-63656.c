//FormAI DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for a node in a linked list */
typedef struct ListNode_t {
    int data;
    struct ListNode_t* next;
} ListNode;

/* Define a function to create a new node */
ListNode* createNode(int data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Define a function to insert a node at the front of a linked list */
void insertFront(ListNode** headPtr, int data)
{
    ListNode* newNode = createNode(data);
    newNode->next = *headPtr;
    *headPtr = newNode;
}

/* Define a function to delete a node from a linked list */
void deleteNode(ListNode** headPtr, int data)
{
    ListNode* currNode = *headPtr;
    ListNode* prevNode = NULL;

    while (currNode != NULL && currNode->data != data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    if (prevNode == NULL) {
        *headPtr = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}

/* Define a function to print the contents of a linked list */
void printList(ListNode* head)
{
    ListNode* currNode = head;

    while (currNode != NULL) {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }

    printf("NULL\n");
}

/* Main function to demonstrate the linked list data structure */
int main()
{
    ListNode* head = NULL;

    printf("Welcome to the Linked List Visualization Program!\n");
    printf("We will now insert 5 nodes into our linked list:\n");

    insertFront(&head, 5);
    printf("Inserted node with data 5. Current list: ");
    printList(head);

    insertFront(&head, 3);
    printf("Inserted node with data 3. Current list: ");
    printList(head);

    insertFront(&head, 8);
    printf("Inserted node with data 8. Current list: ");
    printList(head);

    insertFront(&head, 2);
    printf("Inserted node with data 2. Current list: ");
    printList(head);

    insertFront(&head, 1);
    printf("Inserted node with data 1. Current list: ");
    printList(head);

    printf("Now we will delete the node with data 8 and print the list:\n");
    deleteNode(&head, 8);
    printList(head);

    printf("Finally, we will delete the node with data 6 (which does not exist) and print the list:\n");
    deleteNode(&head, 6);
    printList(head);

    printf("Thanks for using the Linked List Visualization Program!\n");

    return 0;
}