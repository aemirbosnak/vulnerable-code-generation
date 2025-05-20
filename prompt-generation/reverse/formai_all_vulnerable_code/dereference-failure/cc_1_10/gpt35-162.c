//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the data within an XML tag
typedef struct {
    char* name;
    char* value;
} xml_tag_data;

// Define a structure for a linked list node containing XML tag data
typedef struct node {
    xml_tag_data data;
    struct node* next;
} xml_tag_node;

// Define a function to print an error message and exit
void print_error(const char* err_message) {
    printf("Error: %s\n", err_message);
    exit(1);
}

// Define a function to parse the opening tag (e.g. <tagname attr="value">)
xml_tag_node* parse_open_tag(const char* tag_string) {
    xml_tag_node* tag_node = malloc(sizeof(xml_tag_node));
    tag_node->next = NULL;

    // Find the tag name
    char* tag_name_start = strchr(tag_string, '<') + 1;
    char* tag_name_end = strpbrk(tag_name_start, " \t\n/>");
    if (tag_name_end == NULL) print_error("Invalid tag\n");

    tag_node->data.name = malloc((tag_name_end - tag_name_start + 1) * sizeof(char));
    strncpy(tag_node->data.name, tag_name_start, tag_name_end - tag_name_start);
    tag_node->data.name[tag_name_end - tag_name_start] = '\0';

    // Parse any attributes
    char* attr_name_start = tag_name_end;
    while (*attr_name_start != '>') {
        attr_name_start++;
        if (*attr_name_start == '/') break;
        if (*attr_name_start == '>') print_error("Invalid tag\n");

        char* attr_name_end = strpbrk(attr_name_start, "= \t\n/>");
        if (attr_name_end == NULL) print_error("Invalid attribute\n");

        xml_tag_node* new_attr_node = malloc(sizeof(xml_tag_node));
        new_attr_node->next = NULL;

        new_attr_node->data.name = malloc((attr_name_end - attr_name_start + 1) * sizeof(char));
        strncpy(new_attr_node->data.name, attr_name_start, attr_name_end - attr_name_start);
        new_attr_node->data.name[attr_name_end - attr_name_start] = '\0';

        attr_name_start = attr_name_end;
        while (*attr_name_start != '"' && *attr_name_start != '\'') attr_name_start++;
        attr_name_start++;

        char* attr_val_end = strchr(attr_name_start, *attr_name_start);
        if (attr_val_end == NULL) print_error("Invalid attribute value\n");

        new_attr_node->data.value = malloc((attr_val_end - attr_name_start + 1) * sizeof(char));
        strncpy(new_attr_node->data.value, attr_name_start, attr_val_end - attr_name_start);
        new_attr_node->data.value[attr_val_end - attr_name_start] = '\0';

        // Add attribute node to linked list
        new_attr_node->next = tag_node->next;
        tag_node->next = new_attr_node;
    }

    return tag_node;
}

// Define a function to parse a closing tag (e.g. </tagname>)
xml_tag_node* parse_close_tag(const char* tag_string, const char* expected_tag_name) {
    xml_tag_node* tag_node = malloc(sizeof(xml_tag_node));
    tag_node->next = NULL;

    // Find the tag name
    char* tag_name_start = strchr(tag_string, '<') + 2;
    char* tag_name_end = strpbrk(tag_name_start, " \t\n/>");
    if (tag_name_end == NULL) print_error("Invalid tag\n");

    char tag_name[tag_name_end - tag_name_start + 1];
    strncpy(tag_name, tag_name_start, tag_name_end - tag_name_start);
    tag_name[tag_name_end - tag_name_start] = '\0';

    if (strcmp(tag_name, expected_tag_name) != 0) print_error("Mismatched closing tag\n");

    // Set tag data with name but no value
    tag_node->data.name = malloc((tag_name_end - tag_name_start + 1) * sizeof(char));
    strncpy(tag_node->data.name, tag_name_start, tag_name_end - tag_name_start);
    tag_node->data.name[tag_name_end - tag_name_start] = '\0';

    return tag_node;
}

