//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct html_element {
    char *name;
    char *content;
    struct html_element *next;
};

struct html_document {
    struct html_element *root;
};

struct html_beautifier {
    FILE *input;
    FILE *output;
    int indent_level;
    char *indent_string;
};

void html_beautifier_init(struct html_beautifier *beautifier, FILE *input, FILE *output) {
    beautifier->input = input;
    beautifier->output = output;
    beautifier->indent_level = 0;
    beautifier->indent_string = "    ";
}

void html_beautifier_destroy(struct html_beautifier *beautifier) {
    fclose(beautifier->input);
    fclose(beautifier->output);
}

struct html_element *html_element_create(char *name, char *content) {
    struct html_element *element = malloc(sizeof(struct html_element));
    element->name = strdup(name);
    element->content = strdup(content);
    element->next = NULL;
    return element;
}

void html_element_destroy(struct html_element *element) {
    free(element->name);
    free(element->content);
    free(element);
}

struct html_document *html_document_create(struct html_element *root) {
    struct html_document *document = malloc(sizeof(struct html_document));
    document->root = root;
    return document;
}

void html_document_destroy(struct html_document *document) {
    struct html_element *element = document->root;
    while (element != NULL) {
        struct html_element *next = element->next;
        html_element_destroy(element);
        element = next;
    }
    free(document);
}

void html_beautifier_indent(struct html_beautifier *beautifier) {
    for (int i = 0; i < beautifier->indent_level; i++) {
        fprintf(beautifier->output, "%s", beautifier->indent_string);
    }
}

void html_beautifier_process_element(struct html_beautifier *beautifier, struct html_element *element) {
    html_beautifier_indent(beautifier);
    fprintf(beautifier->output, "<%s", element->name);
    if (element->content != NULL) {
        fprintf(beautifier->output, ">%s</%s>\n", element->content, element->name);
    } else {
        fprintf(beautifier->output, " />\n");
    }
    beautifier->indent_level++;
    struct html_element *child = element->next;
    while (child != NULL) {
        html_beautifier_process_element(beautifier, child);
        child = child->next;
    }
    beautifier->indent_level--;
}

void html_beautifier_process_document(struct html_beautifier *beautifier, struct html_document *document) {
    html_beautifier_process_element(beautifier, document->root);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.html output.html\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("fopen");
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("fopen");
        return 1;
    }
    struct html_beautifier beautifier;
    html_beautifier_init(&beautifier, input, output);
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
        char *name = strtok(line, "<>");
        if (name == NULL) {
            continue;
        }
        char *content = strtok(NULL, "<>");
        struct html_element *element = html_element_create(name, content);
        html_beautifier_process_element(&beautifier, element);
        html_element_destroy(element);
    }
    html_beautifier_destroy(&beautifier);
    fclose(input);
    fclose(output);
    return 0;
}