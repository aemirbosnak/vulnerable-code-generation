//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MatrixNode {
    int rows;
    int cols;
    int **data;
    struct MatrixNode *next, *prev;
} MatrixNode;

void createMatrix(MatrixNode **head, int rows, int cols) {
    MatrixNode *newNode = (MatrixNode *)malloc(sizeof(MatrixNode));

    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }

    newNode->rows = rows;
    newNode->cols = cols;

    newNode->data = (int **)calloc(rows, sizeof(int *));
    if (newNode->data == NULL) {
        printf("Memory error\n");
        free(newNode);
        return;
    }

    for (int i = 0; i < rows; i++) {
        newNode->data[i] = (int *)calloc(cols, sizeof(int));
        if (newNode->data[i] == NULL) {
            printf("Memory error\n");
            for (int j = 0; j < i; j++)
                free(newNode->data[j]);
            free(newNode->data);
            free(newNode);
            return;
        }
    }

    if (*head != NULL)
        (*head)->prev = newNode;

    newNode->next = *head;
    *head = newNode;
}

void printMatrix(MatrixNode *node) {
    printf("\nMatrix %p:\n", node);
    printf("Rows: %d, Cols: %d\n", node->rows, node->cols);

    printf("\nData:\n");
    for (int i = 0; i < node->rows; i++) {
        for (int j = 0; j < node->cols; j++) {
            printf("%d ", node->data[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(MatrixNode **head) {
    while (*head != NULL) {
        MatrixNode *temp = *head;
        *head = (*head)->next;

        for (int i = 0; i < temp->rows; i++)
            free(temp->data[i]);
        free(temp->data);

        free(temp);
    }
}

int main() {
    MatrixNode *head = NULL;

    createMatrix(&head, 3, 3);
    printMatrix(head);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            head->data[i][j] = i * 3 + j;
        }
    }

    printMatrix(head);

    freeMatrix(&head);

    return 0;
}