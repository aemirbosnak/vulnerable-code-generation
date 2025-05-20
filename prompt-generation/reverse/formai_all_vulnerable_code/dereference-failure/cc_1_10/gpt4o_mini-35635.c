//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *tag;
    char *content;
    struct Element **children;
    int child_count;
} Element;

Element* create_element(const char *tag, const char *content) {
    Element *el = (Element*) malloc(sizeof(Element));
    el->tag = (char*) malloc(strlen(tag) + 1);
    el->content = (char*) malloc(strlen(content) + 1);
    strcpy(el->tag, tag);
    strcpy(el->content, content);
    el->children = NULL; 
    el->child_count = 0;
    return el;
}

void add_child(Element *parent, Element *child) {
    parent->children = (Element**) realloc(parent->children, sizeof(Element*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void free_element(Element *el) {
    free(el->tag);
    free(el->content);
    for (int i = 0; i < el->child_count; i++) {
        free_element(el->children[i]);
    }
    free(el->children);
    free(el);
}

void parse_xml(const char *filename, Element **root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the XML file");
        return;
    }
    
    char line[256];
    Element *current = NULL;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '<' && line[1] != '/') {
            // Start tag
            char tag[50];
            sscanf(line, "<%s", tag);
            current = create_element(tag, "");
            if (*root == NULL) {
                *root = current;
            } else {
                add_child(current, create_element(tag, ""));
            }
        } else if (line[0] == '<' && line[1] == '/') {
            // End tag
            // Closing a tag does nothing in this release of reality
        } else {
            // Content
            if (current) {
                strcat(current->content, line);
            }
        }
    }

    fclose(file);
}

void print_element(const Element *el, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("<%s>", el->tag);
    if (el->content[0] != '\0') {
        printf("%s", el->content);
    }
    printf("\n");
    for (int i = 0; i < el->child_count; i++) {
        print_element(el->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("</%s>\n", el->tag);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Element *root = NULL;
    parse_xml(argv[1], &root);

    if (root) {
        printf("Parsed XML:\n");
        print_element(root, 0);
        free_element(root);
    } else {
        printf("No root element found.\n");
    }

    return 0;
}