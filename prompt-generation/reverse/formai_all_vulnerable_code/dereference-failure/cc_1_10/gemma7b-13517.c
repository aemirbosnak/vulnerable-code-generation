//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024

typedef struct Node {
    char key[MAX_KEY_LENGTH];
    struct Node* next;
} Node;

Node* Insert(Node* head, char* key) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void Encrypt(Node* head, char* message) {
    Node* current = head;
    char* pos = message;

    while (current && pos) {
        char key = current->key[0];
        int offset = (int)key - (int)'a';
        int encryptedPosition = (int)pos - offset;
        char encryptedChar = (char)('a' + encryptedPosition);
        *pos = encryptedChar;
        current = current->next;
        pos++;
    }
}

int main() {
    Node* head = NULL;
    Insert(head, "abc");
    Insert(head, "def");
    Insert(head, "ghi");

    char message[] = "Hello, world!";
    Encrypt(head, message);

    printf("%s", message);

    return 0;
}