//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 100

typedef struct {
    double value;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void addNode(double value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printList() {
    node *current = head;
    printf("List content:\n");
    while (current != NULL) {
        printf("%.2lf ", current->value);
        current = current->next;
    }
    printf("\n");
}

void calculateSum() {
    node *current = head;
    double sum = 0.0;
    while (current != NULL) {
        sum += current->value;
        current = current->next;
    }
    printf("Sum of the list elements: %.2lf\n", sum);
}

void calculateAverage() {
    node *current = head;
    double sum = 0.0, count = 0.0;
    while (current != NULL) {
        sum += current->value;
        count++;
        current = current->next;
    }
    printf("Average of the list elements: %.2lf\n", sum / count);
}

void calculateDifference() {
    node *current1 = head, *current2 = NULL;
    double difference = 0.0;

    if (head == NULL || head->next == NULL) {
        printf("At least two elements required for the difference calculation.\n");
        return;
    }

    while (current1 != NULL && current1->next != NULL) {
        current2 = current1->next;
        difference = fabs(current1->value - current2->value);
        printf("Difference between %lf and %lf: %.2lf\n", current1->value, current2->value, difference);
        current1 = current1->next;
    }
}

void calculateProduct() {
    node *current = head;
    double product = 1.0;
    while (current != NULL) {
        product *= current->value;
        current = current->next;
    }
    printf("Product of the list elements: %.2lf\n", product);
}

int main() {
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        double randomNumber = (double) rand() / RAND_MAX * 100.0;
        addNode(randomNumber);
    }

    printList();
    calculateSum();
    calculateAverage();
    calculateDifference();
    calculateProduct();

    return 0;
}