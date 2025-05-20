//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_LENGTH 256

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char *content;
    struct Node *next;
    struct Node *child;
} Node;

Node* createNode(const char* tag, const char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    newNode->content = content ? strdup(content) : NULL;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (!node) return;
    free(node->content);
    freeNode(node->next);
    freeNode(node->child);
    free(node);
}

void appendChild(Node* parent, Node* child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        Node* temp = parent->child;
        while (temp->next) temp = temp->next;
        temp->next = child;
    }
}

void printXML(Node* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s>\n", node->tag);
    if (node->content) {
        for (int i = 0; i < level + 1; i++) printf("  ");
        printf("%s\n", node->content);
    }
    printXML(node->child, level + 1);
    for (int i = 0; i < level; i++) printf("  ");
    printf("</%s>\n", node->tag);
    printXML(node->next, level);
}

char* strtok_custom(char* str, const char* delim) {
    static char* last = NULL;
    char* curr;

    if (str) {
        last = str;
    } else if (!last) {
        return NULL;
    }

    curr = last + strspn(last, delim);
    last = curr + strcspn(curr, delim);
    
    if (last == curr) {
        return NULL;
    }

    if (*last) {
        *last++ = '\0';
    } else {
        last = NULL;
    }

    return curr;
}

Node* parseXML(const char* xml) {
    Node* head = NULL;
    Node* current = NULL;
    char buffer[MAX_BUFFER];
    char tag[MAX_TAG_LENGTH];
    char* content = NULL;

    const char* ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // Closing tag
                ptr = strchr(ptr, '>');
                if (ptr) ptr++;
                current = current ? current->next : NULL;
            } else {
                // Opening tag
                ptr++;
                char* tagStart = tag;
                while (*ptr != '>' && *ptr != ' ' && *ptr != '\0') {
                    *tagStart++ = *ptr++;
                }
                *tagStart = '\0';

                // Prepare for content
                content = NULL;
                if (*ptr == ' ') {
                    // Skip to content
                    while (*ptr != '>' && *ptr != '\0') ptr++;
                }
                if (*ptr == '>') {
                    ptr++;
                    head = createNode(tag, content);
                    if (!current) {
                        current = head;
                    } else {
                        appendChild(current, head);
                    }
                    current = head;
                }
            }
        } else {
            // Content
            char* contentStart = buffer;
            while (*ptr != '<' && *ptr != '\0') {
                *contentStart++ = *ptr++;
            }
            *contentStart = '\0';
            current->content = strdup(buffer);
        }
    }
    return head;
}

int main() {
    const char* xmlData = "<root><child>Hello World</child><child><subchild>XML Parser</subchild></child></root>";
    Node* xmlTree = parseXML(xmlData);
    
    printf("Parsed XML Structure:\n");
    printXML(xmlTree, 0);
    
    freeNode(xmlTree);
    return 0;
}