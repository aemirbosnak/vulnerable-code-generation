//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char tag[50];
    char value[256];
    struct Element* next;
    struct Element* child;
} Element;

// Function to create a new XML element
Element* createElement(const char* tag, const char* value) {
    Element* el = (Element*)malloc(sizeof(Element));
    strncpy(el->tag, tag, sizeof(el->tag));
    strncpy(el->value, value, sizeof(el->value));
    el->next = NULL;
    el->child = NULL;
    return el;
}

// Function to append a child element
void appendChild(Element* parent, Element* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Element* current = parent->child;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

// Function to free the entire XML structure
void freeElement(Element* el) {
    if (el) {
        freeElement(el->child);
        freeElement(el->next);
        free(el);
    }
}

// Function to print the XML structure
void printXML(Element* el, int depth) {
    if (el) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("<%s>%s\n", el->tag, el->value);
        printXML(el->child, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", el->tag);
        printXML(el->next, depth);
    }
}

// Simple XML Parser: Parses a given string
Element* parseXML(const char* xml) {
    // For simplicity, this parser will only work on a specific XML format
    Element* root = NULL;
    Element* current = NULL;

    const char* pos = xml;
    char tag[50];
    char value[256];
    
    while (*pos) {
        if (*pos == '<') {
            // End of tag
            if (*(pos + 1) == '/') {
                // Closing tag
                pos += 2; // Skip "</"
                char* end = strchr(pos, '>');
                if (end) {
                    *end = '\0';
                    pos = end + 1; // Move after ">"
                }
                current = current ? current->next : NULL; // Move up
            } else {
                // Opening tag
                pos++; // Skip "<"
                char* end = strchr(pos, '>');
                if (end) {
                    *end = '\0';
                    strncpy(tag, pos, sizeof(tag));
                    tag[sizeof(tag) - 1] = '\0';
                    pos = end + 1; // Move after ">"
                    // Extract value until next tag or end
                    char* valStart = pos;
                    while (*pos && *pos != '<') pos++;
                    int len = pos - valStart;
                    strncpy(value, valStart, len);
                    value[len] = '\0';
                    Element* newElement = createElement(tag, value);
                    if (current) {
                        appendChild(current, newElement);
                    } else {
                        root = newElement;
                    }
                    current = newElement; // Set current to new
                }
            }
        }
        pos++;
    }

    return root;
}

int main() {
    const char* xmlData = "<root>Data <child>More data</child></root>";

    Element* xmlTree = parseXML(xmlData);
    printf("Parsed XML Structure:\n");
    printXML(xmlTree, 0);
    
    freeElement(xmlTree);
    return 0;
}