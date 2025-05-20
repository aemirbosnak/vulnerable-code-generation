//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 64
#define MAX_TAG_CONTENT_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_NAME_LENGTH];
    char content[MAX_TAG_CONTENT_LENGTH];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

XMLNode* createNode(const char* tag, const char* content) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strcpy(node->tag, tag);
    strcpy(node->content, content);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void addNode(XMLNode* parent, XMLNode* child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        XMLNode* temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeNode(XMLNode* node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

XMLNode* parseXML(const char* xml) {
    XMLNode* root = NULL;
    XMLNode* current = NULL;
    char tag[MAX_TAG_NAME_LENGTH];
    char content[MAX_TAG_CONTENT_LENGTH];
    int index = 0;
    int isTag = 0;
    int isContent = 0;

    for (int i = 0; xml[i] != '\0'; i++) {
        if (xml[i] == '<') {
            if (isContent) {
                content[index] = '\0';
                if (current) {
                    strcpy(current->content, content);
                }
                isContent = 0;
                index = 0;
            }

            isTag = 1;
            index = 0;
            i++;
            while (xml[i] != '>' && xml[i] != ' ' && xml[i] != '\0') {
                tag[index++] = xml[i++];
            }
            tag[index] = '\0';
            if (!root) {
                root = createNode(tag, "");
                current = root;
            } else {
                XMLNode* newNode = createNode(tag, "");
                addNode(current, newNode);
                current = newNode;
            }
        } else if (xml[i] == '/') {
            if (xml[i + 1] == '>') {
                if (current) {
                    current = current->next;  // Go to the parent (if any)
                }
                i++;
            }
        } else if (current) {
            content[index++] = xml[i];
            isContent = 1;
        }
    }

    return root;
}

void printXML(XMLNode* node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->content, node->tag);
    printXML(node->child, level + 1);
    printXML(node->next, level);
}

int main() {
    const char* xmlData = 
        "<root>\n"
        " <child1>Hello</child1>\n"
        " <child2>\n"
        "   <subchild1>World</subchild1>\n"
        " </child2>\n"
        "</root>";

    XMLNode* xmlTree = parseXML(xmlData);

    printf("Parsed XML Structure:\n");
    printXML(xmlTree, 0);

    freeNode(xmlTree);
    return 0;
}