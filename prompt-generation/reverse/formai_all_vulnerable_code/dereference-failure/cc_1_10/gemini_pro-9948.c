//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct html_tag {
    char *name;
    struct html_tag *parent;
    struct html_tag *child;
    struct html_tag *next;
    struct html_tag *prev;
    int open;
    int closed;
};

struct html_document {
    struct html_tag *root;
    struct html_tag *current;
};

struct html_tag *create_html_tag(char *name) {
    struct html_tag *tag = malloc(sizeof(struct html_tag));
    tag->name = name;
    tag->parent = NULL;
    tag->child = NULL;
    tag->next = NULL;
    tag->prev = NULL;
    tag->open = 0;
    tag->closed = 0;
    return tag;
}

struct html_document *create_html_document() {
    struct html_document *document = malloc(sizeof(struct html_document));
    document->root = NULL;
    document->current = NULL;
    return document;
}

void add_html_tag(struct html_document *document, struct html_tag *tag) {
    if (document->root == NULL) {
        document->root = tag;
        document->current = tag;
    } else {
        document->current->next = tag;
        tag->prev = document->current;
        document->current = tag;
    }
}

void print_html_tag(struct html_tag *tag) {
    printf("<%s>", tag->name);
    if (tag->open) {
        printf("\n");
    } else {
        printf(" /");
    }
}

void print_html_document(struct html_document *document) {
    struct html_tag *tag = document->root;
    while (tag != NULL) {
        print_html_tag(tag);
        tag = tag->next;
    }
    printf("\n");
}

void beautify_html(struct html_document *document) {
    struct html_tag *tag = document->root;
    int indent = 0;
    while (tag != NULL) {
        for (int i = 0; i < indent; i++) {
            printf("    ");
        }
        print_html_tag(tag);
        if (tag->open) {
            indent++;
            tag = tag->child;
        } else {
            indent--;
            tag = tag->next;
        }
    }
    printf("\n");
}

int main() {
    struct html_document *document = create_html_document();
    struct html_tag *html = create_html_tag("html");
    struct html_tag *head = create_html_tag("head");
    struct html_tag *title = create_html_tag("title");
    struct html_tag *body = create_html_tag("body");
    struct html_tag *p = create_html_tag("p");
    add_html_tag(document, html);
    add_html_tag(document, head);
    add_html_tag(document, title);
    add_html_tag(document, body);
    add_html_tag(document, p);
    print_html_document(document);
    beautify_html(document);
    return 0;
}