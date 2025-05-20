//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *newNode(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

void xmlParse(char *xmlStr) {
    Node *head = NULL;
    char *ptr = xmlStr;
    char tag[255];
    int i = 0;

    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            i = 0;
            while (*ptr && *ptr != '>' && i < 255) {
                tag[i] = *ptr;
                ptr++;
                i++;
            }
            tag[i] = '\0';
            newNode(tag);
        }
        ptr++;
    }

    while (head) {
        printf("%s\n", head->data);
        free(head->data);
        free(head);
        head = head->next;
    }
}

int main() {
    char xmlStr[] = "<root><foo>bar</foo></root>";
    xmlParse(xmlStr);

    return 0;
}