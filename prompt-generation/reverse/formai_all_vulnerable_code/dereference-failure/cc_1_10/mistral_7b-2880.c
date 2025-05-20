//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Out of memory!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node* currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return head;
}

Node* removeFirst(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    Node* tempNode = head;
    head = head->next;
    free(tempNode);
    return head;
}

void displayList(Node* head) {
    printf("Curious List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    printf("Let us start our curious LinkedList journey!\n");

    // Inserting numbers in a curious way
    head = insertAtEnd(head, 13);
    head = insertAtEnd(head, 21);
    head = insertAtEnd(head, 31);
    head = insertAtEnd(head, 101);
    head = insertAtEnd(head, 111);
    head = insertAtEnd(head, 121);

    printf("After inserting some curious numbers, let us display our list:\n");
    displayList(head);

    // Removing numbers in a curious way
    head = removeFirst(head);
    printf("After removing the first number, our list now looks curious again:\n");
    displayList(head);

    head = removeFirst(head);
    printf("After removing another first number, our list is becoming more curious:\n");
    displayList(head);

    head = removeFirst(head);
    printf("After removing yet another first number, our list is getting quite curious!\n");
    displayList(head);

    // Inserting numbers again in a curious way
    head = insertAtEnd(head, 201);
    printf("Let us add another number to our curious list:\n");
    displayList(head);

    head = insertAtEnd(head, 251);
    printf("Adding another number to our curious list, hmmm...\n");
    displayList(head);

    head = insertAtEnd(head, 301);
    printf("Adding one more number to our curious list, it is getting curiouser and curiouser!\n");
    displayList(head);

    return 0;
}