//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 21

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Encrypt(Node* key, Node* msg) {
    while (msg) {
        msg->data ^= key->data;
        msg = msg->next;
    }
}

void Decrypt(Node* key, Node* msg) {
    while (msg) {
        msg->data ^= key->data;
        msg = msg->next;
    }
}

int main() {
    // Create a secret key
    Node* key = malloc(sizeof(Node));
    key->data = 3;
    key->next = malloc(sizeof(Node));
    key->next->data = 5;
    key->next->next = NULL;

    // Create a message
    Node* msg = malloc(sizeof(Node));
    msg->data = 12;
    msg->next = malloc(sizeof(Node));
    msg->next->data = 14;
    msg->next->next = NULL;

    // Encrypt the message
    Encrypt(key, msg);

    // Decrypt the message
    Decrypt(key, msg);

    // Print the decrypted message
    while (msg) {
        printf("%d ", msg->data);
        msg = msg->next;
    }

    return 0;
}