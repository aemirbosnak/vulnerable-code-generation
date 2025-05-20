//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_VALUE_LENGTH 500
#define MAX_XML_SIZE 1024

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* next;
    struct XmlNode* children;
} XmlNode;

XmlNode* createNode(const char* tag, const char* value) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void addChild(XmlNode* parent, XmlNode* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        XmlNode* temp = parent->children;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void parseXML(const char* xml, XmlNode* root) {
    const char* ptr = xml;
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    char currentTag[MAX_TAG_NAME] = "";
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            if (*ptr == '/') {
                // Closing tag
                ptr++;
                sscanf(ptr, "%[^>]", currentTag);
                while (*ptr != '>') ptr++;
                ptr++;
            } else {
                // Opening tag
                sscanf(ptr, "%[^>]", tag);
                XmlNode* newNode = createNode(tag, "");
                addChild(root, newNode);
                root = newNode;
                while (*ptr != '>') ptr++;
                ptr++;
            }
        } else {
            // Read value
            int index = 0;
            while (*ptr != '<' && *ptr) {
                if (index < MAX_VALUE_LENGTH - 1) {
                    value[index++] = *ptr;
                }
                ptr++;
            }
            value[index] = '\0';
            // Assign value to node
            if (root->value[0] == '\0') {
                strcpy(root->value, value);
            }
        }
    }
}

void printXmlNode(XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);

    if (node->children != NULL) {
        printXmlNode(node->children, depth + 1);
    }
    
    printXmlNode(node->next, depth);
}

void freeXmlNode(XmlNode* node) {
    if (node == NULL) return;

    freeXmlNode(node->children);
    freeXmlNode(node->next);
    free(node);
}

int main() {
    char xml[MAX_XML_SIZE] = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    
    XmlNode* rootNode = createNode("root", "");
    parseXML(xml, rootNode);
    
    printf("Parsed XML Structure:\n");
    printXmlNode(rootNode->children, 0);
    
    freeXmlNode(rootNode);
    return 0;
}