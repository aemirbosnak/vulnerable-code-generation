//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Define the structure for holding each element of the XML document
struct xml_element {
    char tag[MAX_SIZE];
    char value[MAX_SIZE];
    struct xml_element* child_start;
    struct xml_element* sibling_next;
};

// Recursive function to parse the XML document
struct xml_element* parse_xml(const char* xml_string) {
    struct xml_element* root = NULL;
    struct xml_element* current_element = NULL;
    struct xml_element* parent_stack[MAX_SIZE];
    int stack_pointer = -1;
    int parsing_tag = 0;
    int parsing_value = 0;
    const char* p = xml_string;
    char tag_buffer[MAX_SIZE];
    char value_buffer[MAX_SIZE];
    int buffer_pointer = 0;

    while (*p != '\0') {
        if (*p == '<') {
            parsing_tag = 1;
            parsing_value = 0;
            buffer_pointer = 0;
            p++;
        }
        else if (*p == '>') {
            parsing_tag = 0;
            parsing_value = 1;
            value_buffer[buffer_pointer] = '\0';
            buffer_pointer = 0;
            if (*(p-1) == '/') {
                // This is a self-closing tag
                if (stack_pointer >= 0) {
                    current_element = parent_stack[stack_pointer];
                }
                p++;
                continue;
            }
            if (*(p-1) == '?') {
                // This is an XML header, just skip over it
                while (*p != '>') {
                    p++;
                }
                p++;
                continue;
            }
            if (*(p-1) == '!') {
                // This is a comment or a CDATA section, just skip over it
                while (*p != '>') {
                    p++;
                }
                p++;
                continue;
            }
            // This is the end of a tag, either opening or closing
            tag_buffer[buffer_pointer] = '\0';
            buffer_pointer = 0;
            if (*tag_buffer == '/') {
                // This is a closing tag
                stack_pointer--;
                p++;
                continue;
            }
            // This is an opening tag 
            struct xml_element* new_element = (struct xml_element*)malloc(sizeof(struct xml_element));
            strcpy(new_element->tag, tag_buffer);
            strcpy(new_element->value, value_buffer);
            new_element->child_start = NULL;
            new_element->sibling_next = NULL;
            if (root == NULL) {
                root = new_element;
                current_element = new_element;
            }
            else {
                if (stack_pointer >= 0) {
                    struct xml_element* parent_element = parent_stack[stack_pointer];
                    if (parent_element->child_start == NULL) {
                        parent_element->child_start = new_element;
                    }
                    else {
                        struct xml_element* sibling_element = parent_element->child_start;
                        while (sibling_element->sibling_next != NULL) {
                            sibling_element = sibling_element->sibling_next;
                        }
                        sibling_element->sibling_next = new_element;
                    }
                }
                else {
                    if (current_element->child_start == NULL) {
                        current_element->child_start = new_element;
                    }
                    else {
                        struct xml_element* sibling_element = current_element->child_start;
                        while (sibling_element->sibling_next != NULL) {
                            sibling_element = sibling_element->sibling_next;
                        }
                        sibling_element->sibling_next = new_element;
                    }
                }
                current_element = new_element;
            }
            parent_stack[++stack_pointer] = current_element;
            p++;
        }
        else if (parsing_tag) {
            tag_buffer[buffer_pointer++] = *p++;
        }
        else if (parsing_value) {
            value_buffer[buffer_pointer++] = *p++;
        }
        else {
            p++;
        }
    }
    return root;
}

// Recursive function to print the XML document in a readable format
void print_xml(struct xml_element* element, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
    printf("<%s>%s\n", element->tag, element->value);
    struct xml_element* child_element = element->child_start;
    while (child_element != NULL) {
        print_xml(child_element, indent_level + 1);
        child_element = child_element->sibling_next;
    }
    for (int i = 0; i < indent_level; i++) {
        printf("  ");
    }
    printf("</%s>\n", element->tag);
}

int main() {
    const char* xml_string = "<people><person><name>John</name><age>25</age></person><person><name>Jane</name><age>30</age></person></people>";

    struct xml_element* root = parse_xml(xml_string);
    print_xml(root, 0);

    return 0;
}