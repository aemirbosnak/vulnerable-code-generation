//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 256
#define MAX_TAG_VALUE 1024

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char tagValue[MAX_TAG_VALUE];
    struct XmlNode *next;
} XmlNode;

XmlNode* createNode(const char *tagName, const char *tagValue) {
    XmlNode *newNode = (XmlNode *)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->tagValue, tagValue, MAX_TAG_VALUE);
    newNode->next = NULL;
    return newNode;
}

void appendNode(XmlNode **head, const char *tagName, const char *tagValue) {
    XmlNode *newNode = createNode(tagName, tagValue);
    if (*head == NULL) {
        *head = newNode;
    } else {
        XmlNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(XmlNode *head) {
    XmlNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(const XmlNode *head) {
    const XmlNode *temp = head;
    while (temp != NULL) {
        printf("Tag: %s, Value: %s\n", temp->tagName, temp->tagValue);
        temp = temp->next;
    }
}

void parseXml(const char *filename, XmlNode **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    char tagName[MAX_TAG_NAME];
    char tagValue[MAX_TAG_VALUE];
    
    while (fgets(line, sizeof(line), file)) {
        char *start, *end;

        // Find the opening tag
        start = strchr(line, '<');
        if (start) {
            end = strchr(start, '>');
            if (end) {
                size_t nameLength = end - start - 1;
                strncpy(tagName, start + 1, nameLength);
                tagName[nameLength] = '\0';

                // Find the value (assuming it's on the same line)
                start = end + 1;
                end = strchr(start, '<');
                if (end) {
                    size_t valueLength = end - start;
                    strncpy(tagValue, start, valueLength);
                    tagValue[valueLength] = '\0';

                    appendNode(head, tagName, tagValue);
                }
            }
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlNode *head = NULL;

    parseXml(argv[1], &head);
    printList(head);
    
    freeList(head);
    return EXIT_SUCCESS;
}