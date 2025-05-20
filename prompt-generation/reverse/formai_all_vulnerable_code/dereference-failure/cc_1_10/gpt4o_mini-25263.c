//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *tag;
    char *content;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} XMLDocument;

void initXMLDocument(XMLDocument *doc) {
    doc->head = NULL;
}

Node* createNode(const char *tag, const char *content) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->tag = strdup(tag);
    newNode->content = strdup(content);
    newNode->next = NULL;
    return newNode;
}

void addNode(XMLDocument *doc, const char *tag, const char *content) {
    Node *newNode = createNode(tag, content);
    if (doc->head == NULL) {
        doc->head = newNode;
    } else {
        Node *current = doc->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeNode(Node *node) {
    if (node) {
        free(node->tag);
        free(node->content);
        free(node);
    }
}

void freeXMLDocument(XMLDocument *doc) {
    Node *current = doc->head;
    while (current) {
        Node *next = current->next;
        freeNode(current);
        current = next;
    }
    doc->head = NULL;
}

void parseXML(const char *filename, XMLDocument *doc) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *startTag = strchr(line, '<');
        char *endTag = strchr(line, '>');

        if (startTag && endTag) {
            *endTag = '\0'; // Null-terminate the tag
            char *tag = startTag + 1; // Skip the '<'
            char *content = endTag + 1; // Move to content
            char *endContent = strchr(content, '<');

            if (endContent) {
                *endContent = '\0'; // Null-terminate content
                addNode(doc, tag, content);
            }
        }
    }
    fclose(file);
}

void printXMLDocument(const XMLDocument *doc) {
    Node *current = doc->head;
    while (current) {
        printf("<%s>%s</%s>\n", current->tag, current->content, current->tag);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLDocument doc;
    initXMLDocument(&doc);

    parseXML(argv[1], &doc);
    printXMLDocument(&doc);

    freeXMLDocument(&doc);
    return EXIT_SUCCESS;
}