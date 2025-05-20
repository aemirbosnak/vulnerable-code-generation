//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the XML structure
typedef struct XML {
    char tag[20];
    char attribute[20];
    char value[20];
    struct XML* parent;
    struct XML* child;
} XML;

// Build an XML node
XML* buildXMLNode(char tag[], char attribute[], char value[]) {
    XML* node = (XML*) malloc(sizeof(XML));
    strcpy(node->tag, tag);
    strcpy(node->attribute, attribute);
    strcpy(node->value, value);
    node->parent = NULL;
    node->child = NULL;
    return node;
}

// Add a child node to an XML node
void addChildToXMLNode(XML* parent, XML* child) {
    child->parent = parent;
    if(parent->child == NULL) {
        parent->child = child;
    } else {
        XML* ptr = parent->child;
        while(ptr->child != NULL) {
            ptr = ptr->child;
        }
        ptr->child = child;
    }
}

// Build the XML tree from a file
XML* buildXMLTreeFromFile(char filename[]) {
    // Open the file
    FILE* file = fopen(filename, "r");

    // Check that the file exists
    if(file == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    // Create the root node
    XML* root = buildXMLNode("", "", "");

    // Set the current node to the root node
    XML* currNode = root;

    // Read each line of the file
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // Check if the line is a tag
        if(line[0] == '<' && line[1] != '/') {
            // Get the tag and attribute
            char tag[20], attribute[20];
            sscanf(line, "<%[^> ] %[^>]", tag, attribute);
            // Get the value
            char value[20] = "";
            strcpy(value, strtok(NULL, ">"));

            // Build the child node
            XML* child = buildXMLNode(tag, attribute, value);
            // Add the child node to the current node
            addChildToXMLNode(currNode, child);
            // Update the current node to be the child node
            currNode = child;
        }
        // Check if the line is a closing tag
        else if(line[0] == '<' && line[1] == '/') {
            // Update the current node to be the parent node
            currNode = currNode->parent;
        }
        // Otherwise, the line is a value
        else {
            // Update the value of the current node
            strcpy(currNode->value, line);
        }
    }

    // Close the file and return the root node
    fclose(file);
    return root;
}

// Print the XML tree
void printXMLTree(XML* node, int depth) {
    // Print the node
    printf("%*s<%s %s>%s\n", depth*4, " ", node->tag, node->attribute, node->value);
    // Print each child node
    XML* ptr = node->child;
    while(ptr != NULL) {
        printXMLTree(ptr, depth+1);
        ptr = ptr->child;
    }
    // Print the closing tag
    printf("%*s</%s>\n", depth*4, " ", node->tag);
}

// The main function
int main() {
    // Build the XML tree from a file
    XML* root = buildXMLTreeFromFile("example.xml");

    // Print the XML tree
    printXMLTree(root, 0);

    return 0;
}