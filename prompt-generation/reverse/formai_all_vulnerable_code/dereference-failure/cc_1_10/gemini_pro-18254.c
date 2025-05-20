//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

struct html_element {
    char *name;
    char *attr;
    char *content;
    struct html_element *next;
};

struct html_document {
    char *doctype;
    struct html_element *head;
    struct html_element *body;
};

struct html_element *html_element_new(const char *name, const char *attr, const char *content) {
    struct html_element *element = malloc(sizeof(struct html_element));
    element->name = malloc(strlen(name) + 1);
    strcpy(element->name, name);
    element->attr = malloc(strlen(attr) + 1);
    strcpy(element->attr, attr);
    element->content = malloc(strlen(content) + 1);
    strcpy(element->content, content);
    element->next = NULL;
    return element;
}

void html_element_free(struct html_element *element) {
    free(element->name);
    free(element->attr);
    free(element->content);
    free(element);
}

struct html_document *html_document_new(const char *doctype) {
    struct html_document *document = malloc(sizeof(struct html_document));
    document->doctype = malloc(strlen(doctype) + 1);
    strcpy(document->doctype, doctype);
    document->head = NULL;
    document->body = NULL;
    return document;
}

void html_document_free(struct html_document *document) {
    free(document->doctype);
    struct html_element *element = document->head;
    while (element) {
        struct html_element *next = element->next;
        html_element_free(element);
        element = next;
    }
    element = document->body;
    while (element) {
        struct html_element *next = element->next;
        html_element_free(element);
        element = next;
    }
    free(document);
}

void html_document_add_head(struct html_document *document, struct html_element *element) {
    element->next = document->head;
    document->head = element;
}

void html_document_add_body(struct html_document *document, struct html_element *element) {
    element->next = document->body;
    document->body = element;
}

char *html_document_to_string(struct html_document *document) {
    char *buffer = malloc(MAX_LINE_LEN);
    sprintf(buffer, "<!DOCTYPE %s>\n", document->doctype);
    strcat(buffer, "<html>\n");
    struct html_element *element = document->head;
    while (element) {
        sprintf(buffer, "%s\t<%s %s>%s</%s>\n", buffer, element->name, element->attr, element->content, element->name);
        element = element->next;
    }
    strcat(buffer, "</html>\n");
    return buffer;
}

int main() {
    struct html_document *document = html_document_new("html");
    html_document_add_head(document, html_element_new("head", "", ""));
    html_document_add_body(document, html_element_new("body", "", ""));
    html_document_add_body(document, html_element_new("h1", "", "Hello, world!"));
    char *html = html_document_to_string(document);
    printf("%s", html);
    free(html);
    html_document_free(document);
    return 0;
}