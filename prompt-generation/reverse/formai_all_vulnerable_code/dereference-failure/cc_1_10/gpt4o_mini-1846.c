//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_BUFFER_SIZE 1024

typedef struct Element {
    char tag[MAX_TAG_NAME];
    struct Element *next;
    struct Element *child;
} Element;

Element* create_element(const char *name) {
    Element *new_element = (Element *)malloc(sizeof(Element));
    if (new_element == NULL) {
        perror("Failed to allocate memory for new element");
        exit(EXIT_FAILURE);
    }
    strncpy(new_element->tag, name, MAX_TAG_NAME - 1);
    new_element->tag[MAX_TAG_NAME - 1] = '\0';   // Ensure null termination
    new_element->next = NULL;
    new_element->child = NULL;
    return new_element;
}

void append_child(Element *parent, Element *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Element *current = parent->child;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

void free_element(Element *element) {
    if (element) {
        free_element(element->child);
        free_element(element->next);
        free(element);
    }
}

void print_xml(Element *element, int depth) {
    if (element == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");  // Indentation for pretty printing
    }

    printf("<%s>\n", element->tag);
    print_xml(element->child, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", element->tag);

    print_xml(element->next, depth);
}

Element* parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    Element *root = NULL, *current = NULL;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char tag[MAX_TAG_NAME];
        if (sscanf(buffer, "<%[^/>]", tag) == 1) {
            Element *new_element = create_element(tag);
            if (root == NULL) {
                root = new_element; // First element becomes root
            } else {
                append_child(current, new_element);
            }
            current = new_element; // Move current pointer to the latest element
        } 
        else if (sscanf(buffer, "</%[^>]", tag) == 1) {
            if (current != NULL) {
                current = current->next; // Move back to parent
            }
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Element *xml_tree = parse_xml(argv[1]);
    
    if (xml_tree) {
        printf("Parsed XML:\n");
        print_xml(xml_tree, 0);
        free_element(xml_tree);
    } else {
        fprintf(stderr, "Failed to parse XML file: %s\n", argv[1]);
    }

    return EXIT_SUCCESS;
}