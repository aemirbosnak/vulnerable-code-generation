//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the HTML tags
typedef struct html_tag {
    char *name;
    char *attributes;
    char *content;
    struct html_tag *next;
} html_tag;

// Function to create a new HTML tag
html_tag *create_tag(char *name, char *attributes, char *content) {
    html_tag *tag = (html_tag *)malloc(sizeof(html_tag));
    tag->name = strdup(name);
    tag->attributes = strdup(attributes);
    tag->content = strdup(content);
    tag->next = NULL;
    return tag;
}

// Function to add a new HTML tag to the end of the list
void add_tag(html_tag **head, html_tag *tag) {
    if (*head == NULL) {
        *head = tag;
    } else {
        html_tag *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = tag;
    }
}

// Function to print the HTML tags
void print_tags(html_tag *head) {
    html_tag *current = head;
    while (current != NULL) {
        printf("<%s %s>%s</%s>\n", current->name, current->attributes, current->content, current->name);
        current = current->next;
    }
}

// Function to free the memory allocated for the HTML tags
void free_tags(html_tag *head) {
    html_tag *current = head;
    while (current != NULL) {
        html_tag *next = current->next;
        free(current->name);
        free(current->attributes);
        free(current->content);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new HTML tag
    html_tag *head = create_tag("html", "", "");

    // Add a new HTML tag to the end of the list
    add_tag(&head, create_tag("head", "", ""));

    // Add a new HTML tag to the end of the list
    add_tag(&head, create_tag("title", "", "My Website"));

    // Add a new HTML tag to the end of the list
    add_tag(&head, create_tag("body", "", ""));

    // Add a new HTML tag to the end of the list
    add_tag(&head, create_tag("h1", "", "Welcome to My Website"));

    // Add a new HTML tag to the end of the list
    add_tag(&head, create_tag("p", "", "This is my website. It is still under construction."));

    // Print the HTML tags
    print_tags(head);

    // Free the memory allocated for the HTML tags
    free_tags(head);

    return 0;
}