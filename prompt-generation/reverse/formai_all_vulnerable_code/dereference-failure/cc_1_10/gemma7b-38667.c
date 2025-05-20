//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void compress(char* str) {
    Node* head = NULL;
    Node* tail = NULL;
    int i = 0;
    int count = 1;
    char prevChar = str[0];

    while (str[i] != '\0') {
        if (str[i] == prevChar) {
            count++;
        } else {
            if (head == NULL) {
                head = tail = malloc(sizeof(Node));
                head->data = str[i];
                head->next = NULL;
            } else {
                tail->next = malloc(sizeof(Node));
                tail = tail->next;
                tail->data = str[i];
                tail->next = NULL;
            }
            prevChar = str[i];
            count = 1;
        }
        i++;
    }

    if (tail) {
        tail->next = NULL;
    }

    str = malloc(sizeof(char) * (i + 1));
    i = 0;

    while (head) {
        str[i++] = head->data;
        if (head->next) {
            str[i++] = count - 1;
        }
        free(head);
        head = head->next;
    }

    str[i] = '\0';

    printf("%s", str);
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);
    return 0;
}