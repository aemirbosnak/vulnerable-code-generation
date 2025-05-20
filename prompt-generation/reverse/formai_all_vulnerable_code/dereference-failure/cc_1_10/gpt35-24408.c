//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a constant for the maximum length of a tag.
#define MAX_TAG_LENGTH 50

// Define a struct to represent an XML tag.
typedef struct xmlTag {
    char name[MAX_TAG_LENGTH];
    struct xmlTag* parent;
    struct xmlTag* children;
    struct xmlTag* nextSibling;
    char* value;
} XmlDocument;

// Function to parse an XML string.
XmlDocument* parseXml(char* xml) {
    // Allocate memory for the document.
    XmlDocument* doc = (XmlDocument*)malloc(sizeof(XmlDocument));
    if (doc == NULL) {
        printf("Error: could not allocate memory for XmlDocument\n");
        return NULL;
    }
    
    // Initialize the document.
    doc->parent = NULL;
    doc->children = NULL;
    doc->nextSibling = NULL;
    doc->value = NULL;
    
    // Initialize variables for parsing.
    char* ptr = xml;
    char* startTag = NULL;
    char* endTag = NULL;
    char* tagEnd = NULL;
    char tagName[MAX_TAG_LENGTH];
    int tagLength = 0;
    
    // Loop through the string.
    while (*ptr) {
        // Look for start tags.
        if (*ptr == '<') {
            // Save a pointer to the start tag.
            startTag = ptr;
        }
        // Look for end tags.
        if (*ptr == '>' && startTag != NULL) {
            // Save a pointer to the end tag.
            endTag = ptr;
            // Calculate the tag length.
            tagLength = endTag - startTag - 1;
            // Extract the tag name.
            strncpy(tagName, startTag+1, tagLength);
            tagName[tagLength] = '\0';
            // Check if it's a start or end tag.
            if (tagName[0] != '/') {
                // Create a new tag.
                XmlDocument* newTag = (XmlDocument*)malloc(sizeof(XmlDocument));
                if (newTag == NULL) {
                    printf("Error: could not allocate memory for new tag\n");
                    return NULL;
                }
                // Initialize the new tag.
                strncpy(newTag->name, tagName, MAX_TAG_LENGTH);
                newTag->parent = doc;
                newTag->children = NULL;
                newTag->nextSibling = NULL;
                newTag->value = NULL;
                // Attach the new tag to the document.
                if (doc->children == NULL) {
                    doc->children = newTag;
                } else {
                    XmlDocument* lastChild = doc->children;
                    while (lastChild->nextSibling != NULL) {
                        lastChild = lastChild->nextSibling;
                    }
                    lastChild->nextSibling = newTag;
                }
            } else {
                // Find the matching start tag.
                XmlDocument* curTag = doc->children;
                while (curTag != NULL) {
                    if (strcmp(curTag->name, &tagName[1]) == 0) {
                        break;
                    }
                    curTag = curTag->nextSibling;
                }
                // Save a pointer to the tag end.
                tagEnd = endTag;
                // Move back through siblings to find the matching start tag.
                while (curTag != NULL && curTag->nextSibling != NULL) {
                    if (strcmp(curTag->name, &tagName[1]) == 0) {
                        break;
                    }
                    tagEnd = curTag->nextSibling->value - 1;
                    curTag = curTag->nextSibling;
                }
                // Extract the value between the tags.
                if (curTag != NULL && curTag->value == NULL) {
                    curTag->value = (char*)malloc(tagEnd - endTag);
                    if (curTag->value == NULL) {
                        printf("Error: could not allocate memory for tag value\n");
                        return NULL;
                    }
                    strncpy(curTag->value, endTag+1, tagEnd-endTag-1);
                    curTag->value[tagEnd-endTag-1] = '\0';
                }
            }
            // Reset the tag pointers.
            startTag = NULL;
            endTag = NULL;
        }
        // Move to the next character in the string.
        ptr++;
    }
    
    return doc;
}

// Function to print an XML document.
void printXml(XmlDocument* doc, int depth) {
    // Print the start tag.
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s", doc->name);
    if (doc->value != NULL) {
        printf(">%s", doc->value);
    } else {
        printf(">\n");
    }
    // Print the child tags.
    XmlDocument* child = doc->children;
    while (child != NULL) {
        printXml(child, depth+1);
        child = child->nextSibling;
    }
    // Print the end tag.
    if (doc->value == NULL) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", doc->name);
    }
}

int main() {
    char xml[] = "<note>\n"
                 "  <to>Tove</to>\n"
                 "  <from>Jani</from>\n"
                 "  <heading>Reminder</heading>\n"
                 "  <body>Don't forget me this weekend!</body>\n"
                 "</note>\n";
    XmlDocument* doc = parseXml(xml);
    printXml(doc, 0);
    return 0;
}