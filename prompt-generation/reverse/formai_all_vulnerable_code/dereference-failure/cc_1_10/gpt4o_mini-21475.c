//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_VALUE_LENGTH 256
#define MAX_ATTRIBUTES 10
#define MAX_XML_SIZE 1024

typedef struct {
    char name[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Attribute;

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    Attribute attributes[MAX_ATTRIBUTES];
    int attr_count;
    struct Node* children;
    struct Node* next;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->tag, tag);
    strcpy(node->value, value);
    node->attr_count = 0;
    node->children = NULL;
    node->next = NULL;
    return node;
}

void addAttribute(Node* node, const char* attr_name, const char* attr_value) {
    if (node->attr_count < MAX_ATTRIBUTES) {
        strcpy(node->attributes[node->attr_count].name, attr_name);
        strcpy(node->attributes[node->attr_count].value, attr_value);
        node->attr_count++;
    } else {
        printf("Max attributes reached for tag: %s\n", node->tag);
    }
}

void addChild(Node* parent, Node* child) {
    child->next = parent->children;
    parent->children = child;
}

void parseXML(const char* xml, Node* current_node) {
    const char* cursor = xml;
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int is_inside_tag = 0;

    while (*cursor) {
        if (*cursor == '<') {
            sscanf(cursor, "<%[^>]>", tag);
            if (strcmp(tag, "/") == 0) {
                break; // Close tag reached
            }
            else {
                // Creating a new node for the tag
                Node* child = createNode(tag, "");
                addChild(current_node, child);
                current_node = child;
                is_inside_tag = 1;
            }
            cursor += strlen(tag) + 2;
        } else if (*cursor == '>') {
            if (is_inside_tag) {
                // Move past the '>' character
                cursor++;
                // Capture the value until the next '<'
                sscanf(cursor, "%[^<]", value);
                strcpy(current_node->value, value);
                cursor += strlen(value);
                is_inside_tag = 0;
            }
        } else {
            cursor++;
        }
    }
}

void printXML(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s\n", node->tag, node->value);
    for (int i = 0; i < node->attr_count; i++) {
        printf("  ");
        printf("%s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    if (node->children) {
        printXML(node->children, depth + 1);
    }
    for (Node* nxt = node->next; nxt; nxt = nxt->next) {
        printXML(nxt, depth);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->children);
        freeNode(node->next);
        free(node);
    }
}

int main() {
    char xml_data[MAX_XML_SIZE] = "<root><child>Hello World</child><child><subchild>Surviving the wasteland!</subchild></child></root>";
    Node* root = createNode("root", "");
    parseXML(xml_data, root);

    printf("Parsed XML Structure:\n");
    printXML(root, 0);
    
    freeNode(root);
    return 0;
}