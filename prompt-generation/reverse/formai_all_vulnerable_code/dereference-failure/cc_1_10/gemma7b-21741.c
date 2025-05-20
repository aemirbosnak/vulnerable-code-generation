//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* compress(char* str, int str_len) {
    Node* head = NULL;
    int i = 0;
    int count = 1;

    for (; i < str_len && str[i] == str[i-1]; i++) {
        count++;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = str[i];
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;

    return head;
}

int main() {
    char str[] = "aabbbb";
    int str_len = strlen(str);

    Node* head = compress(str, str_len);

    printf("Compressed string:");

    while (head) {
        printf("%c ", head->data);
        printf("%d ", head->next ? head->next->data - head->data : -1);

        head = head->next;
    }

    printf("\n");

    return 0;
}