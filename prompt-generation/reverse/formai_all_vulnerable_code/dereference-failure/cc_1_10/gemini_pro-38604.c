//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a node in the TeX tree
struct tex_node {
    char *content;
    struct tex_node *next;
    struct tex_node *prev;
};

// A structure to represent a TeX document
struct tex_document {
    struct tex_node *head;
    struct tex_node *tail;
};

// Create a new TeX document
struct tex_document *new_tex_document() {
    struct tex_document *doc = malloc(sizeof(struct tex_document));
    doc->head = NULL;
    doc->tail = NULL;
    return doc;
}

// Add a new node to the end of the TeX document
void add_tex_node(struct tex_document *doc, char *content) {
    struct tex_node *new_node = malloc(sizeof(struct tex_node));
    new_node->content = strdup(content);
    new_node->next = NULL;
    new_node->prev = doc->tail;
    if (doc->tail != NULL) {
        doc->tail->next = new_node;
    } else {
        doc->head = new_node;
    }
    doc->tail = new_node;
}

// Print the TeX document to a file
void print_tex_document(struct tex_document *doc, FILE *file) {
    struct tex_node *node = doc->head;
    while (node != NULL) {
        fprintf(file, "%s", node->content);
        node = node->next;
    }
}

// Free the memory used by the TeX document
void free_tex_document(struct tex_document *doc) {
    struct tex_node *node = doc->head;
    while (node != NULL) {
        struct tex_node *next_node = node->next;
        free(node->content);
        free(node);
        node = next_node;
    }
    free(doc);
}

// The main function
int main() {
    // Create a new TeX document
    struct tex_document *doc = new_tex_document();

    // Add some nodes to the document
    add_tex_node(doc, "\\documentclass{article}");
    add_tex_node(doc, "\\begin{document}");
    add_tex_node(doc, "Hello, world!");
    add_tex_node(doc, "\\end{document}");

    // Print the document to a file
    FILE *file = fopen("output.tex", "w");
    print_tex_document(doc, file);
    fclose(file);

    // Free the memory used by the document
    free_tex_document(doc);

    return 0;
}