//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct XmlNode* next;
    struct XmlNode* child;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char* tag, const char* content) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->content, content, MAX_LINE_LENGTH);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to parse an XML line
XmlNode* parseXmlLine(const char* line) {
    char tag[MAX_TAG_LENGTH] = {0};
    char content[MAX_LINE_LENGTH] = {0};

    // Extract tag and content
    if (sscanf(line, "<%[^/>]>", tag) == 1) {
        char* pContent = strstr(line, ">");
        if (pContent != NULL) {
            pContent = strchr(pContent + 1, '<');
            if (pContent != NULL) {
                size_t contentLength = pContent - (strstr(line, ">") + 1);
                strncpy(content, strstr(line, ">") + 1, contentLength);
                content[contentLength] = '\0';
            }
        }
        return createNode(tag, content);
    }

    return NULL;
}

// Function to print the XML tree
void printXmlTree(XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++)
        printf("  ");
  
    printf("<%s>%s</%s>\n", node->tag, node->content, node->tag);
    printXmlTree(node->child, depth + 1);
    printXmlTree(node->next, depth);
}

// Function to free the XML tree
void freeXmlTree(XmlNode* node) {
    if (node == NULL) return;
    freeXmlTree(node->child);
    freeXmlTree(node->next);
    free(node);
}

// Main function to read XML and parse it
int main() {
    FILE* file = fopen("example.xml", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file.\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    XmlNode* head = NULL;
    XmlNode* tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        XmlNode* newNode = parseXmlLine(line);
        if (newNode != NULL) {
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

    printf("Parsed XML Structure:\n");
    printXmlTree(head, 0);
    
    freeXmlTree(head);
    return EXIT_SUCCESS;
}