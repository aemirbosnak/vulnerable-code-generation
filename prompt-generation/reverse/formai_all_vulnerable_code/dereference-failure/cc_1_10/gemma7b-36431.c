//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* compress(char* str) {
    int i = 0, count = 1, node_size = 0, total_size = 0;
    Node* head = NULL;
    char* buffer = NULL;

    buffer = malloc(MAX_BUFFER_SIZE);

    while (str[i] != '\0') {
        char current_char = str[i];
        Node* current_node = head;

        if (head == NULL) {
            head = malloc(sizeof(Node));
            head->data = current_char;
            head->next = NULL;
        } else {
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = malloc(sizeof(Node));
            current_node->next->data = current_char;
            current_node->next->next = NULL;
        }

        if (current_char == str[i - 1]) {
            count++;
        } else {
            buffer[total_size++] = str[i - 1];
            buffer[total_size++] = count - 1;
            count = 1;
        }
        i++;
    }

    buffer[total_size++] = str[i - 1];
    buffer[total_size++] = count - 1;

    return head;
}

int main() {
    char* str = "aabbbb";
    Node* head = compress(str);

    printf("Compressed string:");
    for (Node* node = head; node; node = node->next) {
        printf("%c ", node->data);
    }

    printf("\n");

    return 0;
}