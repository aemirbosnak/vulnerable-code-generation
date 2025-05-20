//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct XMLNode *next;
} XMLNode;

XMLNode *createNode(const char *tag, const char *content) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    strncpy(node->content, content, MAX_LINE_LENGTH);
    node->next = NULL;
    return node;
}

void freeNodes(XMLNode *head) {
    XMLNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    XMLNode *head = NULL, *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char content[MAX_LINE_LENGTH];
        if (sscanf(line, "<%[^>]>%[^<]<%*[^>]>", tag, content) == 2) {
            XMLNode *newNode = createNode(tag, content);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    fclose(file);

    // Print parsed content
    printf("Parsed XML Content:\n");
    XMLNode *current = head;
    while (current != NULL) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }

    freeNodes(head);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    parseXML(argv[1]);
    return 0;
}