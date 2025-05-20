//Falcon-180B DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* curr = NULL;
    int i;

    for(i = 0; i < n; i++) {
        curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        curr->next = NULL;

        if(head == NULL) {
            head = curr;
        }
        else {
            Node* temp = head;
            while(temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* curr = head;

    while(curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    Node* linkedList = createLinkedList(5);
    printf("Linked List: ");
    printLinkedList(linkedList);

    free(linkedList);

    return 0;
}