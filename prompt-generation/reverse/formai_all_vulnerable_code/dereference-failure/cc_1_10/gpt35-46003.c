//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for tag names
#define MAX_TAG_NAME_LENGTH 50

// Define maximum length for XML elements
#define MAX_ELEMENT_LENGTH 200

// XML tag stucture
typedef struct XMLTag {
    char tag_name[MAX_TAG_NAME_LENGTH];
    struct XMLTag *parent_tag;
    struct XMLTag *child_tags[MAX_ELEMENT_LENGTH];
    char element_value[MAX_ELEMENT_LENGTH];
} XMLTag;

// Function to create a new tag
XMLTag *create_tag(char *tag_name, XMLTag *parent_tag) {
    XMLTag *tag = malloc(sizeof(XMLTag));

    // Copy tag name to new tag
    strcpy(tag->tag_name, tag_name);

    // Set parent tag
    tag->parent_tag = parent_tag;

    // Initialize child tags to NULL
    for(int i = 0; i < MAX_ELEMENT_LENGTH; i++) {
        tag->child_tags[i] = NULL;
    }

    // Initialize element value to empty string
    strcpy(tag->element_value, "");

    return tag;
}

// Function to get tag index in parent tag's child tags array
int get_tag_index(XMLTag *tag) {
    if(tag->parent_tag == NULL) {
        return -1;
    }

    for(int i = 0; i < MAX_ELEMENT_LENGTH; i++) {
        if(tag->parent_tag->child_tags[i] == tag) {
            return i;
        }
    }

    return -1;
}

// Function to check if string is whitespace
int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Function to parse XML document
XMLTag *parse_xml(char *xml_data) {
    // Initialize root tag
    XMLTag *root_tag = create_tag("root", NULL);

    // Set current tag to root tag
    XMLTag *current_tag = root_tag;

    // Parse XML data
    char *start = xml_data;
    char *end = xml_data;
    int is_tag_open = 0;

    while(1) {
        // Move start pointer to next tag
        while(*start && *start != '<') {
            start++;
        }

        // End of XML data
        if(!(*start)) {
            return root_tag;
        }

        // Move end pointer to closing angle bracket
        end = start;
        while(*end && *end != '>') {
            end++;
        }

        // End of XML data
        if(!(*end)) {
            return root_tag;
        }

        // Check if tag is open or closing
        if(*(start + 1) != '/') {
            // Open tag
            is_tag_open = 1;

            // Extract tag name
            char tag_name[MAX_TAG_NAME_LENGTH];
            int i = 0;
            start++;
            while(*start && !is_whitespace(*start) && *start != '>') {
                tag_name[i++] = *start++;
            }
            tag_name[i] = '\0';

            // Create new tag
            XMLTag *new_tag = create_tag(tag_name, current_tag);

            // Link new tag to current tag's child tags
            for(i = 0; i < MAX_ELEMENT_LENGTH; i++) {
                if(current_tag->child_tags[i] == NULL) {
                    current_tag->child_tags[i] = new_tag;
                    break;
                }
            }

            // Update current tag
            current_tag = new_tag;
        } else {
            // Closing tag
            is_tag_open = 0;

            // Extract tag name
            char tag_name[MAX_TAG_NAME_LENGTH];
            int i = 0;
            start += 2;
            while(*start && !is_whitespace(*start) && *start != '>') {
                tag_name[i++] = *start++;
            }
            tag_name[i] = '\0';

            // Move current tag to parent tag
            if(strcmp(tag_name, current_tag->tag_name) == 0) {
                current_tag = current_tag->parent_tag;
            } else {
                int tag_index = get_tag_index(current_tag);
                current_tag = current_tag->parent_tag;
                while(current_tag != NULL) {
                    if(current_tag->child_tags[tag_index] != NULL && strcmp(current_tag->child_tags[tag_index]->tag_name, tag_name) == 0) {
                        current_tag = current_tag->child_tags[tag_index];
                        break;
                    }
                    current_tag = current_tag->parent_tag;
                }
            }
        }

        // Extract element value
        if((is_tag_open && *end == '>') || (!is_tag_open && *(end - 1) == '/')) {
            start = end + 1;
            continue;
        }

        char element_value[MAX_ELEMENT_LENGTH];
        int i = 0;

        if(is_tag_open) {
            // Skip whitespace
            start = end + 1;
            while(*start && is_whitespace(*start)) {
                start++;
            }

            // Extract element value
            while(*start && *start != '<') {
                element_value[i++] = *start++;
            }
            element_value[i] = '\0';

            strcpy(current_tag->element_value, element_value);
        } else {
            // Extract element value
            end -= 2;
            while(is_whitespace(*end)) {
                end--;
            }
            end++;
            while(start < end) {
                element_value[i++] = *start++;
            }
            element_value[i] = '\0';

            strcpy(current_tag->element_value, element_value);
        }

        // Move start pointer to after closing tag
        start = end + 1;
    }

    return root_tag;
}

// Function to print tag tree
void print_tag_tree(XMLTag *tag, int depth) {
    if(tag == NULL) {
        return;
    }

    // Print tag name
    for(int i = 0; i < depth; i++) {
        putchar(' ');
    }
    printf("<%s>\n", tag->tag_name);

    // Print element value
    for(int i = 0; i < depth + 1; i++) {
        putchar(' ');
    }
    printf("%s\n", tag->element_value);

    // Print child tags
    for(int i = 0; i < MAX_ELEMENT_LENGTH; i++) {
        if(tag->child_tags[i] != NULL) {
            print_tag_tree(tag->child_tags[i], depth + 2);
        }
    }

    // Print closing tag
    for(int i = 0; i < depth; i++) {
        putchar(' ');
    }
    printf("</%s>\n", tag->tag_name);
}

int main() {
    char *xml_data = "<root>"
                     "<person>"
                     "<name>John Smith</name>"
                     "<age>30</age>"
                     "<address>"
                     "<street>Main St</street>"
                     "<city>New York</city>"
                     "</address>"
                     "</person>"
                     "<country>"
                     "<name>USA</name>"
                     "<population>300 million</population>"
                     "</country>"
                     "</root>";

    XMLTag *tag_tree = parse_xml(xml_data);

    print_tag_tree(tag_tree, 0);

    return 0;
}