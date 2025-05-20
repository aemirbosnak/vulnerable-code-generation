//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node* next;
    struct Node* children;
} Node;

// Function prototypes
Node* createNode(const char* tag, const char* value);
void addChild(Node* parent, Node* child);
void freeNode(Node* node);
void parseXMLLine(const char* line, Node* parent);
void printXML(Node* node, int depth);
void trimWhitespace(char* str);

// Create a new Node
Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

// Add a child to a parent Node
void addChild(Node* parent, Node* child) {
    if (!parent->children) {
        parent->children = child;
    } else {
        Node* temp = parent->children;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

// Free a Node and its children
void freeNode(Node* node) {
    if (node) {
        freeNode(node->children);
        freeNode(node->next);
        free(node);
    }
}

// Parse a single line of XML
void parseXMLLine(const char* line, Node* parent) {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    char* startTag = strstr(line, "<");
    char* endTag = strstr(line, ">");
    
    if (startTag && endTag) {
        size_t tagLength = endTag - startTag - 1;
        strncpy(tag, startTag + 1, tagLength);
        tag[tagLength] = '\0';
        
        // Check for closing tag or self-closing tag
        if (tag[0] == '/') {
            return; // This is a closing tag
        }

        char* valueStart = endTag + 1;
        char* valueEnd = strstr(valueStart, "<");

        if (valueEnd) {
            size_t valueLength = valueEnd - valueStart;
            strncpy(value, valueStart, valueLength);
            value[valueLength] = '\0';
            trimWhitespace(value);
        } else {
            value[0] = '\0'; // No value found
        }

        Node* newNode = createNode(tag, value);
        addChild(parent, newNode);

        // Recursive call for child nodes
        if (strstr(line, "/>")==NULL && !strstr(line, "/")) {
            parseXMLLine(valueEnd, newNode);
        }
    }
}

// Print the XML Node and all children
void printXML(Node* node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("<%s>", node->tag);
        if (node->value[0] != '\0') {
            printf("%s", node->value);
        }
        printf("\n");
        printXML(node->children, depth + 1);
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", node->tag);
        printXML(node->next, depth);
    }
}

// Trim whitespace from a string
void trimWhitespace(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) end--;
    *(end + 1) = '\0';

    char* start = str;
    while (*start && (*start == ' ' || *start == '\t' || *start == '\n')) start++;
    memmove(str, start, end - start + 2);
}

int main() {
    FILE* file = fopen("example.xml", "r");
    if (!file) {
        fprintf(stderr, "Could not open the XML file\n");
        return EXIT_FAILURE;
    }

    Node* root = createNode("root", "");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        parseXMLLine(line, root);
    }

    fclose(file);

    printf("Parsed XML Structure:\n");
    printXML(root, 0);

    freeNode(root);
    return EXIT_SUCCESS;
}