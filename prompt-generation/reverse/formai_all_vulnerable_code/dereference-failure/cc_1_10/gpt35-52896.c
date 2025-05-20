//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Define struct to hold XML data
typedef struct {
    char tag[100];
    char value[100];
} XMLData;

// Define struct to represent XML node
typedef struct node {
    XMLData data;
    struct node * child;
    struct node * sibling;
} XMLNode;

// Function to parse XML string
XMLNode * parseXML(char * xml) {
    // Initialize variables
    int i = 0, start = 0;
    XMLNode * root = NULL;
    XMLNode * parent = NULL;
    XMLNode * current = NULL;
    XMLData data;
    char tag[100];
    char value[100];

    // Loop through each character in XML string
    while(xml[i] != '\0') {
        switch(xml[i]) {
            case '<':
                // If tag is starting tag
                if(xml[i+1] != '/') {
                    // Add current node as a child to parent node
                    if(parent && current) {
                        parent->child = current;
                    }

                    // Create new node
                    current = (XMLNode *) malloc(sizeof(XMLNode));
                    current->child = NULL;
                    current->sibling = NULL;

                    // Set tag
                    start = i + 1;
                    while(xml[i] != '>') {
                        i++;
                    }
                    strncpy(tag, &xml[start], i-start);
                    tag[i-start] = '\0';
                    strncpy(current->data.tag, tag, strlen(tag)+1);

                    // Set parent
                    if(parent != NULL) {
                        current->sibling = parent->child;
                        parent->child = current;
                    }
                    parent = current;

                // If tag is closing tag
                } else {
                    // Add value to current node
                    if(current != NULL) {
                        start = i + 2;
                        while(xml[i+1] != '>') {
                            i++;
                        }
                        strncpy(value, &xml[start], i-start);
                        value[i-start] = '\0';
                        strncpy(current->data.value, value, strlen(value)+1);
                    }

                    // Move up to parent node
                    parent = parent->sibling;
                    current = parent;
                }
                break;

            default:
                break;
        }
        i++;
    }

    // Return root of XML tree
    return current;
}

// Function to print XML tree recursively
void printXML(XMLNode * node, int depth) {
    // Print tag and value of current node
    for(int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("<%s>%s</%s>\n", node->data.tag, node->data.value, node->data.tag);

    // Print child nodes
    if(node->child != NULL) {
        printXML(node->child, depth + 1);
    }

    // Print sibling nodes
    if(node->sibling != NULL) {
        printXML(node->sibling, depth);
    }
}

// Main function
int main() {
    // Initialize XML string
    char xml[] = "<root><name>John</name><age>30</age></root>";

    // Parse XML string
    XMLNode * root = parseXML(xml);

    // Print XML tree
    printXML(root, 0);

    // Exit program
    return 0;
}