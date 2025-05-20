//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void generateQrCode(char* str) {
    int length = strlen(str);
    Node* head = NULL;

    for (int i = 0; i < length; i++) {
        insertAtTail(head, str[i]);
    }

    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    int matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }

    int i = 0;
    while (head) {
        matrix[i][0] = 1;
        matrix[i][i] = 1;
        i++;
        head = head->next;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("----------------------------\n");
}

int main() {
    generateQrCode("HELLO WORLD");
    return 0;
}