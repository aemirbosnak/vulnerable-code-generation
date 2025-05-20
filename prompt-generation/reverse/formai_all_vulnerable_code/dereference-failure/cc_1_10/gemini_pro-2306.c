//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct matrix {
    int rows;
    int cols;
    int **data;
};

struct matrix_operation {
    struct matrix *a;
    struct matrix *b;
    struct matrix *result;
    int operation; // 0 for addition, 1 for subtraction, 2 for multiplication
};

void *matrix_add(void *arg) {
    struct matrix_operation *op = (struct matrix_operation *)arg;
    for (int i = 0; i < op->a->rows; i++) {
        for (int j = 0; j < op->a->cols; j++) {
            op->result->data[i][j] = op->a->data[i][j] + op->b->data[i][j];
        }
    }
    return NULL;
}

void *matrix_subtract(void *arg) {
    struct matrix_operation *op = (struct matrix_operation *)arg;
    for (int i = 0; i < op->a->rows; i++) {
        for (int j = 0; j < op->a->cols; j++) {
            op->result->data[i][j] = op->a->data[i][j] - op->b->data[i][j];
        }
    }
    return NULL;
}

void *matrix_multiply(void *arg) {
    struct matrix_operation *op = (struct matrix_operation *)arg;
    for (int i = 0; i < op->a->rows; i++) {
        for (int j = 0; j < op->b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < op->a->cols; k++) {
                sum += op->a->data[i][k] * op->b->data[k][j];
            }
            op->result->data[i][j] = sum;
        }
    }
    return NULL;
}

void create_matrix(struct matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *)malloc(sizeof(int) * cols);
    }
}

void free_matrix(struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

void print_matrix(struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2, operation;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    struct matrix *a = (struct matrix *)malloc(sizeof(struct matrix));
    create_matrix(a, rows1, cols1);
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &a->data[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    struct matrix *b = (struct matrix *)malloc(sizeof(struct matrix));
    create_matrix(b, rows2, cols2);
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &b->data[i][j]);
        }
    }
    printf("Enter the operation you want to perform (0 for addition, 1 for subtraction, 2 for multiplication): ");
    scanf("%d", &operation);
    struct matrix *result = (struct matrix *)malloc(sizeof(struct matrix));
    create_matrix(result, rows1, cols2);
    struct matrix_operation op = {a, b, result, operation};
    pthread_t thread;
    if (operation == 0) {
        pthread_create(&thread, NULL, matrix_add, &op);
    } else if (operation == 1) {
        pthread_create(&thread, NULL, matrix_subtract, &op);
    } else if (operation == 2) {
        pthread_create(&thread, NULL, matrix_multiply, &op);
    }
    pthread_join(thread, NULL);
    printf("The result of the operation is:\n");
    print_matrix(result);
    free_matrix(a);
    free_matrix(b);
    free_matrix(result);
    return 0;
}