//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

void freeNode(struct Node* node) {
    free(node->data);
    free(node);
}

int main() {
    char xml_data[] = "<foo><bar>baz</bar></foo>";
    char* buffer = malloc(MAX_BUFFER_SIZE);
    int buffer_size = 0;
    struct Node* head = NULL;

    for (int i = 0; xml_data[i] != '\0'; i++) {
        if (buffer_size == MAX_BUFFER_SIZE) {
            buffer_size = 0;
            buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
        }

        buffer[buffer_size++] = xml_data[i];

        if (xml_data[i] == '<' && xml_data[i + 1] == '>' && head == NULL) {
            head = malloc(sizeof(struct Node));
            head->next = NULL;
            head->data = strdup(buffer);
        } else if (xml_data[i] == '>' && head) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode->next = NULL;
            newNode->data = strdup(buffer);
            head->next = newNode;
            head = newNode;
        }
    }

    free(buffer);

    for (struct Node* node = head; node; node = node->next) {
        printf("%s\n", node->data);
    }

    return 0;
}