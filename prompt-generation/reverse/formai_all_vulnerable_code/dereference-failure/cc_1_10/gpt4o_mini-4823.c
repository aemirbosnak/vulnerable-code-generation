//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML element
typedef struct XmlNode {
    char *tag;
    char *value;
    struct XmlNode *next;
    struct XmlNode *child;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char *tag, const char *value) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    node->tag = strdup(tag);
    node->value = value ? strdup(value) : NULL;
    node->next = NULL;
    node->child = NULL;
    return node;
}

// Function to free the memory used by XML node
void freeNode(XmlNode *node) {
    if (node) {
        free(node->tag);
        free(node->value);
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

// Function to print XML in a pretty format
void printXml(XmlNode *node, int indent) {
    XmlNode *current = node;
    while (current) {
        for (int i = 0; i < indent; i++) {
            printf("  ");
        }
        printf("<%s>", current->tag);
        if (current->value) {
            printf("%s", current->value);
        }
        printf("\n");
        if (current->child) {
            printXml(current->child, indent + 1);
        }
        printf("</%s>\n", current->tag);
        current = current->next;
    }
}

// Parser function to parse a simple XML string
XmlNode* parseXml(const char *xml) {
    XmlNode *root = NULL;
    XmlNode *current = NULL;
    char tag[256];
    char value[256];

    const char *ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') { // Closing tag
                ptr = strchr(ptr, '>');
                ptr++; // move past '>'
                continue;
            } else { // Opening tag
                sscanf(ptr, "<%255[^>]>%255[^<]", tag, value);
                ptr = strchr(ptr, '>') + 1; // move past '>'
                XmlNode *newNode = createNode(tag, value[0] ? value : NULL);
                if (!root) {
                    root = newNode; // Set root for the first element
                } else {
                    current->next = newNode; // Link new node to the last node
                }
                current = newNode; // Move current pointer to the new node
            }
        } else {
            ptr++;
        }
    }
    return root;
}

// Main function to demonstrate the XML parser
int main() {
    const char *xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    
    // Parse the XML string
    XmlNode *xmlRoot = parseXml(xmlString);
    
    // Print the parsed XML structure
    printf("Parsed XML Structure:\n");
    printXml(xmlRoot, 0);
    
    // Free the allocated memory
    freeNode(xmlRoot);
    return 0;
}