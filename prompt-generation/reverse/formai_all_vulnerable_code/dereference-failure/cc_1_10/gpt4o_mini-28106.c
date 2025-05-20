//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *tag;
    char *content;
    struct Element **children;
    int child_count;
} Element;

// Function to create a new XML element
Element* create_element(const char *tag, const char *content) {
    Element *el = malloc(sizeof(Element));
    el->tag = strdup(tag);
    el->content = strdup(content);
    el->child_count = 0;
    el->children = NULL;
    return el;
}

// Function to add a child element to a parent element
void add_child(Element *parent, Element *child) {
    parent->child_count++;
    parent->children = realloc(parent->children, sizeof(Element*) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

// Function to free an XML element
void free_element(Element *el) {
    if (el) {
        free(el->tag);
        free(el->content);
        for (int i = 0; i < el->child_count; i++) {
            free_element(el->children[i]);
        }
        free(el->children);
        free(el);
    }
}

// Function to parse a simple XML string
Element* parse_xml(const char *xml) {
    char *tag = NULL;
    char *content = NULL;
    int i = 0, j = 0;
    Element *root = NULL, *current = NULL;

    while (xml[i]) {
        if (xml[i] == '<') {
            j = 0;
            while (xml[i] && xml[i] != '>') {
                if (xml[i] == '/') { // Closing tag
                    i++;
                    break;
                }
                if (!tag) {
                    tag = malloc(256);
                    while (xml[i] && xml[i] != '>') {
                        tag[j++] = xml[i++];
                    }
                    tag[j] = '\0';
                }
                i++;
            }
            if (xml[i] == '>') i++; // Skip '>'
            if (!root) {
                root = create_element(tag, "");
                current = root;
            } else {
                Element *new_el = create_element(tag, content ? content : "");
                add_child(current, new_el);
                current = new_el;
            }
            free(tag);
            tag = NULL;
            content = NULL;
            j = 0;
        } else {
            j = 0;
            while (xml[i] && xml[i] != '<') {
                if (!content) {
                    content = malloc(256);
                }
                content[j++] = xml[i++];
            }
            if (content) {
                content[j] = '\0';
                current->content = strdup(content);
                free(content);
                content = NULL;
            }
        }
    }
    return root;
}

// Function to print the XML tree
void print_xml(Element *el, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s>\n", el->tag);
    if (*el->content) {
        for (int i = 0; i < level + 1; i++) printf("  ");
        printf("%s\n", el->content);
    }
    for (int i = 0; i < el->child_count; i++) {
        print_xml(el->children[i], level + 1);
    }
    for (int i = 0; i < level; i++) printf("  ");
    printf("</%s>\n", el->tag);
}

int main() {
    const char *xml_data = "<root><child1>Hello</child1><child2><subchild>World</subchild></child2></root>";

    Element *xml_tree = parse_xml(xml_data);
    
    printf("Parsed XML Structure:\n");
    print_xml(xml_tree, 0);
    
    free_element(xml_tree);
    return 0;
}