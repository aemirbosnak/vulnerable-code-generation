//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XML_ELEMENTS 100
#define MAX_LENGTH 512

typedef struct XmlElement {
    char tag[MAX_LENGTH];
    char content[MAX_LENGTH];
    struct XmlElement *children[MAX_XML_ELEMENTS];
    int child_count;
} XmlElement;

XmlElement* create_element(const char *tag) {
    XmlElement *element = (XmlElement *)malloc(sizeof(XmlElement));
    strncpy(element->tag, tag, MAX_LENGTH);
    element->tag[MAX_LENGTH - 1] = '\0';
    element->content[0] = '\0';
    element->child_count = 0;
    return element;
}

void add_child(XmlElement *parent, XmlElement *child) {
    if (parent->child_count < MAX_XML_ELEMENTS) {
        parent->children[parent->child_count++] = child;
    } else {
        printf("Error: Maximum child elements exceeded for %s\n", parent->tag);
    }
}

void parse_xml(const char *xml, XmlElement *root) {
    const char *current = xml;
    char tag[MAX_LENGTH];
    char content[MAX_LENGTH];
    
    while (*current) {
        if (*current == '<') {
            // Start of a tag
            const char *tag_start = current + 1;
            const char *tag_end = strchr(tag_start, '>');
            if (!tag_end) break; // Malformed XML
            
            size_t tag_length = tag_end - tag_start;
            strncpy(tag, tag_start, tag_length);
            tag[tag_length] = '\0';

            if (tag[0] != '/') { // Not a closing tag
                XmlElement *new_elem = create_element(tag);
                if (root) {
                    add_child(root, new_elem);
                }
                root = new_elem;
            } else {
                // Closing tag
                if (root) {
                    root->content[0] = '\0'; // Reset content before next iteration
                    strcpy(root->content, current + 1); // For demonstration purposes, storing closing tag
                }
            }
            current = tag_end + 1; // Move past '>'
        } else {
            // This is content if there's no tag
            const char *text_end = strchr(current, '<');
            if (!text_end) break;

            size_t text_length = text_end - current;
            if (root) {
                strncat(root->content, current, text_length);
                root->content[text_length + strlen(root->content)] = '\0';
            }
            current = text_end;
        }
    }
}

void print_element(XmlElement *element, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  "); // Indentation
    }
    printf("<%s>%s\n", element->tag, element->content);

    for (int i = 0; i < element->child_count; i++) {
        print_element(element->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("  "); // Indentation
    }
    printf("</%s>\n", element->tag);
}

void free_element(XmlElement *element) {
    if (!element) return;
    
    for (int i = 0; i < element->child_count; i++) {
        free_element(element->children[i]);
    }
    free(element);
}

int main() {
    const char *xml_sample = "<root><child1>Content1</child1><child2>Content2</child2></root>";
    
    XmlElement *root = create_element("root");
    parse_xml(xml_sample, root);
    
    printf("Parsed XML Structure:\n");
    print_element(root, 0);

    free_element(root);
    
    return 0;
}