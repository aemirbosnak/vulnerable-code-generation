//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define TAG_MAX_LENGTH 64
#define VALUE_MAX_LENGTH 256

typedef struct Node {
    char tag[TAG_MAX_LENGTH];
    char value[VALUE_MAX_LENGTH];
    struct Node *next;
} Node;

Node* createNode(const char *tag, const char *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, TAG_MAX_LENGTH);
    strncpy(newNode->value, value, VALUE_MAX_LENGTH);
    newNode->next = NULL;
    return newNode;
}

void freeList(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}

Node* parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }
    
    char line[MAX_LINE_LENGTH];
    Node *head = NULL;
    Node *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *tagStart = strchr(line, '<');
        char *tagEnd = strchr(line, '>');
        
        if (tagStart != NULL && tagEnd != NULL && tagStart < tagEnd) {
            *tagEnd = '\0'; // terminate the string at the end tag
            char *tag = tagStart + 1; // move past '<'
            char *valueStart = tagEnd + 1;
            char *valueEnd = strchr(valueStart, '<');

            if (valueEnd != NULL) {
                *valueEnd = '\0'; // terminate the string at the start of the next tag
                Node *newNode = createNode(tag, valueStart);
                if (head == NULL) {
                    head = newNode; // first node
                    tail = newNode;
                } else {
                    tail->next = newNode; // append to the end of the list
                    tail = newNode;
                }
            }
        }
    }

    fclose(file);
    return head;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node *xmlData = parseXML(argv[1]);
    
    if (xmlData != NULL) {
        printList(xmlData);
        freeList(xmlData);
    }

    return EXIT_SUCCESS;
}