//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct Element {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct Element* next;
} Element;

Element* head = NULL;

void addElement(const char* tag, const char* content) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (!newElement) exit(EXIT_FAILURE);
    
    strncpy(newElement->tag, tag, MAX_TAG_LENGTH);
    strncpy(newElement->content, content, MAX_LINE_LENGTH);
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        Element* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void printElements() {
    Element* current = head;
    while (current) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }
}

void parseLine(const char* line) {
    const char* openTagStart = strchr(line, '<');
    const char* closeTagStart = strchr(line, '>');
    
    if (openTagStart && closeTagStart) {
        size_t tagLength = closeTagStart - openTagStart - 1;
        char tag[MAX_TAG_LENGTH];
        strncpy(tag, openTagStart + 1, tagLength);
        tag[tagLength] = '\0';  // Closing the string

        const char* contentStart = closeTagStart + 1;
        const char* closeTag = strstr(contentStart, "</");
        
        if (closeTag) {
            size_t contentLength = closeTag - contentStart;
            char content[MAX_LINE_LENGTH];
            strncpy(content, contentStart, contentLength);
            content[contentLength] = '\0';  // Closing the string

            addElement(tag, content);
        }
    }
}

void freeElements() {
    Element* current = head;
    Element* nextElement;
    
    while (current != NULL) {
        nextElement = current->next;
        free(current);
        current = nextElement;
    }
}

int main() {
    FILE* file = fopen("sample.xml", "r");
    if (!file) {
        fprintf(stderr, "Could not open file\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLine(line);
    }
    
    fclose(file);
    
    printElements();
    freeElements();

    return EXIT_SUCCESS;
}