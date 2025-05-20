//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h>

// Define the structure of an XML element
typedef struct {
    char* name;
    char* value;
    struct element* child;
    struct element* next;
} element;

// Function prototypes
element* createElement(char* name, char* value);
element* addChild(element* parent, element* child);

// Main function
int main() {
    // Create the root element
    element* root = createElement("root", "");

    // Add some child elements
    root = addChild(root, createElement("child1", "value1"));
    root = addChild(root, createElement("child2", "value2"));
    root = addChild(root, createElement("child3", "value3"));

    // Print the XML document
    printf("<%s>\n", root->name);
    element* child = root->child;
    while (child!= NULL) {
        printf("\t<%s>%s</%s>\n", child->name, child->value, child->name);
        child = child->next;
    }
    printf("</%s>\n", root->name);

    return 0;
}

// Function to create a new XML element
element* createElement(char* name, char* value) {
    element* newElement = (element*) malloc(sizeof(element));
    newElement->name = name;
    newElement->value = value;
    newElement->child = NULL;
    newElement->next = NULL;

    return newElement;
}

// Function to add a child element to a parent element
element* addChild(element* parent, element* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        element* currentChild = parent->child;
        while (currentChild->next!= NULL) {
            currentChild = currentChild->next;
        }
        currentChild->next = child;
    }

    return parent;
}