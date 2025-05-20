//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 101

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
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

int main() {
  Node* publicKey = insert(NULL, 3);
  publicKey = insert(publicKey, 5);
  publicKey = insert(publicKey, 7);

  Node* privateKey = insert(NULL, 11);
  privateKey = insert(privateKey, 13);
  privateKey = insert(privateKey, 15);

  int message = 19;

  int encryptedMessage = encrypt(publicKey, message);
  int decryptedMessage = decrypt(privateKey, encryptedMessage);

  printf("Message: %d\n", message);
  printf("Encrypted Message: %d\n", encryptedMessage);
  printf("Decrypted Message: %d\n", decryptedMessage);

  return 0;
}

int encrypt(Node* publicKey, int message) {
  int product = 1;

  for (Node* node = publicKey; node != NULL; node++) {
    product *= node->data;
  }

  return (message * product) % MOD;
}

int decrypt(Node* privateKey, int encryptedMessage) {
  int product = 1;

  for (Node* node = privateKey; node != NULL; node++) {
    product *= node->data;
  }

  return (encryptedMessage * product) % MOD;
}