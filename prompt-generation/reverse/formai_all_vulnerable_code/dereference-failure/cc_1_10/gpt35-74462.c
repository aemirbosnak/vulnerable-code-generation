//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define parent and child node structures for the XML document
struct parent_node {
    char name[20];
    int num_children;
    struct child_node *children;
};

struct child_node {
    char name[20];
    char content[100];
};

// Declare the asynchronous XML parser function
void parse_xml_asynchronous(char* filename, void(*callback)(struct parent_node*));

// Define the asynchronous XML parser function
void parse_xml_asynchronous(char* filename, void(*callback)(struct parent_node*)) {
    FILE *fp;
    char current_tag[20], current_content[100];
    struct parent_node parent;
    struct child_node child;

    // Open the XML file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the first line of the file to get the parent node name
    fscanf(fp, "<%[^>]>", parent.name);
    parent.num_children = 0;
    parent.children = malloc(sizeof(struct child_node));

    // Loop through the file until the end is reached
    while (fscanf(fp, "<%[^>]>", current_tag) != EOF) {
        // If the current tag is the parent closing tag, call the callback function
        if (strcmp(current_tag, parent.name) == 0) {
            callback(&parent);
            return;
        }
        // If the current tag is a child opening tag, read the content of the child
        else {
            fscanf(fp, "%[^<]", current_content);
            // If the parent has more than one child, resize the children array to fit the new child
            if (parent.num_children > 0) {
                parent.children = realloc(parent.children, (parent.num_children + 1) * sizeof(struct child_node));
            }
            strcpy(parent.children[parent.num_children].name, current_tag);
            strcpy(parent.children[parent.num_children].content, current_content);
            parent.num_children++;
        }
    }

    // Close the file
    fclose(fp);
}

// Define a callback function that prints the XML data
void callback_function(struct parent_node *parent) {
    int i;
    printf("Parent node: %s\n", parent->name);
    for (i = 0; i < parent->num_children; i++) {
        printf("Child node %d: %s\n", i + 1, parent->children[i].name);
        printf("Child content %d: %s\n", i + 1, parent->children[i].content);
    }
}

int main() {
    printf("Parsing XML file asynchronously...\n");
    parse_xml_asynchronous("example.xml", callback_function);
    printf("XML file parsing complete.\n");
    return 0;
}