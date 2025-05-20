//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

void summarizeText(Node* head) {
    Node* current = head;
    char summary[MAX_BUFFER_SIZE];
    int summaryIndex = 0;

    while (current) {
        char* text = current->data;
        int textLength = 0;

        while (text[textLength] != '\0') {
            textLength++;
        }

        for (int i = 0; i < textLength; i++) {
            if (text[i] == ' ' || text[i] == '\n') {
                summary[summaryIndex] = ' ';
                summaryIndex++;
            } else {
                summary[summaryIndex] = text[i];
                summaryIndex++;
            }
        }

        summary[summaryIndex] = '\0';

        printf("%s\n", summary);
    }
}

int main() {
    Node* head = NULL;

    // Create a few nodes
    Node* node1 = malloc(sizeof(Node));
    node1->data[0] = 'A';
    node1->data[1] = 'B';
    node1->data[2] = 'C';
    node1->data[3] = '\0';
    node1->next = NULL;

    Node* node2 = malloc(sizeof(Node));
    node2->data[0] = 'D';
    node2->data[1] = 'E';
    node2->data[2] = 'F';
    node2->data[3] = '\0';
    node2->next = NULL;

    head = node1;
    head->next = node2;

    summarizeText(head);

    return 0;
}