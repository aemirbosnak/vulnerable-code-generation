//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for XML elements
typedef struct XmlElement {
    char tag[50];
    char content[200];
    struct XmlElement *next;
} XmlElement;

// Function to create a new XML element
XmlElement* createElement(const char* tag, const char* content) {
    XmlElement* newElement = (XmlElement*)malloc(sizeof(XmlElement));
    strcpy(newElement->tag, tag);
    strcpy(newElement->content, content);
    newElement->next = NULL;
    return newElement;
}

// Function to free the XML elements
void freeElements(XmlElement* head) {
    XmlElement* current = head;
    XmlElement* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function to parse a simple XML string into elements
XmlElement* parseXml(const char* xml) {
    XmlElement *head = NULL, *tail = NULL;
    const char* pos = xml;

    while (*pos) {
        // Check for the opening tag
        if (*pos == '<') {
            const char* startTag = ++pos;
            while (*pos && *pos != '>') pos++; // move to '>'
            if (*pos == '>') {
                char tag[50];
                strncpy(tag, startTag, pos - startTag);
                tag[pos - startTag] = '\0'; // Null-terminate the tag
                
                // Move past '>'
                pos++;

                // Now find the content until the closing tag
                const char* startContent = pos;
                while (*pos && strncmp(pos, "</", 2) != 0) pos++;
                char content[200];
                strncpy(content, startContent, pos - startContent);
                content[pos - startContent] = '\0'; // Null-terminate the content

                // Check for the closing tag
                if (strncmp(pos, "</", 2) == 0) {
                    pos += 2; // Move to the tag after '</'
                    while (*pos && *pos != '>') pos++; // move to '>'
                    if (*pos == '>') {
                        // Create a new XML element
                        XmlElement* element = createElement(tag, content);
                        // Add to the linked list
                        if (head == NULL) {
                            head = element;
                            tail = element;
                        } else {
                            tail->next = element;
                            tail = element;
                        }
                    }
                }
                // Move past '>'
                pos++;
            }
        } else {
            pos++;
        }
    }
    return head;
}

// Function to print the parsed XML elements
void printXmlElements(XmlElement* head) {
    XmlElement* current = head;
    printf("Parsed XML Elements:\n");
    while (current) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }
}

int main() {
    const char* xmlData = "<greeting>Hello, World!</greeting><farewell>Goodbye, World!</farewell>";

    printf("Welcome to the Happy XML Parser!\n");
    printf("Let's parse some wonderful XML data:\n\n");

    XmlElement* parsedXml = parseXml(xmlData);
    printXmlElements(parsedXml);
    freeElements(parsedXml);

    printf("\nThank you for using the Happy XML Parser! Have a splendid day!\n");
    return 0;
}