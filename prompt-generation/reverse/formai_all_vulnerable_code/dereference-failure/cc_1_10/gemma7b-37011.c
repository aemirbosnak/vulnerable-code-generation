//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 23

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int powMod(int a, int b, int n) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
        result %= n;
    }

    return result;
}

int main() {
    Node* pubKey = insertAtTail(NULL, 3);
    insertAtTail(pubKey, 5);
    insertAtTail(pubKey, 11);

    int msg = 13;
    int encMsg = powMod(pubKey->data, msg, MOD);

    printf("Original message: %d\n", msg);
    printf("Encrypted message: %d\n", encMsg);

    int decMsg = powMod(powMod(pubKey->data, -1, MOD), encMsg, MOD);

    printf("Decrypted message: %d\n", decMsg);

    return 0;
}