//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTRIBUTE_LENGTH 50
#define MAX_ATTRIBUTE_COUNT 20

typedef struct attribute {
    char name[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_LENGTH];
} Attribute;

typedef struct node {
    char tag[MAX_TAG_LENGTH];
    Attribute attributes[MAX_ATTRIBUTE_COUNT];
    int attributeCount;
    char content[MAX_TAG_LENGTH];
    struct node *children;
} Node;

void printNode(Node *node) {
    printf("<%s", node->tag);
    for(int i = 0; i < node->attributeCount; i++) {
        printf(" %s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    printf(">%s", node->content);
    for(Node *current = node->children; current != NULL; current = current->children) {
        printNode(current);
    }
    printf("</%s>\n", node->tag);
}

int main() {
    Node *root = malloc(sizeof(Node));
    strcpy(root->tag, "root");
    strcpy(root->content, "");
    root->attributeCount = 0;
    
    Node *child1 = malloc(sizeof(Node));
    strcpy(child1->tag, "child1");
    Attribute child1Attribute1 = {"attr1", "value1"};
    Attribute child1Attribute2 = {"attr2", "value2"};
    child1->attributes[0] = child1Attribute1;
    child1->attributes[1] = child1Attribute2;
    child1->attributeCount = 2;
    strcpy(child1->content, "Hello World");
    child1->children = NULL;
    
    root->children = child1;
    child1->children = NULL;
    
    printNode(root);
    
    return 0;
}