//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct XMLNode *next;
} XMLNode;

XMLNode* createNode(const char *tag, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    strncpy(node->value, value, MAX_LINE_LENGTH);
    node->next = NULL;
    return node;
}

void freeList(XMLNode *head) {
    XMLNode *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void printXMLList(XMLNode *head) {
    while (head) {
        printf("Tag: %s, Value: %s\n", head->tag, head->value);
        head = head->next;
    }
}

void parseXML(FILE *file, XMLNode **head) {
    char line[MAX_LINE_LENGTH];
    char currentTag[MAX_TAG_LENGTH];
    int inTag = 0;

    while (fgets(line, sizeof(line), file)) {
        char *tagStart = strchr(line, '<');
        char *tagEnd = strchr(line, '>');
        
        if (tagStart && tagEnd) {
            if (tagStart[1] != '/') { // Start tag
                strncpy(currentTag, tagStart + 1, tagEnd - tagStart - 1);
                currentTag[tagEnd - tagStart - 1] = '\0';
                
                // Find the closing tag on the next line
                if (fgets(line, sizeof(line), file)) {
                    tagStart = strchr(line, '<');
                    tagEnd = strchr(line, '>');
                    if (tagStart && tagEnd && tagStart[1] == '/') {
                        char value[MAX_LINE_LENGTH];
                        strncpy(value, line, tagStart - line);
                        value[tagStart - line] = '\0'; // null terminate
                        XMLNode *newNode = createNode(currentTag, value);
                        newNode->next = *head;
                        *head = newNode;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    XMLNode *head = NULL;

    parseXML(file, &head);
    
    fclose(file);

    printf("Parsed XML Tags and Values:\n");
    printXMLList(head);

    freeList(head);
    return 0;
}