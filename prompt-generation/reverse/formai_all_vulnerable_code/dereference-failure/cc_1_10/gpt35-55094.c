//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void appendNode(struct Node** headRef, int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* lastNode = *headRef;
    newNode->val = val;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = newNode;
    return;
}

void deallocList(struct Node** headRef) {
    struct Node* currNode = *headRef;
    struct Node* nextNode;
    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
    *headRef = NULL;
}

int main() {
    struct Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    printf("List before deallocation: ");
    struct Node* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->val);
        currNode = currNode->next;
    }
    deallocList(&head);
    printf("\nList after deallocation: ");
    currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->val);
        currNode = currNode->next;
    }
    return 0;
}