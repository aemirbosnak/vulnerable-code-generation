//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_VALUE_LENGTH 256

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    struct XMLNode *next;
} XMLNode;

void createNode(XMLNode** head, const char* tag, const char* value) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(newNode->tagName, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->next = (*head);
    (*head) = newNode;
}

void displayNodes(XMLNode* head) {
    XMLNode* current = head;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tagName, current->value);
        current = current->next;
    }
}

void freeNodes(XMLNode* head) {
    XMLNode* current = head;
    XMLNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void parseXML(const char* xmlContent, XMLNode** head) {
    const char* ptr = xmlContent;
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    int i = 0, j = 0;

    while (*ptr) {
        // Look for opening tag
        if (*ptr == '<') {
            ++ptr; // Skip '<'
            while (*ptr != '>') {
                tag[i++] = *ptr++;
            }
            tag[i] = '\0'; // Null-terminate the tag
            i = 0;
            ptr++; // Skip '>'

            // Look for value until the next '<'
            while (*ptr && *ptr != '<') {
                value[j++] = *ptr++;
            }
            value[j] = '\0'; // Null-terminate the value
            j = 0;

            if (*ptr == '<') { // If we hit another tag
                createNode(head, tag, value);
            }
        }
        ptr++;
    }
}

int main() {
    const char* xmlData = "<love><heart>Forever</heart></love><passion>Always</passion>";
    XMLNode* head = NULL;

    printf("Parsing XML...\n");
    parseXML(xmlData, &head);

    printf("\nHere are the tender thoughts captured in the XML heart...\n");
    displayNodes(head);

    freeNodes(head); // Free memory
    return 0;
}