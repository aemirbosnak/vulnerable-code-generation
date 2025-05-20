//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWD_LEN 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(Node* head, char data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    head = newNode;
}

int generatePassword(int len) {
    time_t t = time(NULL);
    srand(t);

    Node* head = NULL;
    for (int i = 0; i < len; i++) {
        char data = rand() % 62 + 33;
        insertAtTail(head, data);
    }

    int passwordLength = rand() % (len - 1) + 1;
    char* password = malloc(passwordLength);

    int i = 0;
    for (Node* node = head; node; node = node->next) {
        password[i++] = node->data;
    }

    return passwordLength;
}

int main() {
    int passwordLength = generatePassword(16);
    char* password = malloc(passwordLength);

    passwordLength = generatePassword(16);
    for (int i = 0; i < passwordLength; i++) {
        printf("%c", password[i]);
    }

    return 0;
}