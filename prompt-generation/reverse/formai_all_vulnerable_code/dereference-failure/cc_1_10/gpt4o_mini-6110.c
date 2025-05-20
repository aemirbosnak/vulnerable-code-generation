//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 50
#define MAX_BUFFER_LENGTH 1024

typedef struct XMLNode {
    char tag[MAX_TAG_NAME_LENGTH];
    char *content;
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

void initializeNode(XMLNode *node, const char *tag) {
    strncpy(node->tag, tag, MAX_TAG_NAME_LENGTH);
    node->content = NULL;
    node->next = NULL;
    node->child = NULL;
}

void appendChild(XMLNode *parent, XMLNode *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XMLNode *temp = parent->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeXMLNode(XMLNode *node) {
    if (node) {
        freeXMLNode(node->child);
        freeXMLNode(node->next);
        free(node->content);
        free(node);
    }
}

XMLNode *parseXML(const char *xml) {
    XMLNode *root = NULL, *current = NULL;
    char tag[MAX_TAG_NAME_LENGTH];
    const char *pos = xml;
    char *contentStart = NULL;

    while (*pos) {
        // Skip whitespace
        while (*pos && (*pos == ' ' || *pos == '\n' || *pos == '\t')) {
            pos++;
        }

        if (*pos == '<') {
            // Check for closing tag
            if (*(pos + 1) == '/') {
                // End of current tag
                pos = strchr(pos, '>');
                if (pos) {
                    pos++;
                }
                current = current->next;
            } 
            else {
                // Parse opening tag
                const char *tagStart = pos + 1;
                pos = strchr(tagStart, '>');
                if (!pos) {
                    fprintf(stderr, "Malformed XML: No closing '>' for tag\n");
                    return NULL;
                }
                strncpy(tag, tagStart, pos - tagStart);
                tag[pos - tagStart] = '\0';
                pos++;

                XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
                initializeNode(newNode, tag);
                if (!root) {
                    root = newNode; // First node is the root
                }
                if (current) {
                    appendChild(current, newNode);
                }
                current = newNode;

                // Parse content
                contentStart = pos;
                pos = strchr(contentStart, '<');
                if (pos) {
                    int contentLength = pos - contentStart;
                    if (contentLength > 0) {
                        current->content = (char *)malloc(contentLength + 1);
                        strncpy(current->content, contentStart, contentLength);
                        current->content[contentLength] = '\0';
                    }
                }
            }
        }
    }
    
    return root;
}

void printXML(XMLNode *node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("<%s>", node->tag);
        if (node->content) {
            printf("%s", node->content);
        }
        printf("\n");
        if (node->child) {
            printXML(node->child, depth + 1);
        }
        for (XMLNode *next = node->next; next != NULL; next = next->next) {
            printXML(next, depth);
        }
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
    }
}

int main() {
    const char *xmlData = "<root>\n"
                          "  <child1>Hello World</child1>\n"
                          "  <child2>\n"
                          "    <subchild>Text</subchild>\n"
                          "  </child2>\n"
                          "</root>\n";

    XMLNode *xmlTree = parseXML(xmlData);
    if (xmlTree) {
        printf("Parsed XML Structure:\n");
        printXML(xmlTree, 0);
        freeXMLNode(xmlTree);
    } else {
        fprintf(stderr, "XML parsing failed!\n");
    }
    
    return 0;
}