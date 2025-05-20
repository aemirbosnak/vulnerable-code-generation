//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *tag;
    char *content;
    struct Element *next;
    struct Element *children;
} Element;

// Function to create a new XML Element
Element* createElement(const char *tag, const char *content) {
    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->tag = strdup(tag);
    newElement->content = content ? strdup(content) : NULL;
    newElement->next = NULL;
    newElement->children = NULL;
    return newElement;
}

// Function to free an XML Element and its children
void freeElement(Element *element) {
    if (!element) return;
    if (element->tag) free(element->tag);
    if (element->content) free(element->content);
    freeElement(element->children);
    freeElement(element->next);
    free(element);
}

// Function to parse a simple XML string
Element* parseXML(const char *xml) {
    Element *root = NULL;
    Element *current = NULL;
    char tagName[100];
    char content[256];
    int inTag = 0, inContent = 0, index = 0;
    const char *pos = xml;

    while (*pos) {
        if (*pos == '<') {
            if (inContent) {
                content[index] = '\0';
                if (current) {
                    current->content = strdup(content);
                }
                inContent = 0;
                index = 0;
            }
            inTag = 1;
            tagName[0] = '\0';
            pos++;
            while (*pos && *pos != '>') {
                strncat(tagName, pos, 1);
                pos++;
            }
            if (*pos == '>') {
                Element *newElement = createElement(tagName, NULL);
                if (!root) {
                    root = newElement;
                }
                if (current) {
                    newElement->next = current->children;
                    current->children = newElement;
                }
                current = newElement;
            }
        } else if (*pos == '</') {
            if (inContent) {
                content[index] = '\0';
                if (current) {
                    current->content = strdup(content);
                }
                inContent = 0;
                index = 0;
            }
            inTag = 0;
            pos++;
            while (*pos && *pos != '>') {
                pos++;
            }
            if (*pos == '>') {
                if (current) {
                    current = current->children; // move up to parent element
                }
            }
        } else if (inTag) {
            // Skip processing of content inside tags
        } else {
            inContent = 1;
            content[index++] = *pos;
        }
        pos++;
    }

    return root;
}

// Function to print XML Element
void printElement(Element *element, int level) {
    if (!element) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>", element->tag);
    if (element->content) {
        printf("%s", element->content);
    }
    printf("\n");

    printElement(element->children, level + 1);
    printf("\n");

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("</%s>\n", element->tag);
    printElement(element->next, level);
}

int main() {
    const char *xmlData = "<book><title>XML Parser</title><author>ChatGPT</author></book>";
    printf("Parsing XML:\n%s\n\n", xmlData);
    
    Element *xmlTree = parseXML(xmlData);
    
    printf("Parsed XML Structure:\n");
    printElement(xmlTree, 0);

    // Freeing the XML structure
    freeElement(xmlTree);
    
    return 0;
}