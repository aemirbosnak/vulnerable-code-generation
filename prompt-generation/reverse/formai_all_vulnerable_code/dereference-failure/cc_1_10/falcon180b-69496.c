//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// define a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// create a linked list
Node* createList(int n) {
    Node* head = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

// print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// free memory allocated to a linked list
void freeList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        free(temp);
        temp = temp->next;
    }
}

// main function
int main() {
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    Node* head = createList(n);
    printf("Original linked list:\n");
    printList(head);
    Node* reversedHead = reverseList(head);
    printf("Reversed linked list:\n");
    printList(reversedHead);
    freeList(head);
    freeList(reversedHead);
    return 0;
}