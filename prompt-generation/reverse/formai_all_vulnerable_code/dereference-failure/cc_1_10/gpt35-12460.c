//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CHILDREN 50

typedef struct XMLNode XMLNode;

struct XMLNode {
    char* tagName;
    char* value;
    int numChildren;
    XMLNode* children[MAX_CHILDREN];
};

XMLNode* createNode(char* tagName, char* value) {
    XMLNode* node = malloc(sizeof(XMLNode));
    node->tagName = tagName;
    node->value = value;
    node->numChildren = 0;
    return node;
}

void addChildNode(XMLNode* parent, XMLNode* child) {
    if(parent->numChildren >= MAX_CHILDREN) {
        printf("Error: Maximum children exceeded!\n");
        return;
    }
    parent->children[parent->numChildren++] = child;
}

void parseXML(char* xmlContent, XMLNode* parent) {
    char* tagStart = strchr(xmlContent, '<');
    char* tagEnd = strchr(xmlContent, '>');
    int valueStart = tagEnd - xmlContent + 1;
    int valueEnd = strlen(xmlContent) - 1;
    if(tagStart == NULL || tagEnd == NULL) return;
    if(*tagStart == '<' && *(tagStart + 1) == '/') return;
    if(*(tagEnd - 1) == '/') return;
    char* tagName = calloc(tagEnd - tagStart - 1, sizeof(char));
    strncpy(tagName, tagStart + 1, tagEnd - tagStart - 1);
    char* value = calloc(valueEnd - valueStart + 1, sizeof(char));
    strncpy(value, xmlContent + valueStart, valueEnd - valueStart + 1);
    XMLNode* node = createNode(tagName, value);
    addChildNode(parent, node);
    char* nextXML = tagEnd + 1;
    while(*nextXML != '\0') {
        XMLNode* child = createNode("", "");
        parseXML(nextXML, child);
        if(child->tagName != NULL && *child->tagName != '\0') {
            addChildNode(node, child);
        }
        nextXML = strchr(nextXML, '<') + 1;
    }
}

void printXMLTree(XMLNode* node, int level) {
    int i;
    for(i = 0; i < level; i++) printf(" ");
    printf("<%s>", node->tagName);
    if(node->value != NULL && *node->value != '\0') {
        printf("%s", node->value);
    }
    printf("\n");
    for(i = 0; i < node->numChildren; i++) {
        printXMLTree(node->children[i], level + 1);
    }
    for(i = 0; i < level; i++) printf(" ");
    printf("</%s>\n", node->tagName);
}

int main() {
    char* xmlContent = "<root><person><name>Jane Doe</name><age>30</age><address><street>123 Main St</street><city>New York</city></address></person></root>";
    XMLNode* root = createNode("root", "");
    parseXML(xmlContent, root);
    printXMLTree(root, 0);
    return 0;
}