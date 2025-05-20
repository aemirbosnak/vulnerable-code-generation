//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tag[50];
    char value[100];
    struct Node* next;
    struct Node* children;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (!node) return;
    freeNode(node->children);
    freeNode(node->next);
    free(node);
}

void printXML(Node* node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("<%s>", node->tag);
    
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    
    printf("\n");
    
    printXML(node->children, depth + 1);
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    printf("</%s>\n", node->tag);
    
    printXML(node->next, depth);
}

Node* parseXML(const char* xml) {
    Node* head = NULL;
    Node** current = &head;
    
    char* tagStart = strstr(xml, "<");
    while (tagStart) {
        char* tagEnd = strstr(tagStart, ">");
        if (!tagEnd) break;
        
        int tagLength = tagEnd - tagStart - 1;
        char tag[50] = {0};
        strncpy(tag, tagStart + 1, tagLength);
        
        char* valueStart = tagEnd + 1;
        char* valueEnd = strstr(valueStart, "<");
        char value[100] = {0};
        
        if (valueEnd) {
            int valueLength = valueEnd - valueStart;
            strncpy(value, valueStart, valueLength);
        }
        
        Node* node = createNode(tag, value);
        *current = node;
        current = &node->next;
        
        tagStart = strstr(valueEnd, "<");
    }
    
    return head;
}

int main() {
    const char* xmlData = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    
    printf("Parsing the following XML:\n%s\n", xmlData);
    
    Node* xmlTree = parseXML(xmlData);
    
    printf("\nParsed XML structure:\n");
    printXML(xmlTree, 0);
    
    freeNode(xmlTree);
    
    return 0;
}