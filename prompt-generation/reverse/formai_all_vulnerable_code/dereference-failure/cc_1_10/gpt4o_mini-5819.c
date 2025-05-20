//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 512
#define MAX_TAG_LENGTH 100

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_BUFFER];
    struct Node *next;
} Node;

Node *createNode(const char *tag, const char *value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, const char *tag, const char *value) {
    Node *newNode = createNode(tag, value);
    newNode->next = *head;
    *head = newNode;
}

void printNodes(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Tag: <%s>, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}

void freeNodes(Node *head) {
    Node *current = head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void parseXML(const char *filename, Node **head) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }
    
    char buffer[MAX_BUFFER];
    char tag[MAX_TAG_LENGTH];
    char value[MAX_BUFFER];
    int readingTag = 1;
    
    while (fgets(buffer, sizeof(buffer), file)) {
        char *startTag = strchr(buffer, '<');
        char *endTag = strchr(buffer, '>');
        
        if (startTag && endTag) {
            int tagLength = endTag - startTag - 1;
            strncpy(tag, startTag + 1, tagLength);
            tag[tagLength] = '\0';

            char *valueStart = endTag + 1;
            char *valueEnd = strchr(valueStart, '<');
            if (valueEnd) {
                int valueLength = valueEnd - valueStart;
                strncpy(value, valueStart, valueLength);
                value[valueLength] = '\0';

                addNode(head, tag, value);
            }
        }
    }
    
    fclose(file);
}

int main() {
    Node *xmlData = NULL;
    const char *filename = "example.xml";

    parseXML(filename, &xmlData);
    
    printf("Parsed XML Data:\n");
    printNodes(xmlData);
    
    freeNodes(xmlData);
    printf("Memory cleaned up. Happy parsing!\n");

    return 0;
}