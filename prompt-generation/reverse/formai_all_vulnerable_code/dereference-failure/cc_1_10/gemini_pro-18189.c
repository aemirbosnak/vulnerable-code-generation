//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct html_element {
    char *name;
    char *content;
    struct html_element *next;
};

struct html_document {
    struct html_element *head;
    struct html_element *body;
};

struct html_element *create_element(char *name, char *content) {
    struct html_element *element = malloc(sizeof(struct html_element));
    element->name = strdup(name);
    element->content = strdup(content);
    element->next = NULL;
    return element;
}

void add_element(struct html_document *document, struct html_element *element) {
    if (document->head == NULL) {
        document->head = element;
        document->body = element;
    } else {
        document->body->next = element;
        document->body = element;
    }
}

char *beautify_html(struct html_document *document) {
    char *html = malloc(1024);
    int indent = 0;
    struct html_element *element = document->head;
    while (element != NULL) {
        sprintf(html, "%s%*s<%s>", html, indent, "", element->name);
        if (element->content != NULL) {
            sprintf(html, "%s%s</%s>", html, element->content, element->name);
        }
        indent++;
        element = element->next;
    }
    return html;
}

int main() {
    struct html_document document;
    document.head = NULL;
    document.body = NULL;
    add_element(&document, create_element("html", NULL));
    add_element(&document, create_element("head", NULL));
    add_element(&document, create_element("title", "My Website"));
    add_element(&document, create_element("body", NULL));
    add_element(&document, create_element("h1", "Welcome to my website"));
    add_element(&document, create_element("p", "This is my website"));
    char *html = beautify_html(&document);
    printf("%s", html);
    return 0;
}