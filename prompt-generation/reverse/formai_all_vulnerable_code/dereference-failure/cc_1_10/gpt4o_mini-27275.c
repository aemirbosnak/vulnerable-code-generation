//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_NAME_LENGTH 64
#define MAX_BUFFER 4096

typedef struct XmlNode {
    char tag[MAX_TAG_NAME_LENGTH];
    char *content;
    struct XmlNode **children;
    int childCount;
} XmlNode;

// Function prototypes
XmlNode *createNode(const char *tag);
void freeNode(XmlNode *node);
void parseXml(const char *xmlData, XmlNode *root);
void printXmlTree(XmlNode *node, int depth);
void trimWhitespace(char *str);
int isWhitespace(char c);

int main() {
    const char *xmlData = 
        "<bookstore>"
        "<book>"
        "<title>Programming in C</title>"
        "<author>John Doe</author>"
        "<price>29.99</price>"
        "</book>"
        "<book>"
        "<title>Learning XML</title>"
        "<author>Jane Smith</author>"
        "<price>39.99</price>"
        "</book>"
        "</bookstore>";

    XmlNode *root = createNode("bookstore");
    parseXml(xmlData, root);
    printXmlTree(root, 0);
    freeNode(root);

    return 0;
}

XmlNode *createNode(const char *tag) {
    XmlNode *newNode = (XmlNode *)malloc(sizeof(XmlNode));
    strncpy(newNode->tag, tag, MAX_TAG_NAME_LENGTH);
    newNode->content = NULL;
    newNode->childCount = 0;
    newNode->children = NULL;
    return newNode;
}

void freeNode(XmlNode *node) {
    if (!node) return;
    
    if (node->content) {
        free(node->content);
    }
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node->children);
    free(node);
}

void parseXml(const char *xmlData, XmlNode *root) {
    char tag[MAX_TAG_NAME_LENGTH];
    char buffer[MAX_BUFFER];
    int i = 0, j = 0, inTag = 0, inContent = 0;
    XmlNode *currentNode = root;

    while (xmlData[i] != '\0') {
        if (xmlData[i] == '<') {
            if (xmlData[i + 1] == '/') {  // Closing tag
                tag[j] = '\0';
                j = 0;
                inTag = 0;
                if (currentNode->content) {
                    trimWhitespace(currentNode->content);
                    inContent = 0;
                }
                // Move back to the previous node
                currentNode = currentNode->children[currentNode->childCount - 1];
                currentNode->childCount--;      
            } else { // Opening tag
                inTag = 1;
                while (xmlData[i] != '>' && xmlData[i] != '\0') {
                    if (xmlData[i] != '<') {
                        tag[j++] = xmlData[i];
                    }
                    i++;
                }
                tag[j] = '\0';
                j = 0;

                XmlNode *newNode = createNode(tag);
                currentNode->children = 
                    (XmlNode **)realloc(currentNode->children, 
                                        sizeof(XmlNode *) * (currentNode->childCount + 1));
                currentNode->children[currentNode->childCount++] = newNode;
                currentNode = newNode;
                inContent = 1;
            }
        } else if (inContent) {
            while (xmlData[i] != '<' && xmlData[i] != '\0') {
                buffer[j++] = xmlData[i++];
            }
            buffer[j] = '\0';
            j = 0;
            currentNode->content = (char *)malloc(strlen(buffer) + 1);
            strcpy(currentNode->content, buffer);
            trimWhitespace(currentNode->content);
            inContent = 0;
        }
        i++;
    }
}

void trimWhitespace(char *str) {
    char *end;

    while (isWhitespace(*str)) str++; // Trim leading space

    if (*str == 0)  // All spaces?
        return;

    end = str + strlen(str) - 1;
    while (end > str && isWhitespace(*end)) end--; // Trim trailing space

    *(end + 1) = '\0';
}

int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void printXmlTree(XmlNode *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    
    if (node->content) {
        printf("%s", node->content);
    }

    printf("\n");

    for (int i = 0; i < node->childCount; i++) {
        printXmlTree(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}