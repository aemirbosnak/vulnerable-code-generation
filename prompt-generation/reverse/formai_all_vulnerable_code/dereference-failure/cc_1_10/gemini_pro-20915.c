//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom struct to hold HTML tags and their attributes
typedef struct html_tag {
    char *name;
    char **attributes;
    int num_attributes;
} html_tag_t;

// Function to create a new HTML tag
html_tag_t *create_html_tag(char *name) {
    html_tag_t *tag = malloc(sizeof(html_tag_t));
    tag->name = strdup(name);
    tag->attributes = NULL;
    tag->num_attributes = 0;
    return tag;
}

// Function to add an attribute to an HTML tag
void add_html_tag_attribute(html_tag_t *tag, char *name, char *value) {
    tag->attributes = realloc(tag->attributes, (tag->num_attributes + 1) * sizeof(char *));
    tag->attributes[tag->num_attributes] = malloc(strlen(name) + strlen(value) + 2);
    sprintf(tag->attributes[tag->num_attributes], "%s=\"%s\"", name, value);
    tag->num_attributes++;
}

// Function to print an HTML tag
void print_html_tag(html_tag_t *tag) {
    printf("<%s", tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        printf(" %s", tag->attributes[i]);
    }
    printf(">");
}

// Function to free an HTML tag
void free_html_tag(html_tag_t *tag) {
    free(tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        free(tag->attributes[i]);
    }
    free(tag->attributes);
    free(tag);
}

// Main function
int main() {
    // Create an HTML document
    html_tag_t *html = create_html_tag("html");
    html_tag_t *head = create_html_tag("head");
    html_tag_t *title = create_html_tag("title");
    add_html_tag_attribute(title, "lang", "en");
    html_tag_t *body = create_html_tag("body");
    html_tag_t *h1 = create_html_tag("h1");
    html_tag_t *p = create_html_tag("p");

    // Add the tags to the document
    add_html_tag_attribute(html, "lang", "en");
    add_html_tag_attribute(body, "class", "container");
    add_html_tag_attribute(h1, "id", "main-heading");
    add_html_tag_attribute(p, "style", "color: red;");

    // Print the document
    print_html_tag(html);
    print_html_tag(head);
    print_html_tag(title);
    printf("My Awesome Website");
    print_html_tag(head);
    print_html_tag(body);
    print_html_tag(h1);
    printf("Welcome to my website!");
    print_html_tag(h1);
    print_html_tag(p);
    printf("This is a paragraph of text.");
    print_html_tag(p);
    print_html_tag(body);
    print_html_tag(html);

    // Free the tags
    free_html_tag(html);
    free_html_tag(head);
    free_html_tag(title);
    free_html_tag(body);
    free_html_tag(h1);
    free_html_tag(p);

    return 0;
}