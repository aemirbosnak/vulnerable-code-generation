//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node* createNode(int data) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node *lastNode = *head;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int num, i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &num);
    printf("Enter the elements of the list: ");
    for(i=0; i<num; i++) {
        int data;
        scanf("%d", &data);
        insertNode(&head, data);
    }
    printf("The entered list is: ");
    printList(head);
    return 0;
}