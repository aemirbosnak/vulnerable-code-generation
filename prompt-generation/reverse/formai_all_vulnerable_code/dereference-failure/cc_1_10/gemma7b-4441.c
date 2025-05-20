//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

typedef struct Node {
    char data[KEY_LENGTH];
    struct Node* next;
} Node;

void encrypt(Node* head, char key[]) {
    Node* current = head;
    while (current) {
        for (int i = 0; i < KEY_LENGTH; i++) {
            int offset = (int)key[i] - (int)key[0];
            current->data[i] ^= offset;
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data[0] = 'A';
    head->data[1] = 'B';
    head->data[2] = 'C';
    head->next = malloc(sizeof(Node));
    head->next->data[0] = 'D';
    head->next->data[1] = 'E';
    head->next->data[2] = 'F';
    head->next->next = malloc(sizeof(Node));
    head->next->next->data[0] = 'G';
    head->next->next->data[1] = 'H';
    head->next->next->data[2] = 'I';

    char key[] = "SECRET";

    encrypt(head, key);

    Node* current = head;
    while (current) {
        for (int i = 0; i < KEY_LENGTH; i++) {
            printf("%c ", current->data[i] ^ key[i]);
        }
        printf("\n");
        current = current->next;
    }

    return 0;
}