//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_CONTENT 256

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    struct XmlNode *next;
    struct XmlNode *child;
} XmlNode;

XmlNode* createNode(const char *tagName, const char *content) {
    XmlNode *newNode = (XmlNode *)malloc(sizeof(XmlNode));
    strcpy(newNode->tagName, tagName);
    strcpy(newNode->content, content);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void addChild(XmlNode *parent, XmlNode *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XmlNode *current = parent->child;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

void freeXmlNode(XmlNode *node) {
    if (node) {
        freeXmlNode(node->child);
        freeXmlNode(node->next);
        free(node);
    }
}

void printXml(XmlNode *node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>\n", node->tagName);
    if (strlen(node->content) > 0) {
        for (int i = 0; i < level + 1; i++) {
            printf("  ");
        }
        printf("%s\n", node->content);
    }
    printXml(node->child, level + 1);
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tagName);
    printXml(node->next, level);
}

XmlNode* parseXml(const char *xmlData) {
    XmlNode *root = NULL;
    XmlNode *currentNode = NULL;
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    int pos = 0;
    int i = 0;
    
    while (xmlData[i] != '\0') {
        if (xmlData[i] == '<') {
            if (xmlData[i + 1] != '/') {  // Opening tag
                int j = 0;
                i++; // Move past '<'
                while (xmlData[i] != '>' && xmlData[i] != ' ' && xmlData[i] != '\0') {
                    tagName[j++] = xmlData[i++];
                }
                tagName[j] = '\0';
                content[0] = '\0';
                XmlNode *newNode = createNode(tagName, content);
                if (currentNode == NULL) {
                    root = newNode;
                } else {
                    addChild(currentNode, newNode);
                }
                currentNode = newNode;
            } else { // Closing tag
                int j = 0;
                i += 2; // Move past '</'
                while (xmlData[i] != '>' && xmlData[i] != '\0') {
                    tagName[j++] = xmlData[i++];
                }
                tagName[j] = '\0';
                currentNode = NULL; // Returning to the parent node
            }
        } else if (xmlData[i] != '\0') {
            int j = 0;
            while (xmlData[i] != '<' && xmlData[i] != '\0') {
                content[j++] = xmlData[i++];
            }
            content[j] = '\0';
            if (currentNode) {
                strcpy(currentNode->content, content);
            }
        }
        i++;
    }
    return root;
}

int main() {
    const char *xmlData = "<root><child>Hello, World!</child><child>XML Parsing in C</child></root>";
    
    XmlNode *xmlTree = parseXml(xmlData);
    
    printf("Parsed XML Structure:\n");
    printXml(xmlTree, 0);
    
    freeXmlNode(xmlTree);
    return 0;
}