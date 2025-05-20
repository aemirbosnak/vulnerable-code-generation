//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdlib.h>
#include <stdio.h>

// Define the maximum size of the XML file
#define MAX_SIZE 1024

// Declare the XML data structure
typedef struct {
    char* tag_name;
    char* tag_value;
    struct XML* sub_elements[MAX_SIZE];
    int num_sub_elements;
} XML;

// Declare the function that parses the XML file
XML* parse_xml(char* file_path);

// The main function
int main() {
    // Define the path to the XML file
    char* file_path = "example.xml";

    // Parse the XML file
    XML* root_element = parse_xml(file_path);

    // Print the root element tag name and value
    printf("Tag Name: %s\n", root_element->tag_name);
    printf("Tag Value: %s\n", root_element->tag_value);

    return 0;
}

// Function to parse the XML file
XML* parse_xml(char* file_path) {
    // Open the file
    FILE* xml_file = fopen(file_path, "r");

    // If the file doesn't exist, return null
    if(!xml_file) {
        printf("File %s not found.\n", file_path);
        return NULL;
    }

    // Create the root element
    XML* root_element = (XML*) malloc(sizeof(XML));

    // Initialize the root element
    root_element->tag_name = "root";
    root_element->tag_value = "";
    root_element->num_sub_elements = 0;

    // Declare the current element
    XML* current_element = root_element;

    // Read the XML file line by line
    char line[MAX_SIZE];
    while(fgets(line, MAX_SIZE, xml_file)) {
        // Check if the line is a start tag
        if(line[0] == '<' && line[1] != '/') {
            // Declare the new element
            XML* new_element = (XML*) malloc(sizeof(XML));

            // Initialize the new element
            new_element->tag_name = strtok(line, " <>");
            new_element->tag_value = "";
            new_element->num_sub_elements = 0;

            // Add the new element as a sub-element of the current element
            current_element->sub_elements[current_element->num_sub_elements] = new_element;
            current_element->num_sub_elements++;

            // Set the current element to the new element
            current_element = new_element;
        }
        // Check if the line is an end tag
        else if(line[0] == '<' && line[1] == '/') {
            // Set the tag value of the current element
            current_element->tag_value = strtok(line, " <>/");

            // Set the current element to the parent element
            current_element = current_element->sub_elements[current_element->num_sub_elements - 1];
        }
        // Otherwise, the line is a value
        else {
            // Set the tag value of the current element
            current_element->tag_value = line;
        }
    }

    // Close the file
    fclose(xml_file);

    // Return the root element
    return root_element;
}