//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store XML node data
typedef struct xml_node {
    char tag_name[50];
    char* value;
    int num_children;
    struct xml_node* children[50];
} xml_node;

// Function to parse XML data into a tree of xml_node structs
xml_node* parse_xml(char* xml_data) {
    // Allocate memory for the root node
    xml_node* root = (xml_node*) malloc(sizeof(xml_node));

    // Initialize root node values
    strcpy(root->tag_name, "root");
    root->value = NULL;
    root->num_children = 0;

    // Create a stack to keep track of parents as we parse the XML data
    xml_node* parent_stack[50];
    int stack_index = -1;

    // Loop through each character in the XML data
    for (int i = 0; i < strlen(xml_data); i++) {
        // If we find a tag opening, create a new child node and push it onto the stack
        if (xml_data[i] == '<' && xml_data[i+1] != '/') {
            // Create a new xml_node and initialize its values
            xml_node* child = (xml_node*) malloc(sizeof(xml_node));
            char* tag_name_start = &xml_data[i+1];
            char* tag_name_end = strchr(tag_name_start, '>');
            int tag_name_length = tag_name_end - tag_name_start;
            strncpy(child->tag_name, tag_name_start, tag_name_length);
            child->tag_name[tag_name_length] = '\0';
            child->value = NULL;
            child->num_children = 0;

            // Add the child to the parent's list of children
            parent_stack[stack_index]->children[parent_stack[stack_index]->num_children] = child;
            parent_stack[stack_index]->num_children++;

            // Push the child onto the stack
            stack_index++;
            parent_stack[stack_index] = child;

            // Move the index past the end of the tag opening
            i = tag_name_end - xml_data;
        }
        // If we find a tag closing, pop the current node off the stack
        else if (xml_data[i] == '<' && xml_data[i+1] == '/') {
            stack_index--;
            // Move the index past the end of the tag closing
            i += strlen(parent_stack[stack_index]->tag_name) + 2;
        }
        // If we find a data value, add it to the current node's value
        else {
            // If the current node doesn't have a value yet, allocate memory for its value string
            if (parent_stack[stack_index]->value == NULL) {
                parent_stack[stack_index]->value = (char*) malloc(sizeof(char));
                parent_stack[stack_index]->value[0] = '\0';
            }

            // Append the current character to the end of the value string
            int value_length = strlen(parent_stack[stack_index]->value);
            parent_stack[stack_index]->value = (char*) realloc(parent_stack[stack_index]->value, value_length + 2);
            parent_stack[stack_index]->value[value_length] = xml_data[i];
            parent_stack[stack_index]->value[value_length+1] = '\0';
        }
    }

    return root;
}

int main() {
    // Sample XML data to parse
    char xml_data[] = "<root><example>foo</example><example>bar</example></root>";

    // Parse the XML data and print out the resulting tree
    xml_node* root = parse_xml(xml_data);
    printf("Root node tag: %s\n", root->tag_name);
    printf("Root node has %d children:\n", root->num_children);
    for (int i = 0; i < root->num_children; i++) {
        printf("  - %s: %s\n", root->children[i]->tag_name, root->children[i]->value);
    }

    return 0;
}