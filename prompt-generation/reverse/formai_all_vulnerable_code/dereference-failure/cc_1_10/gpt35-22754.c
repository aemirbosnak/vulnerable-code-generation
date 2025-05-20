//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for XML tags
#define MAX_TAG_LENGTH 20

// Define a struct to hold tag information
typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    char* content;
    struct Tag* children[10];
    int child_count;
} Tag;

// Define a global variable to hold the root tag
Tag root;

// Define a helper function to insert a child tag into a parent tag
void insert_child(Tag* parent, Tag* child) {
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

// Define a recursive function to parse the XML document
void parse_xml(FILE* fp, Tag* parent) {
    // Define a buffer to hold lines from the file
    char buffer[MAX_TAG_LENGTH + 3];

    // Loop through the file, reading one line at a time
    while (fgets(buffer, MAX_TAG_LENGTH + 3, fp)) {
        // Check for the end of the parent tag
        if (strstr(buffer, "</") == buffer) {
            return;
        }

        // Allocate memory for a new Tag struct
        Tag* tag = malloc(sizeof(Tag));

        // Copy the tag name from the buffer
        sscanf(buffer, "<%[^>]>", tag->name);

        // Initialize the child count to 0
        tag->child_count = 0;

        // Initialize the content pointer to NULL
        tag->content = NULL;

        // Check for self-closing tags
        if (strstr(buffer, "/>") != NULL) {
            // Insert the tag as a child of the parent
            insert_child(parent, tag);
        } else {
            // Parse the contents of the tag recursively
            parse_xml(fp, tag);

            // Read the closing tag
            fgets(buffer, MAX_TAG_LENGTH + 3, fp);

            // Insert the tag as a child of the parent
            insert_child(parent, tag);
        }
    }
}

// Define a recursive function to print the contents of the XML document
void print_xml(Tag* tag, int indent_level) {
    // Print the tag name and content, if any
    for (int i = 0; i < indent_level; i++) { printf("    "); }
    printf("<%s>", tag->name);
    if (tag->content != NULL) { printf("%s", tag->content); }
    printf("\n");

    // Print the contents of each child tag, recursively
    for (int i = 0; i < tag->child_count; i++) {
        print_xml(tag->children[i], indent_level + 1);
    }

    // Print the closing tag
    for (int i = 0; i < indent_level; i++) { printf("    "); }
    printf("</%s>\n", tag->name);
}

int main() {
    // Open the XML file for reading
    FILE* fp = fopen("example.xml", "r");

    // Check for errors opening the file
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Parse the XML document
    parse_xml(fp, &root);

    // Print the contents of the XML document
    print_xml(&root, 0);

    // Close the file
    fclose(fp);

    return 0;
}