//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_TAG 256

typedef struct XmlNode {
    char tag[MAX_TAG];
    char *value;
    struct XmlNode *next;
} XmlNode;

XmlNode* createNode(const char *tag, const char *value) {
    XmlNode *newNode = (XmlNode *)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG);
    newNode->value = strdup(value);
    newNode->next = NULL;
    return newNode;
}

void freeList(XmlNode *head) {
    while (head) {
        XmlNode *temp = head;
        head = head->next;
        free(temp->value);
        free(temp);
    }
}

void parseXML(FILE *file, XmlNode **head) {
    char line[MAX_LINE];
    char currentTag[MAX_TAG] = {0};
    
    while (fgets(line, sizeof(line), file)) {
        char *startTag = strstr(line, "<");
        char *endTag = strstr(line, ">");

        if (startTag && endTag && startTag < endTag) {
            // Extract the tag
            size_t tagLength = endTag - startTag - 1;
            if (tagLength < MAX_TAG) {
                strncpy(currentTag, startTag + 1, tagLength);
                currentTag[tagLength] = '\0'; // Null terminate the string
                
                // Check for closing tag
                if (currentTag[0] == '/') {
                    // Closing tag found! Do nothing for now.
                    continue;
                }
                
                // Extracting value (assuming values are in the same line for simplicity)
                char *valueStart = endTag + 1;
                char *valueEnd = strstr(valueStart, "<");
                if (valueEnd) {
                    *valueEnd = '\0'; // Terminate value string
                }
                
                XmlNode *node = createNode(currentTag, valueStart);
                node->next = *head;
                *head = node;
            }
        }
    }
}

void printXML(XmlNode *head) {
    while (head) {
        printf("Tag: %s, Value: %s\n", head->tag, head->value);
        head = head->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    XmlNode *head = NULL;
    
    parseXML(file, &head);
    fclose(file);
    
    printf("Parsed XML Elements:\n");
    printXML(head);
    
    freeList(head);
    return EXIT_SUCCESS;
}