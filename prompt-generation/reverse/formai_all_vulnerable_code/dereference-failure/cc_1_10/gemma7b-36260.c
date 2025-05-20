//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Matrix {
    Node** matrix;
    int size;
};

void generateQR(char* str) {
    struct Matrix* matrix = malloc(sizeof(struct Matrix));
    matrix->size = MAX_SIZE;
    matrix->matrix = malloc(sizeof(Node*) * matrix->size);

    for (int i = 0; i < matrix->size; i++) {
        matrix->matrix[i] = NULL;
    }

    int len = strlen(str);
    int i = 0;
    while (i < len) {
        char data = str[i];
        Node* node = malloc(sizeof(Node));
        node->data = data;
        node->next = matrix->matrix[len - 1 - i];
        matrix->matrix[len - 1 - i] = node;
        i++;
    }

    // Print QR code
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; matrix->matrix[i] && j < matrix->size; j++) {
            printf("%c ", matrix->matrix[i]->data);
        }
        printf("\n");
    }

    free(matrix->matrix);
    free(matrix);
}

int main() {
    generateQR("Hello, world!");
    return 0;
}