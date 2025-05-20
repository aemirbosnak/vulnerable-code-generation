//Gemma-7B DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFERSIZE 1024

typedef struct Node {
    int index;
    double value;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, double value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void Filter(Node* head, double cutoff) {
    Node* current = head;
    while (current) {
        double frequency = (current->index) * SAMPLE_RATE;
        if (frequency < cutoff) {
            current->value = 0.0;
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    for (int i = 0; i < BUFFERSIZE; i++) {
        InsertAtTail(head, sin(i / SAMPLE_RATE));
    }

    Filter(head, 2000);

    for (int i = 0; i < BUFFERSIZE; i++) {
        printf("%f ", head->value);
        head = head->next;
    }

    printf("\n");

    return 0;
}