//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tag[50];
    char content[100];
    struct Node* next;
    struct Node* child;
} Node;

Node* createNode(const char* tag, const char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->content, content);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

void parseXML(const char* xml, Node** root) {
    const char* ptr = xml;
    Node* current = NULL;
    Node* last = NULL;

    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            char tag[50];
            char content[100] = "";
            int tagIndex = 0, contentIndex = 0;

            while (*ptr && *ptr != '>' && *ptr != ' ' && *ptr != '/') {
                tag[tagIndex++] = *ptr++;
            }
            tag[tagIndex] = '\0';

            if (*ptr == ' ') {
                ptr++;
                while (*ptr && *ptr != '>') {
                    content[contentIndex++] = *ptr++;
                }
            }

            Node* newNode = createNode(tag, content);
            if (!current) {
                *root = newNode;
            } else {
                if (!current->child) {
                    current->child = newNode;
                } else {
                    last->next = newNode;
                }
            }
            last = newNode;
            current = newNode;

            if (*ptr == '/') {
                if (current->next) {
                    current = current->next;
                } else {
                    current = NULL;
                }
            }
            ptr++; // Skip '>'
        } else {
            ptr++;
        }
    }
}

void printXML(Node* node, int depth) {
    while (node) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("<%s>%s</%s>\n", node->tag, node->content[0] ? node->content : "", node->tag);
        printXML(node->child, depth + 1);
        node = node->next;
    }
}

int main() {
    const char* xmlData = "<note> \
                            <to>Tove</to> \
                            <from>Jani</from> \
                            <heading>Reminder</heading> \
                            <body>Don't forget me this weekend!</body> \
                          </note>";
    
    Node* root = NULL;

    parseXML(xmlData, &root);
    
    printf("Parsed XML Structure:\n");
    printXML(root, 0);
    
    freeNode(root);
    return 0;
}