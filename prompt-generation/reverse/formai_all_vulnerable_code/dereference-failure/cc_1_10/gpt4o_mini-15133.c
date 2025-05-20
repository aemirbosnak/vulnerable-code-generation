//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64

// Structure to hold an XML element
typedef struct Element {
    char tag[MAX_TAG_LENGTH];
    struct Element *next;
} Element;

// Function to create a new XML element
Element* createElement(const char *tag) {
    Element *newElement = (Element *)malloc(sizeof(Element));
    if (newElement == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newElement->tag, tag);
    newElement->next = NULL;
    return newElement;
}

// Function to add an element to the linked list
void addElement(Element **head, const char *tag) {
    Element *newElement = createElement(tag);
    newElement->next = *head;
    *head = newElement;
}

// Function to free the linked list of XML elements
void freeElements(Element *head) {
    Element *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to parse XML line by line
void parseXML(FILE *file, Element **head) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *start = strchr(line, '<');
        char *end = strchr(line, '>');
        if (start && end) {
            // Extract the tag, account for closing tag
            char tag[MAX_TAG_LENGTH];
            size_t length = end - start - 1;
            // Check for closing tag
            if (*(start + 1) == '/') {
                strncpy(tag, start + 2, length - 1);
                tag[length - 1] = '\0'; // Null-terminate
                printf("Alas! The tag of parting, < %s > hath been closed.\n", tag);
            } else {
                strncpy(tag, start + 1, length);
                tag[length] = '\0'; // Null-terminate
                printf("O sweet light, the tag hath been opened: < %s >\n", tag);
                addElement(head, tag);
            }
        }
    }
}

// Function to display all the tags
void displayTags(Element *head) {
    printf("In merry celebration, the tags of love are:\n");
    while (head) {
        printf("  < %s >\n", head->tag);
        head = head->next;
    }
}

int main() {
    FILE *file = fopen("example.xml", "r");
    if (!file) {
        fprintf(stderr, "Could not open file\n");
        return EXIT_FAILURE;
    }

    Element *head = NULL;
    parseXML(file, &head);
    fclose(file);

    displayTags(head);
    
    // Free the dynamically allocated memory
    freeElements(head);
    return 0;
}