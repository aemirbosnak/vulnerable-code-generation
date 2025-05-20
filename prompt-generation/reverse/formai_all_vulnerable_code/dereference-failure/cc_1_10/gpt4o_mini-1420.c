//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 256
#define MAX_BUFFER 1024

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    struct XMLNode* child;
    struct XMLNode* sibling;
    char* content;
} XMLNode;

// Function prototypes
XMLNode* createNode(const char* tagName);
void freeNode(XMLNode* node);
void parseXML(const char* xmlData, XMLNode** root);
void printXML(XMLNode* node, int depth);
void trimWhitespace(char* str);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char* xmlData = (char*)malloc(MAX_BUFFER);
    size_t bytesRead = fread(xmlData, sizeof(char), MAX_BUFFER - 1, file);
    xmlData[bytesRead] = '\0'; // Null-terminate the string

    fclose(file);

    XMLNode* root = NULL;
    parseXML(xmlData, &root);
    printXML(root, 0);

    free(xmlData);
    freeNode(root);
    return EXIT_SUCCESS;
}

XMLNode* createNode(const char* tagName) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(node->tagName, tagName, MAX_TAG_NAME);
    node->tagName[MAX_TAG_NAME - 1] = '\0'; // Ensure null termination
    node->child = NULL;
    node->sibling = NULL;
    node->content = NULL;
    return node;
}

void freeNode(XMLNode* node) {
    if (node) {
        free(node->content);
        freeNode(node->child);
        freeNode(node->sibling);
        free(node);
    }
}

void parseXML(const char* xmlData, XMLNode** root) {
    const char* pos = xmlData;
    XMLNode* current = NULL;
    XMLNode* lastNode = NULL;
    char tagName[MAX_TAG_NAME];
    int inTag = 0;
    int isClosingTag = 0;

    while (*pos) {
        if (*pos == '<') {
            if (*(pos + 1) == '/') { // Closing tag
                isClosingTag = 1;
                pos += 2; // Skip "</"
                while (*pos != '>' && *pos) {
                    pos++;
                }
                if (*pos == '>') {
                    pos++; // Skip '>'
                }
                inTag = 0; // End of tag processing
            } else {
                isClosingTag = 0;
                pos++; // Skip '<'
                int index = 0;
                while (*pos != '>' && *pos != ' ' && *pos) {
                    tagName[index++] = *pos++;
                }
                tagName[index] = '\0'; // Null-terminate tag name
                if (*pos == '>') {
                    pos++; // Skip '>'
                }
                trimWhitespace(tagName);
                current = createNode(tagName);
                if (*root == NULL) {
                    *root = current; // Set root if it's the first node
                } else if (lastNode) {
                    lastNode->sibling = current; // Add to previous node's sibling
                }
                lastNode = current;

                inTag = 1; // We're inside a tag
            }
        } else if (inTag && !isClosingTag) {
            // Check for content before the next tag
            char* contentStart = (char*)pos;
            while (*pos != '<' && *pos) {
                pos++;
            }
            if (contentStart != pos) {
                int length = pos - contentStart;
                current->content = (char*)malloc(length + 1);
                strncpy(current->content, contentStart, length);
                current->content[length] = '\0'; // Null-terminate the content
            }
        } else {
            pos++; // Move to the next character
        }
    }
}

void printXML(XMLNode* node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("<%s>", node->tagName);
        if (node->content) {
            printf("%s", node->content);
        }
        printf("\n");
        printXML(node->child, depth + 1);
        printXML(node->sibling, depth);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tagName);
    }
}

void trimWhitespace(char* str) {
    char* start = str;
    while (*start == ' ') start++;
    char* end = str + strlen(str) - 1;
    while (end > start && *end == ' ') end--;
    end[1] = '\0'; // Null-terminate string at new end
}