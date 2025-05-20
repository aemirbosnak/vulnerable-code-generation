//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void addNode(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int countNodes(Node *head) {
    int count = 0;
    while (head!= NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int sumList(Node *head) {
    int sum = 0;
    while (head!= NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int averageList(Node *head) {
    int sum = 0;
    int count = 0;
    while (head!= NULL) {
        sum += head->data;
        count++;
        head = head->next;
    }
    return (sum / count);
}

int maxList(Node *head) {
    int max = head->data;
    while (head!= NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

int minList(Node *head) {
    int min = head->data;
    while (head!= NULL) {
        if (head->data < min) {
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

int main() {
    Node *head = NULL;
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);
    addNode(&head, 25);
    printList(head);
    printf("Number of nodes: %d\n", countNodes(head));
    printf("Sum of list: %d\n", sumList(head));
    printf("Average of list: %.2f\n", averageList(head));
    printf("Maximum value: %d\n", maxList(head));
    printf("Minimum value: %d\n", minList(head));
    return 0;
}