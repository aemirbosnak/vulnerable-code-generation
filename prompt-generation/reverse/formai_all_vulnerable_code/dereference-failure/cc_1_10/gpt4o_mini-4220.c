//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *tag;
    char *content;
    struct Node **children;
    int child_count;
} Node;

Node* createNode(const char* tag, const char* content) {
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->tag = strdup(tag);
    node->content = content ? strdup(content) : NULL;
    node->children = NULL;
    node->child_count = 0;
    
    return node;
}

void addChildNode(Node* parent, Node* child) {
    parent->children = realloc(parent->children, (parent->child_count + 1) * sizeof(Node*));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void freeNode(Node* node) {
    if (node) {
        free(node->tag);
        if (node->content) {
            free(node->content);
        }
        for (int i = 0; i < node->child_count; i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void printNode(const Node* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    
    printf("<%s>", node->tag);
    if (node->content) {
        printf("%s", node->content);
    }
    printf("\n");

    for (int i = 0; i < node->child_count; i++) {
        printNode(node->children[i], indent + 1);
    }
    
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

void parseXML(const char* xml, Node** root) {
    char tag[256];
    char content[256];
    const char* pos = xml;
    
    while (*pos) {
        if (*pos == '<') {
            if (*(pos + 1) == '/') {
                pos = strchr(pos, '>') + 1;
                return; // End of a tag
            }
            else {
                sscanf(pos, "<%255[^>]>", tag);
                pos += strlen(tag) + 2;  // Move past '<tag>'
                const char* contentEnd = strchr(pos, '<');
                strncpy(content, pos, contentEnd - pos);
                content[contentEnd - pos] = '\0'; // Null-terminate the content
                Node* node = createNode(tag, content);
                parseXML(pos, &node);
                addChildNode(*root, node);
                pos = contentEnd; // Set pos to the start of the next tag
            }
        }
        else {
            pos++;
        }
    }
}

int main() {
    const char* xmlData = "<book><title>XML Parsing in C</title><author>OpenAI</author></book>";
    
    Node* root = createNode("root", NULL);
    parseXML(xmlData, &root);
    
    printf("Parsed XML Structure:\n");
    printNode(root, 0);
    
    freeNode(root);
    return 0;
}