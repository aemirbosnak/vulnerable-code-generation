//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Complex {
    int real;
    int img;
} Complex;

void complex_add(Complex* a, Complex* b) {
    a->real = b->real + a->real;
    a->img = b->img + a->img;
}

void complex_mul(Complex* a, Complex* b) {
    int tmp_real = a->real * b->real - a->img * b->img;
    int tmp_img = a->real * b->img + a->img * b->real;
    a->real = tmp_real;
    a->img = tmp_img;
}

void insert_node(Node** head, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

int main() {
    Node* head = NULL;
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);

    Complex* a = malloc(sizeof(Complex));
    a->real = 5;
    a->img = 10;

    Complex* b = malloc(sizeof(Complex));
    b->real = 15;
    b->img = 20;

    complex_add(a, b);

    printf("The result of the addition is: %.2f + %.2fi\n", a->real, a->img);

    complex_mul(a, b);

    printf("The result of the multiplication is: %.2f + %.2fi\n", a->real, a->img);

    return 0;
}