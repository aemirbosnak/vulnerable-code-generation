//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 100

typedef struct Node {
    char tagName[MAX_TAG_NAME_LEN];
    struct Node *next;
    struct Node *child;
    char *content;
} Node;

Node* createNode(const char* tagName, const char* content) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->tagName, tagName, MAX_TAG_NAME_LEN);
    node->next = NULL;
    node->child = NULL;
    node->content = content ? strdup(content) : NULL; // Save content or NULL if there's none
    return node;
}

void freeNode(Node* node) {
    if (node) {
        free(node->content);
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

void printXmlNode(Node* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf("  "); // Indentation for clarity
    printf("<%s>", node->tagName);
    if (node->content) printf("%s", node->content);
    printf("\n");

    printXmlNode(node->child, indent + 1);
    for (int i = 0; i < indent; i++) printf("  "); // Matching indentation for closing
    printf("</%s>\n", node->tagName);

    printXmlNode(node->next, indent);
}

Node* parseXml(const char* fname) {
    FILE* file = fopen(fname, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", fname);
        return NULL;
    }

    Node* root = NULL;
    Node* current = NULL;
    char line[256];
    char tagName[MAX_TAG_NAME_LEN];
    char content[256];
    
    while (fgets(line, sizeof(line), file)) {
        char *startTag = strchr(line, '<');
        char *endTag = strchr(line, '>');

        if (startTag && endTag) {
            // Parse content assuming well-structured XML
            strncpy(tagName, startTag + 1, endTag - startTag - 1);
            tagName[endTag - startTag - 1] = '\0'; // Null-terminate the tag name

            // Content resides adjacent to the tag
            if (*endTag != '\n') {
                char *contentStart = endTag + 1;
                char *contentEnd = strchr(contentStart, '<');
                if (contentEnd) {
                    strncpy(content, contentStart, contentEnd - contentStart);
                    content[contentEnd - contentStart] = '\0';
                } else {
                    strcpy(content, contentStart); // If no ending tag, take all
                }
            } else {
                content[0] = '\0'; // No content present
            }

            Node* newNode = createNode(tagName, strlen(content) > 0 ? content : NULL);
            
            // Link newNode into the list/tree
            if (!current) {
                root = newNode; // First node is the root
            } else {
                current->next = newNode; // Link to next in the same level
            }
            
            current = newNode; // Move current pointer for the next node
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node* xmlTree = parseXml(argv[1]);
    printf("Parsed XML Structure:\n");
    printXmlNode(xmlTree, 0);
    
    // Clean up the allocated nodes
    freeNode(xmlTree);
    return EXIT_SUCCESS;
}