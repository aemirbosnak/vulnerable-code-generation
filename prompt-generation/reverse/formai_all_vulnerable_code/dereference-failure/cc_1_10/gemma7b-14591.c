//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 11

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void powmod(int a, int b, int n) {
    Node* exp = NULL;
    Node* base = NULL;
    Node* result = NULL;

    base = malloc(sizeof(Node));
    base->data = a;
    base->next = NULL;

    exp = malloc(sizeof(Node));
    exp->data = b;
    exp->next = NULL;

    result = exponentiation(base, exp, n);

    printf("%d", result->data);

    free(exp);
    free(base);
    free(result);
}

int exponentiation(Node* base, Node* exp, int n) {
    Node* result = NULL;

    if (exp->data == 0) {
        result = malloc(sizeof(Node));
        result->data = 1;
        result->next = NULL;
        return result;
    }

    result = exponentiation(base, exp->next, n);

    if (exp->data % 2 == 0) {
        result = multiply(result, base, n);
    }

    return result;
}

int multiply(Node* a, Node* b, int n) {
    Node* product = NULL;
    Node* carry = NULL;

    product = malloc(sizeof(Node));
    product->data = 0;
    product->next = NULL;

    carry = malloc(sizeof(Node));
    carry->data = 0;
    carry->next = NULL;

    for (int i = n - 1; i >= 0; i--) {
        int product_digit = a->data * b->data % MOD + carry->data;
        carry->data = product_digit / MOD;
        product->data = product_digit % MOD;

        a = a->next;
        b = b->next;
    }

    return product;
}

int main() {
    powmod(3, 5, MOD);
    return 0;
}