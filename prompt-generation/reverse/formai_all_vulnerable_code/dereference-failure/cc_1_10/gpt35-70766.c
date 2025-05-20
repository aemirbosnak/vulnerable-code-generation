//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 50
#define MAX_ATTRIBUTE_SIZE 20
#define MAX_ATTRIBUTES 10

// Define the tag struct
struct tag {
    char name[MAX_ELEMENT_SIZE];
    char attributes[MAX_ATTRIBUTES][MAX_ATTRIBUTE_SIZE];
    int num_attributes;
    struct tag* child;
    struct tag* sibling;
};

// Declare function to parse XML file
struct tag* parseFile(FILE* fp);

// Declare helper functions for parsing tags, attributes, and values
char* parseTag(char* str, char* tag);
char* parseAttribute(char* str, char* attribute);
char* parseValue(char* str, char* value);

// Main function to read XML file and print out the parsed tags
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: xmlparser <filename>\n");
        return -1;
    }

    // Open file for reading
    FILE* fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Error: couldn't open file %s\n", argv[1]);
        return -1;
    }

    // Parse the file and close the file pointer
    struct tag* root = parseFile(fp);
    fclose(fp);

    // Print out the parsed tags
    printf("Parsed tags:\n");
    struct tag* cur_tag = root;
    while (cur_tag != NULL) {
        printf("Tag name: %s\n", cur_tag->name);
        printf("Attributes (%d):\n", cur_tag->num_attributes);
        for (int i = 0; i < cur_tag->num_attributes; i++) {
            printf("%s\n", cur_tag->attributes[i]);
        }

        cur_tag = cur_tag->sibling;
    }

    return 0;
}

// Function to parse the XML file and return the root tag
struct tag* parseFile(FILE* fp) {
    char buf[MAX_ELEMENT_SIZE];
    struct tag* root = NULL;
    struct tag* cur_tag = NULL;
    int inside_tag = 0;

    // Read the file line by line
    while (fgets(buf, sizeof buf, fp) != NULL) {
        if (inside_tag) {
            // Parse attributes or value
            if (strncmp(buf, "/", 1) != 0) {
                // Parse attribute
                char attribute[MAX_ATTRIBUTE_SIZE];
                cur_tag->child->num_attributes++;
                parseAttribute(buf, attribute);
                strcpy(cur_tag->child->attributes[cur_tag->child->num_attributes - 1], attribute);
            } else {
                // End of tag, reset inside_tag and move to sibling
                inside_tag = 0;
                cur_tag = cur_tag->sibling;
            }
        } else {
            // Parse tag name and value
            if (strncmp(buf, "<", 1) == 0) {
                // Start of new tag
                char tag[MAX_ELEMENT_SIZE];
                char value[MAX_ELEMENT_SIZE];
                struct tag* new_tag = (struct tag*) malloc(sizeof(struct tag));
                new_tag->num_attributes = 0;
                new_tag->child = NULL;
                new_tag->sibling = NULL;
                parseTag(buf, tag);
                strcpy(new_tag->name, tag);

                // Parse value, if there is one
                if (fgets(buf, sizeof buf, fp) != NULL) {
                    parseValue(buf, value);
                    cur_tag->child = new_tag;
                    strcpy(cur_tag->child->name, value);
                } else {
                    // No value, just set child tag
                    cur_tag->child = new_tag;
                }

                // Set current tag and set inside_tag to true
                cur_tag = new_tag;
                inside_tag = 1;
            }
        }

        // Set root tag if not yet set
        if (root == NULL) {
            root = cur_tag;
        }
    }

    return root;
}

// Helper function to parse tag from input string
char* parseTag(char* str, char* tag) {
    // Move past '<' character
    str++;

    // Copy characters up until whitespace or '>'
    int i = 0;
    while (str[i] != ' ' && str[i] != '>') {
        tag[i] = str[i];
        i++;
    }
    tag[i] = '\0';

    return str + i;
}

// Helper function to parse attribute from input string
char* parseAttribute(char* str, char* attribute) {
    // Move past whitespace and attribute name
    str = strstr(str, " ");
    str++;

    // Copy attribute value inside quotes
    int i = 0;
    while (str[i] != '\"') {
        i++;
    }
    i++;
    int j = 0;
    while (str[i] != '\"') {
        attribute[j] = str[i];
        i++;
        j++;
    }
    attribute[j] = '\0';

    return str + i;
}

// Helper function to parse value from input string
char* parseValue(char* str, char* value) {
    // Trim whitespace and newlines from string
    int i = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r') {
        i++;
    }

    int j = strlen(str) - 1;
    while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' || str[j] == '\r') {
        j--;
    }

    // Copy trimmed string into value variable
    int k = 0;
    for (int l = i; l <= j; l++) {
        value[k] = str[l];
        k++;
    }
    value[k] = '\0';

    return str + j;
}