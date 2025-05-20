//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
    struct Node* next;
    int symbol;
    int frequency;
} Node;

void huffman_encode(Node* root, char* str) {
    Node* current = root;
    for (int i = 0; str[i] != '\0'; i++) {
        int symbol = str[i] - 'a';
        current = root;
        while (current->next && current->symbol != symbol) {
            current = current->next;
        }
        if (current->symbol == symbol) {
            current->frequency++;
        } else {
            Node* newNode = malloc(sizeof(Node));
            newNode->next = current->next;
            newNode->symbol = symbol;
            newNode->frequency = 1;
            current->next = newNode;
            current = newNode;
        }
    }
}

void huffman_decode(Node* root, char* str) {
    Node* current = root;
    for (int i = 0; str[i] != '\0'; i++) {
        int symbol = str[i] - 'a';
        current = root;
        while (current->next && current->symbol != symbol) {
            current = current->next;
        }
        if (current->symbol == symbol) {
            current->frequency--;
            if (current->frequency == 0) {
                free(current);
                current = current->next;
            }
        }
    }
}

int main() {
    char str[] = "ABCAABBCA";
    Node* root = NULL;
    huffman_encode(root, str);
    huffman_decode(root, str);
    return 0;
}