//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int prime;
    struct Node* next;
} Node;

Node* insertPrime(int prime, Node* head) {
    Node* newNode = malloc(sizeof(Node));
    newNode->prime = prime;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void printPrimes(Node* head) {
    while (head) {
        printf("%d ", head->prime);
        head = head->next;
    }
}

int main() {
    int i, prime, count = 0;
    Node* head = NULL;

    for (i = 0; i < MAX; i++) {
        prime = rand() % MAX + 2;
        if (isPrime(prime)) {
            insertPrime(prime, head);
            count++;
        }
    }

    printf("Total primes generated: %d\n", count);
    printPrimes(head);

    return 0;
}