//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 256

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XMLNode* next;
} XMLNode;

XMLNode* createNode(const char* tagName, const char* value) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tagName, tagName, MAX_TAG_NAME_LENGTH);
    strncpy(node->value, value, MAX_VALUE_LENGTH);
    node->next = NULL;
    return node;
}

void appendNode(XMLNode** head, const char* tagName, const char* value) {
    XMLNode* newNode = createNode(tagName, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        XMLNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(XMLNode* head) {
    while (head) {
        XMLNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void printXMLList(XMLNode* head) {
    printf("Parsed XML Data:\n");
    while (head) {
        printf("Tag: <%s>, Value: \"%s\"\n", head->tagName, head->value);
        head = head->next;
    }
}

void parseXML(const char* filename, XMLNode** head) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    char line[512];
    char tagName[MAX_TAG_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int inTag = 0;

    while (fgets(line, sizeof(line), file)) {
        char* startTag = strchr(line, '<');
        char* endTag = strchr(line, '>');
        if (startTag && endTag) {
            if (endTag > startTag) {
                inTag = 1;
                strncpy(tagName, startTag + 1, endTag - startTag - 1);
                tagName[endTag - startTag - 1] = '\0';
            }
        }

        char* valueStart = endTag + 1;
        char* valueEnd = strchr(valueStart, '<');
        if (valueStart && valueEnd) {
            strncpy(value, valueStart, valueEnd - valueStart);
            value[valueEnd - valueStart] = '\0';
            appendNode(head, tagName, value);
            inTag = 0;
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* xmlList = NULL;
    parseXML(argv[1], &xmlList);
    printXMLList(xmlList);
    freeList(xmlList);

    return EXIT_SUCCESS;
}