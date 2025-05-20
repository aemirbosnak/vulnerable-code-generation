//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 64
#define MAX_TAG_VALUE_LEN 256

typedef struct XmlNode {
    char tag[MAX_TAG_NAME_LEN];
    char value[MAX_TAG_VALUE_LEN];
    struct XmlNode* next;
    struct XmlNode* child;
} XmlNode;

// Function prototypes
XmlNode* createNode(const char* tag, const char* value);
void insertChild(XmlNode* parent, XmlNode* child);
void freeTree(XmlNode* root);
void parseXml(FILE* file, XmlNode* root);
void printXml(XmlNode* node, int depth);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    XmlNode* root = createNode("root", "");
    
    parseXml(file, root);
    
    printf("Parsed XML Structure:\n");
    printXml(root, 0);
    
    freeTree(root);
    fclose(file);
    
    return 0;
}

XmlNode* createNode(const char* tag, const char* value) {
    XmlNode* node = (XmlNode*)malloc(sizeof(XmlNode));
    strncpy(node->tag, tag, MAX_TAG_NAME_LEN);
    strncpy(node->value, value, MAX_TAG_VALUE_LEN);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void insertChild(XmlNode* parent, XmlNode* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XmlNode* tmp = parent->child;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = child;
    }
}

void freeTree(XmlNode* root) {
    if (root == NULL) return;
    freeTree(root->child);
    freeTree(root->next);
    free(root);
}

void parseXml(FILE* file, XmlNode* root) {
    char line[512];
    XmlNode* currentNode = root;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_NAME_LEN];
        char value[MAX_TAG_VALUE_LEN] = "";
        
        if (sscanf(line, " <%s > %s </ %*s>", tag, value) == 2) {
            XmlNode* newNode = createNode(tag, value);
            insertChild(currentNode, newNode);
            currentNode = newNode;
        }
        else if (sscanf(line, " </%s>", tag) == 1) {
            currentNode = root;  // Return to root for simplicity.
        }
    }
}

void printXml(XmlNode* node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; ++i) {
        printf("  "); // Indentation
    }
    printf("<%s>%s</%s>\n", node->tag, node->value[0] ? node->value : "", node->tag);

    printXml(node->child, depth + 1);
    printXml(node->next, depth);
}