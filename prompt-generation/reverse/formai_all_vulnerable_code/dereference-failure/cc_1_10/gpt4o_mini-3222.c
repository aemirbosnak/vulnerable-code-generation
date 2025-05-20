//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1024
#define MAX_XML_SIZE 8192

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XMLNode **children;
    int childCount;
} XMLNode;

XMLNode *createNode(const char *tagName) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tagName, tagName, MAX_TAG_NAME_LENGTH);
    node->tagName[MAX_TAG_NAME_LENGTH - 1] = '\0';  // Ensuring null termination
    node->value[0] = '\0';  // Initialize value as empty
    node->children = NULL;
    node->childCount = 0;
    return node;
}

void freeNode(XMLNode *node) {
    if (node) {
        for (int i = 0; i < node->childCount; i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void addChild(XMLNode *parent, XMLNode *child) {
    parent->children = (XMLNode **)realloc(parent->children, sizeof(XMLNode *) * (parent->childCount + 1));
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

int parseXML(const char *xml, XMLNode **root) {
    const char *pos = xml;
    char tagName[MAX_TAG_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];    
    int i;

    *root = NULL;

    while (*pos) {
        // Skip whitespace
        while (*pos && isspace(*pos)) pos++;

        // Check for start tag
        if (*pos == '<') {
            pos++;
            i = 0;
            // Read tag name
            while (*pos && *pos != ' ' && *pos != '>') {
                tagName[i++] = *pos++;
            }
            tagName[i] = '\0';  // Null terminate the tag name

            // Create the new node and set it as the root if it's the first node
            XMLNode *node = createNode(tagName);
            if (!(*root)) {
                *root = node;
            } else {
                // Add it to the previous node's children
                addChild(*root, node);
            }

            // Check for closing tag
            if (*pos == '>') {
                pos++;
                // Read value until next opening tag or closing tag
                i = 0;
                while (*pos && *pos != '<') {
                    if (i < MAX_VALUE_LENGTH - 1) {
                        value[i++] = *pos++;
                    }
                }
                value[i] = '\0';  // Null terminate the value
                strncpy(node->value, value, MAX_VALUE_LENGTH);  // Store value in node
            }

            // Check for self-closing tag
            if (*(pos - 1) == '/' && *pos == '>') {
                pos++;
            }

            // Look ahead for child nodes or closing tag
            while (*pos && *pos != '/' && *pos != '>') {
                pos++;
            } 
        }

        // Closing tag
        if (*pos == '<' && *(pos + 1) == '/') {
            // Skip '</'
            pos += 2;
            i = 0;
            // Read closing tag name
            while (*pos && *pos != '>') {
                tagName[i++] = *pos++;
            }
            tagName[i] = '\0';  // Null terminate the tag name
            pos++;  // Move past '>'
            // Check if it matches the last node
            if (*root && strcmp((*root)->tagName, tagName) == 0) {
                // Move back up to parent node
                // For simplicity, we'll just make sure we are at the root again
                if ((*root)->childCount > 0) {
                    *root = (*root)->children[0];
                } else {
                    *root = NULL; // No children to go up to
                }
            }
        }
    }
    return 0;
}

void printXML(XMLNode *node, int indent) {
    if (node) {
        for (int i = 0; i < indent; ++i) printf(" ");
        printf("<%s>", node->tagName);
        if (strlen(node->value) > 0) {
            printf("%s", node->value);
        }
        printf("\n");
        for (int i = 0; i < node->childCount; ++i) {
            printXML(node->children[i], indent + 2);
        }
        for (int i = 0; i < indent; ++i) printf(" ");
        printf("</%s>\n", node->tagName);
    }
}

int main() {
    const char *xmlData =
        "<root>"
            "<child1>Value1</child1>"
            "<child2>"
                "<subchild1>Value2</subchild1>"
                "<subchild2>Value3</subchild2>"
            "</child2>"
        "</root>";

    XMLNode *root = NULL;
    if (parseXML(xmlData, &root) == 0) {
        printf("Parsed XML:\n");
        printXML(root, 0);
    } else {
        fprintf(stderr, "Error parsing XML.\n");
    }

    freeNode(root);
    return 0;
}