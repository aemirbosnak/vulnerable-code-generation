//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *tag;
    char *value;
    struct Element **children;
    int child_count;
} Element;

// Function to create a new Element
Element *create_element(const char *tag, const char *value) {
    Element *el = malloc(sizeof(Element));
    el->tag = strdup(tag);
    el->value = value ? strdup(value) : NULL;
    el->children = NULL;
    el->child_count = 0;
    return el;
}

// Function to add a child to an Element
void add_child(Element *parent, Element *child) {
    parent->children = realloc(parent->children, sizeof(Element *) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

// Function to print an Element
void print_element(Element *el, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("<%s>", el->tag);
    if (el->value) {
        printf("%s", el->value);
    }
    printf("\n");
    for (int i = 0; i < el->child_count; i++) {
        print_element(el->children[i], indent + 1);
    }
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("</%s>\n", el->tag);
}

// Function to free memory of an Element
void free_element(Element *el) {
    free(el->tag);
    free(el->value);
    for (int i = 0; i < el->child_count; i++) {
        free_element(el->children[i]);
    }
    free(el->children);
    free(el);
}

// Simple XML parser function
Element *parse_xml(const char *xml) {
    Element *root = NULL;
    Element *current = NULL;
    char tag[256];
    char value[256];
    int tag_index = 0, value_index = 0;
    int parsing_value = 0;

    for (const char *p = xml; *p; p++) {
        if (*p == '<') {
            if (*(p + 1) == '/') { // End tag
                // Closing current tag
                tag[tag_index] = '\0';
                p += strlen(tag) + 2; // Skip the end tag
                if (current) {
                    current = NULL;  // Move back to parent
                }
            } else { // Start tag
                if (root == NULL) { // If this is the root element
                    tag_index = 0;
                    while (*(p + 1) != '>') {
                        tag[tag_index++] = *(++p);
                    }
                    tag[tag_index] = '\0';
                    root = create_element(tag, NULL);
                    current = root;
                } else {
                    tag_index = 0;
                    while (*(p + 1) != '>') {
                        tag[tag_index++] = *(++p);
                    }
                    tag[tag_index] = '\0';
                    Element *new_elem = create_element(tag, NULL);
                    add_child(current, new_elem);
                    current = new_elem; // Move into the new element
                }
            }
        } else if (*p != '>' && current) {
            // Collecting value
            parsing_value = 1;
            value[value_index++] = *p;
        } else if (parsing_value && *p == '>') {
            value[value_index] = '\0';
            if (current) {
                current->value = strdup(value);
            }
            value_index = 0;
            parsing_value = 0;
        }
    }
    return root;
}

int main() {
    const char *xml = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    Element *root = parse_xml(xml);
    print_element(root, 0);
    free_element(root);
    return 0;
}