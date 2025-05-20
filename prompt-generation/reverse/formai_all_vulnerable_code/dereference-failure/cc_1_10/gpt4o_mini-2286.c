//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256
#define MAX_VALUE_LENGTH 512

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node* next;
    struct Node* child;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node* temp = parent->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

Node* parseXML(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    Node* root = NULL;
    Node* current = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char value[MAX_VALUE_LENGTH];

        // Detect tags
        char *openingTag = strstr(line, "<");
        char *closingTag = strstr(line, ">");
        if (openingTag && closingTag) {
            size_t tagLength = closingTag - openingTag + 1;
            strncpy(tag, openingTag + 1, tagLength - 2);
            tag[tagLength - 2] = '\0'; // Null terminate
            char* valueStart = closingTag + 1;
            char* valueEnd = strstr(valueStart, "<");
            if (valueEnd) {
                size_t valueLength = valueEnd - valueStart;
                strncpy(value, valueStart, valueLength);
                value[valueLength] = '\0'; // Null terminate
            } else {
                value[0] = '\0'; // Empty value
            }

            Node* newNode = createNode(tag, value);
            if (root == NULL) {
                root = newNode;
                current = newNode;
            } else {
                addChild(current, newNode);
                current = newNode; // Assume child was just added
            }
        } else if (strstr(line, "</")) {
            current = current->child; // Move up the hierarchy when closing tag
        }
    }

    fclose(file);
    return root;
}

void printXML(Node* node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);

    if (node->child) {
        printXML(node->child, level + 1);
    }
    
    if (node->next) {
        printXML(node->next, level);
    }
}

void startCyberpunkParse(const char *filename) {
    printf("Loading cybernetic XML parser...\n");
    Node* parsedData = parseXML(filename);

    if (parsedData) {
        printf("Parsed XML data:\n");
        printXML(parsedData, 0);
        freeNode(parsedData);
    } else {
        printf("Failed to parse XML data.\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    startCyberpunkParse(argv[1]);
    return EXIT_SUCCESS;
}