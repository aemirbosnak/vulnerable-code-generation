//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

void parser(char* xml) {
    Node* head = NULL;
    Node* tail = NULL;
    char* ptr = xml;
    char* tag = NULL;
    char* content = NULL;

    while (*ptr) {
        switch (*ptr) {
            case '<':
                tag = ptr + 1;
                while (*ptr && *ptr != '>') {
                    ptr++;
                }
                if (tail) {
                    tail->next = malloc(sizeof(Node));
                    tail = tail->next;
                } else {
                    head = tail = malloc(sizeof(Node));
                }
                strcpy(tail->data, tag);
                break;
            case '>':
                content = ptr + 1;
                while (*ptr && *ptr != '<') {
                    ptr++;
                }
                strcpy(tail->data, content);
                tail = head;
                break;
        }
        ptr++;
    }

    printf("XML Data:");
    for (tail = head; tail; tail = tail->next) {
        printf("\n%s: %s", tail->data, tail->data);
    }
}

int main() {
    parser("<root><person><name>John Doe</name><age>30</age></person></root>");
    return 0;
}