//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct html_element
{
    char *name;
    char *attributes;
    char *content;
    struct html_element *children;
    struct html_element *sibling;
};

struct html_beautifier
{
    int indent_level;
    int indent_size;
    FILE *output_file;
};

void html_beautifier_init(struct html_beautifier *beautifier, FILE *output_file, int indent_size)
{
    beautifier->indent_level = 0;
    beautifier->indent_size = indent_size;
    beautifier->output_file = output_file;
}

void html_beautifier_free(struct html_beautifier *beautifier)
{
    // Not implemented
}

void html_beautifier_indent(struct html_beautifier *beautifier)
{
    for (int i = 0; i < beautifier->indent_level; i++)
    {
        fprintf(beautifier->output_file, " ");
    }
}

void html_beautifier_write_element(struct html_beautifier *beautifier, struct html_element *element)
{
    html_beautifier_indent(beautifier);
    fprintf(beautifier->output_file, "<%s%s>", element->name, element->attributes ? element->attributes : "");

    if (element->content)
    {
        fprintf(beautifier->output_file, "%s", element->content);
    }

    if (element->children)
    {
        fprintf(beautifier->output_file, "\n");
        beautifier->indent_level += beautifier->indent_size;
        html_beautifier_write_element(beautifier, element->children);
        beautifier->indent_level -= beautifier->indent_size;
        html_beautifier_indent(beautifier);
    }

    fprintf(beautifier->output_file, "</%s>\n", element->name);
}

struct html_element *html_element_create(char *name, char *attributes, char *content)
{
    struct html_element *element = malloc(sizeof(struct html_element));
    element->name = name;
    element->attributes = attributes;
    element->content = content;
    element->children = NULL;
    element->sibling = NULL;

    return element;
}

void html_element_free(struct html_element *element)
{
    // Not implemented
}

void html_element_add_child(struct html_element *element, struct html_element *child)
{
    if (!element->children)
    {
        element->children = child;
    }
    else
    {
        struct html_element *last_child = element->children;
        while (last_child->sibling)
        {
            last_child = last_child->sibling;
        }
        last_child->sibling = child;
    }
}

int main()
{
    struct html_beautifier beautifier;
    html_beautifier_init(&beautifier, stdout, 4);

    struct html_element *html = html_element_create("html", NULL, NULL);
    struct html_element *head = html_element_create("head", NULL, NULL);
    struct html_element *title = html_element_create("title", NULL, "My Page");
    struct html_element *body = html_element_create("body", NULL, NULL);
    struct html_element *h1 = html_element_create("h1", NULL, "Hello, World!");
    struct html_element *p = html_element_create("p", NULL, "This is my page.");

    html_element_add_child(head, title);
    html_element_add_child(html, head);
    html_element_add_child(body, h1);
    html_element_add_child(body, p);
    html_element_add_child(html, body);

    html_beautifier_write_element(&beautifier, html);

    html_element_free(html);
    html_element_free(head);
    html_element_free(title);
    html_element_free(body);
    html_element_free(h1);
    html_element_free(p);

    html_beautifier_free(&beautifier);

    return 0;
}