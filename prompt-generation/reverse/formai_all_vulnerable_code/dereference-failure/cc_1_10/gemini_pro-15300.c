//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Default tab size
#define TAB_SIZE 4

// Structure to represent a single HTML tag
typedef struct html_tag {
    char *name;
    struct html_tag *parent;
    struct html_tag *first_child;
    struct html_tag *next_sibling;
    char *attributes;
    char *content;
} html_tag;

// Structure to represent the entire HTML document
typedef struct html_document {
    struct html_tag *root_tag;
    char *content;
} html_document;

// Function to create a new HTML tag
html_tag *html_tag_create(const char *name) {
    html_tag *tag = malloc(sizeof(html_tag));
    tag->name = strdup(name);
    tag->parent = NULL;
    tag->first_child = NULL;
    tag->next_sibling = NULL;
    tag->attributes = NULL;
    tag->content = NULL;
    return tag;
}

// Function to free an HTML tag
void html_tag_free(html_tag *tag) {
    free(tag->name);
    free(tag->attributes);
    free(tag->content);
    free(tag);
}

// Function to create a new HTML document
html_document *html_document_create() {
    html_document *document = malloc(sizeof(html_document));
    document->root_tag = NULL;
    document->content = NULL;
    return document;
}

// Function to free an HTML document
void html_document_free(html_document *document) {
    html_tag *tag = document->root_tag;
    while (tag) {
        html_tag *next = tag->next_sibling;
        html_tag_free(tag);
        tag = next;
    }
    free(document->content);
    free(document);
}

// Function to add a new tag to the end of the document
void html_document_add_tag(html_document *document, html_tag *tag) {
    if (!document->root_tag) {
        document->root_tag = tag;
    } else {
        html_tag *last_tag = document->root_tag;
        while (last_tag->next_sibling) {
            last_tag = last_tag->next_sibling;
        }
        last_tag->next_sibling = tag;
    }
}

// Function to add a new child tag to the end of a parent tag
void html_tag_add_child(html_tag *parent, html_tag *child) {
    if (!parent->first_child) {
        parent->first_child = child;
    } else {
        html_tag *last_child = parent->first_child;
        while (last_child->next_sibling) {
            last_child = last_child->next_sibling;
        }
        last_child->next_sibling = child;
    }
}

// Function to set the attributes of a tag
void html_tag_set_attributes(html_tag *tag, const char *attributes) {
    tag->attributes = strdup(attributes);
}

// Function to set the content of a tag
void html_tag_set_content(html_tag *tag, const char *content) {
    tag->content = strdup(content);
}

// Function to print the HTML document to a file
void html_document_print(html_document *document, FILE *file) {
    html_tag *tag = document->root_tag;
    while (tag) {
        fprintf(file, "<%s%s>", tag->name, tag->attributes ? " " : "");
        if (tag->content) {
            fprintf(file, "%s", tag->content);
        } else {
            fprintf(file, "\n");
            html_tag *child = tag->first_child;
            while (child) {
                html_document_print(child, file);
                child = child->next_sibling;
            }
            fprintf(file, "</%s>\n", tag->name);
        }
        tag = tag->next_sibling;
    }
}

// Main function
int main() {
    // Create a new HTML document
    html_document *document = html_document_create();

    // Create the root tag
    html_tag *root_tag = html_tag_create("html");

    // Add the root tag to the document
    html_document_add_tag(document, root_tag);

    // Create the head tag
    html_tag *head_tag = html_tag_create("head");

    // Add the head tag to the root tag
    html_tag_add_child(root_tag, head_tag);

    // Create the title tag
    html_tag *title_tag = html_tag_create("title");

    // Set the title of the document
    html_tag_set_content(title_tag, "My HTML Document");

    // Add the title tag to the head tag
    html_tag_add_child(head_tag, title_tag);

    // Create the body tag
    html_tag *body_tag = html_tag_create("body");

    // Add the body tag to the root tag
    html_tag_add_child(root_tag, body_tag);

    // Create the h1 tag
    html_tag *h1_tag = html_tag_create("h1");

    // Set the text of the h1 tag
    html_tag_set_content(h1_tag, "My Heading");

    // Add the h1 tag to the body tag
    html_tag_add_child(body_tag, h1_tag);

    // Create the p tag
    html_tag *p_tag = html_tag_create("p");

    // Set the text of the p tag
    html_tag_set_content(p_tag, "My Paragraph");

    // Add the p tag to the body tag
    html_tag_add_child(body_tag, p_tag);

    // Print the HTML document to a file
    FILE *file = fopen("output.html", "w");
    html_document_print(document, file);
    fclose(file);

    // Free the HTML document
    html_document_free(document);

    return 0;
}