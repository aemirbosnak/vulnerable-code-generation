//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 64
#define MAX_CONTENT_LEN 256
#define MAX_XML_LEN 4096

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME_LEN];
    char content[MAX_CONTENT_LEN];
    struct XmlNode *next;
    struct XmlNode *child;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char *tagName, const char *content) {
    XmlNode *newNode = (XmlNode *)malloc(sizeof(XmlNode));
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME_LEN);
    strncpy(newNode->content, content, MAX_CONTENT_LEN);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to parse XML string
XmlNode* parseXml(const char *xml) {
    XmlNode *root = NULL, *currentNode = NULL;
    char tag[MAX_TAG_NAME_LEN], content[MAX_CONTENT_LEN];
    const char *ptr = xml;
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++; // skip the '<'
            if (*ptr == '/') { // End tag
                while (*ptr && *ptr != '>') ptr++;
            } else {
                // Read the tag name
                int i = 0;
                while (*ptr && *ptr != '>' && *ptr != ' ') {
                    tag[i++] = *ptr++;
                }
                tag[i] = '\0'; // Null-terminate the tag

                // Skip any attributes until '>'
                while (*ptr && *ptr != '>') ptr++;
                if (*ptr == '>') ptr++; // skip the '>'

                // Read the content if necessary
                i = 0;
                while (*ptr && *ptr != '<') {
                    if (i < MAX_CONTENT_LEN - 1) {
                        content[i++] = *ptr++;
                    } else {
                        content[i] = '\0'; // Truncate if too long
                        break;
                    }
                }
                content[i] = '\0'; // Null-terminate the content

                // Create a new node
                XmlNode *newNode = createNode(tag, content);
                if (!root) {
                    root = newNode; // First node
                }
                if (currentNode) {
                    // Append to the current node's child
                    newNode->next = currentNode->child;
                    currentNode->child = newNode;
                }
                // Move the current node to newNode
                currentNode = newNode;
            }
        } else {
            ptr++; // skip if not a tag
        }
    }
    return root;
}

// Function to print the XML tree
void printXmlTree(XmlNode *node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tagName, node->content, node->tagName);
    
    // Print children
    printXmlTree(node->child, depth + 1);
    printXmlTree(node->next, depth);
}

// Function to free the XML tree
void freeXmlTree(XmlNode *node) {
    if (!node) return;
    freeXmlTree(node->child);
    freeXmlTree(node->next);
    free(node);
}

int main() {
    const char *xmlInput = 
        "<root>"
        "<child1>Hello</child1>"
        "<child2>World</child2>"
        "<child3>"
        "<subchild>A subchild</subchild>"
        "</child3>"
        "</root>";

    XmlNode *xmlTree = parseXml(xmlInput);
    printXmlTree(xmlTree, 0);
    
    // Free the allocated memory
    freeXmlTree(xmlTree);
    return 0;
}