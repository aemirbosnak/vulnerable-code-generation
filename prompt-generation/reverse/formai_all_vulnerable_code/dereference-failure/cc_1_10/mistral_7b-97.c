//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    double sum;
    double variance;
    double stddev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->sum = 0.0;
    newNode->variance = 0.0;
    newNode->stddev = 0.0;
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void calculateStats(Node* head) {
    Node* current = head;
    double sum = 0.0;
    int count = 0;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }

    current = head;
    double avg = sum / count;

    while (current != NULL) {
        current->sum += current->data;
        current->variance += pow(current->data - avg, 2);
        current = current->next;
    }

    current = head;
    double totalVariance = 0.0;

    while (current != NULL) {
        totalVariance += current->variance;
        current->stddev = sqrt(totalVariance / count);
        current = current->next;
    }

    printf("Average: %.2f\n", avg);
    printf("Minimum: %d\n", current->data);
    printf("Maximum: %d\n", head->data);
    printf("Standard Deviation: %.2f\n", current->stddev);
}

int main() {
    Node* head = NULL;
    int numbers[] = {3, 5, 7, 9, 11};

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        addToList(&head, numbers[i]);
    }

    calculateStats(head);

    return 0;
}