// Define a function to parse tag contents (e.g. text or mixed content)
xml_tag_node* parse_contents(const char* contents_string) {
    // Set tag data with name "contents" and given value
    xml_tag_node* tag_node = malloc(sizeof(xml_tag_node));
    tag_node->next = NULL;

    tag_node->data.name = malloc(strlen("contents") * sizeof(char));
    strcpy(tag_node->data.name, "contents");

    tag_node->data.value = malloc((strlen(contents_string) + 1) * sizeof(char));
    strcpy(tag_node->data.value, contents_string);

    return tag_node;
}

// Define a function to build a linked list of XML tag data nodes
xml_tag_node* build_xml_tree(const char* xml_string) {
    xml_tag_node* root_node = NULL;
    xml_tag_node* current_node = NULL;

    const char* cursor = xml_string;
    while (*cursor != '\0') {
        if (*cursor == '<') {
            if (*(cursor + 1) == '/') {
                // Parse a closing tag
                char* tag_end = strchr(cursor, '>');
                if (tag_end == NULL) print_error("Invalid tag\n");

                xml_tag_node* closing_tag_node = parse_close_tag(cursor, current_node->data.name);

                if (root_node == NULL) {
                    root_node = closing_tag_node;
                    current_node = NULL;
                } else {
                    current_node = current_node->next;
                }

                cursor = tag_end + 1;
            } else {
                // Parse an opening tag
                char* tag_end = strpbrk(cursor, "/>");
                if (tag_end == NULL) print_error("Invalid tag\n");

                xml_tag_node* opening_tag_node = parse_open_tag(cursor);

                // Determine the node's parent and add it to linked list
                if (root_node == NULL) {
                    root_node = opening_tag_node;
                    current_node = root_node;
                } else {
                    opening_tag_node->next = current_node->next;
                    current_node->next = opening_tag_node;
                    current_node = opening_tag_node;
                }

                // If this tag is self-closing, no content follows it
                if (*tag_end == '/') {
                    cursor = tag_end + 2;
                } else {
                    cursor = tag_end + 1;

                    // Parse tag contents (text or mixed)
                    char* contents_end = strstr(cursor, "</");
                    if (contents_end == NULL) print_error("Invalid contents\n");

                    xml_tag_node* contents_node = parse_contents(cursor);
                    contents_node->next = current_node->next;
                    current_node->next = contents_node;

                    current_node = contents_node;

                    cursor = contents_end;
                }
            }
        } else {
            // Ignore whitespace outside of tags
            if (*cursor != ' ' && *cursor != '\t' && *cursor != '\n') print_error("Invalid character\n");
            cursor++;
        }
    }

    return root_node;
}

// Define a function to print out the XML tree for debugging
void print_xml_tree(xml_tag_node* tag_node, int level) {
    for (int i = 0; i < level; i++) printf("\t");

    printf("<%s", tag_node->data.name);

    xml_tag_node* current_attr = tag_node->next;
    while (current_attr != NULL) {
        printf(" %s=\"%s\"", current_attr->data.name, current_attr->data.value);
        current_attr = current_attr->next;
    }

    if (tag_node->data.value != NULL) {
        printf(">%s", tag_node->data.value);
    } else {
        printf(">\n");

        xml_tag_node* current_child = tag_node->next;
        while (current_child != NULL && current_child->data.value == NULL) {
            print_xml_tree(current_child, level + 1);
            current_child = current_child->next;
        }

        if (current_child != NULL) {
            for (int i = 0; i < level + 1; i++) printf("\t");
            printf("%s", current_child->data.value);

            current_child = current_child->next;
            while (current_child != NULL) {
                for (int i = 0; i < level + 1; i++) printf("\t");
                printf("%s\n", current_child->data.value);
                current_child = current_child->next;
            }
        }
    }

    printf("</%s>\n", tag_node->data.name);
}

int main() {
    const char* test_xml = "<root><element1 attr1=\"value1\">Text1<child></child>Text2</element1><element2>Text3\nText4</element2></root>";

    xml_tag_node* root = build_xml_tree(test_xml);
    print_xml_tree(root, 0);

    return 0;
}