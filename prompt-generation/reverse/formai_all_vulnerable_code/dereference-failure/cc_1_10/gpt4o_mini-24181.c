//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_XML_SIZE 1024

typedef struct Element {
    char tag[MAX_TAG_NAME];
    char value[MAX_XML_SIZE];
    struct Element* next;
} Element;

Element* head = NULL;

void addElement(const char* tag, const char* value) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    strncpy(newElement->tag, tag, MAX_TAG_NAME);
    strncpy(newElement->value, value, MAX_XML_SIZE);
    newElement->next = head;
    head = newElement;
}

void freeElements() {
    Element* current = head;
    Element* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void printElements() {
    Element* current = head;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}

void parseXML(const char* xml) {
    char tag[MAX_TAG_NAME];
    char value[MAX_XML_SIZE];
    int index = 0;
    int inTag = 0;

    const char* pos = xml;

    while (*pos) {
        if (*pos == '<') {
            inTag = 1;
            index = 0;
            pos++; // Move past '<'
            while (*pos != '>' && *pos != '\0') {
                tag[index++] = *pos++;
            }
            tag[index] = '\0'; // Null-terminate the tag

            // Move past '>'
            if (*pos == '>') pos++;

        } else if (inTag == 1) {
            index = 0;
            while (*pos != '<' && *pos != '\0') {
                value[index++] = *pos++;
            }
            value[index] = '\0'; // Null-terminate the value

            addElement(tag, value);
            inTag = 0; // Reset inTag
        } else {
            pos++;
        }
    }
}

int main() {
    const char* xmlString = "<greeting>Hello, World!</greeting><farewell>Goodbye!</farewell>";

    printf("Parsing XML: %s\n", xmlString);
    parseXML(xmlString);
    
    printf("\nParsed Elements:\n");
    printElements();

    // Free allocated memory
    freeElements();

    return 0;
}