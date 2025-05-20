//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_CONTENT 1024

typedef struct Node {
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    struct Node *next;
    struct Node *child;
} Node;

Node* createNode(const char *tagName) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->tagName, tagName);
    newNode->content[0] = '\0';
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void insertChild(Node *parent, Node *child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        Node *temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void parseXML(const char *xml, Node *root) {
    const char *ptr = xml;
    char tag[MAX_TAG_NAME];
    char content[MAX_CONTENT];
    int contentIndex = 0;

    while (*ptr) {
        // Skip whitespace
        while (*ptr && (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')) ptr++;

        // Read opening tag
        if (*ptr == '<') {
            ptr++;
            if (*ptr == '/') {
                // Closing tag
                // Move pointer until the next '>'
                while (*ptr && *ptr != '>') ptr++;
                if (*ptr) ptr++;
                continue;
            }
            // Read tag name
            int tagIndex = 0;
            while (*ptr && *ptr != '>') {
                if (*ptr == ' ') break; // Break on whitespace before attributes
                tag[tagIndex++] = *ptr++;
            }
            tag[tagIndex] = '\0'; // Null-terminate the tag name

            Node *newNode = createNode(tag);
            insertChild(root, newNode);
            parseXML(ptr, newNode); // Recursively parse children
            root = newNode;
            continue;
        }
        
        // Read content until next tag
        if (*ptr && *ptr != '<') {
            contentIndex = 0;
            while (*ptr && *ptr != '<' && contentIndex < MAX_CONTENT - 1) {
                content[contentIndex++] = *ptr++;
            }
            content[contentIndex] = '\0'; // Null-terminate content
            if (strlen(root->content) + contentIndex < MAX_CONTENT) {
                strcat(root->content, content);
            }
        }
    }
}

void printXML(Node *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", node->tagName);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    Node *child = node->child;
    while (child) {
        printXML(child, depth + 1);
        child = child->next;
    }
    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", node->tagName);
}

void freeTree(Node *node) {
    if (node) {
        freeTree(node->child);
        freeTree(node->next);
        free(node);
    }
}

int main() {
    const char *xmlString =
        "<root>\n"
        "    <child1>\n"
        "        <subchild1>Content1</subchild1>\n"
        "        <subchild2>Content2</subchild2>\n"
        "    </child1>\n"
        "    <child2>Content for child2</child2>\n"
        "</root>";

    Node *root = createNode("root");
    parseXML(xmlString, root);
    printXML(root, 0);
    freeTree(root);

    return 0;
}