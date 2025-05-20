//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XML_LINE_LENGTH 1024
#define MAX_TAG_NAME_LENGTH 100
#define MAX_ATTRIBUTE_LENGTH 100

typedef struct Attribute {
    char name[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_LENGTH];
    struct Attribute *next;
} Attribute;

typedef struct XMLNode {
    char tag[MAX_TAG_NAME_LENGTH];
    Attribute *attributes;
    struct XMLNode *children;
    struct XMLNode *next;
} XMLNode;

// Function prototypes
XMLNode* createNode(const char *tag);
void addAttribute(XMLNode *node, const char *name, const char *value);
void addChild(XMLNode *parent, XMLNode *child);
void parseXML(const char *filename, XMLNode *root);
void printXML(XMLNode *node, int depth);
void freeXML(XMLNode *node);
char* trimWhitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    XMLNode *root = createNode("root");
    parseXML(argv[1], root);
    
    printXML(root, 0);
    
    freeXML(root);
    return EXIT_SUCCESS;
}

XMLNode* createNode(const char *tag) {
    XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(newNode->tag, tag, MAX_TAG_NAME_LENGTH);
    newNode->tag[MAX_TAG_NAME_LENGTH - 1] = '\0';
    newNode->attributes = NULL;
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void addAttribute(XMLNode *node, const char *name, const char *value) {
    Attribute *newAttr = (Attribute *)malloc(sizeof(Attribute));
    strncpy(newAttr->name, name, MAX_ATTRIBUTE_LENGTH);
    strncpy(newAttr->value, value, MAX_ATTRIBUTE_LENGTH);
    newAttr->next = node->attributes;
    node->attributes = newAttr;
}

void addChild(XMLNode *parent, XMLNode *child) {
    child->next = parent->children;
    parent->children = child;
}

void parseXML(const char *filename, XMLNode *root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_XML_LINE_LENGTH];
    XMLNode *currentNode = root;

    while (fgets(line, sizeof(line), file)) {
        trimWhitespace(line);
        if (line[0] == '\0') continue; // Skip empty lines shearing
       
        char *startTag = strstr(line, "<");
        char *endTag = strstr(line, ">");
        
        // Handle start tags
        if (startTag && endTag && startTag < endTag) {
            *endTag = '\0';
            char *tagName = startTag + 1; // Skip '<'
            char *space = strstr(tagName, " ");
            if (space) {
                *space = '\0'; // Null-terminate the tag name
                char *attributesStart = space + 1; // Start of attributes
                
                char *attributeToken = strtok(attributesStart, " ");
                while (attributeToken != NULL) {
                    char *equalsPos = strchr(attributeToken, '=');
                    if (equalsPos) {
                        *equalsPos = '\0';
                        char *value = equalsPos + 2; // Skip '=' and opening quote
                        value[strlen(value) - 1] = '\0'; // Remove closing quote
                        addAttribute(currentNode, attributeToken, value);
                    }
                    attributeToken = strtok(NULL, " ");
                }
            }

            addChild(currentNode, createNode(tagName));
            currentNode = currentNode->children; // Move to new node
        } 
        // Handle end tags
        else if (strstr(line, "</")) {
            currentNode = root; // Move back to root for simplicity
        }
    }
    
    fclose(file);
}

void printXML(XMLNode *node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s", node->tag);
    
    for (Attribute *attr = node->attributes; attr; attr = attr->next) {
        printf(" %s=\"%s\"", attr->name, attr->value);
    }
    
    printf(">\n");
    
    printXML(node->children, depth + 1); // Print children

    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", node->tag);
    printXML(node->next, depth); // Print siblings
}

void freeXML(XMLNode *node) {
    if (!node) return;
    
    freeXML(node->children); // Free children
    freeXML(node->next); // Free siblings
    
    for (Attribute *attr = node->attributes; attr; ) {
        Attribute *nextAttr = attr->next;
        free(attr);
        attr = nextAttr;
    }
    
    free(node);
}

char* trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;
    
    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    return str;
}