//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} attribute;

typedef struct {
    char *tag;
    attribute *attributes;
    int num_attributes;
    char **children;
    int num_children;
} node;

node *create_node(char *tag, attribute *attributes, int num_attributes, char **children, int num_children) {
    node *n = malloc(sizeof(node));
    n->tag = tag;
    n->attributes = attributes;
    n->num_attributes = num_attributes;
    n->children = children;
    n->num_children = num_children;
    return n;
}

void free_node(node *n) {
    free(n->tag);
    for (int i = 0; i < n->num_attributes; i++) {
        free(n->attributes[i].name);
        free(n->attributes[i].value);
    }
    free(n->attributes);
    for (int i = 0; i < n->num_children; i++) {
        free_node(n->children[i]);
    }
    free(n->children);
    free(n);
}

char *beautify_html(node *n, int indent) {
    char *s = malloc(1024);
    sprintf(s, "%*s<%s", indent, "", n->tag);
    for (int i = 0; i < n->num_attributes; i++) {
        sprintf(s, "%s %s=\"%s\"", s, n->attributes[i].name, n->attributes[i].value);
    }
    sprintf(s, "%s>", s);
    for (int i = 0; i < n->num_children; i++) {
        sprintf(s, "%s%s", s, beautify_html(n->children[i], indent + 2));
    }
    sprintf(s, "%s%*s</%s>", s, indent, "", n->tag);
    return s;
}

int main() {
    attribute attributes[] = {{"href", "https://example.com"}, {"target", "_blank"}};
    node *n = create_node("a", attributes, 2, NULL, 0);
    char *s = beautify_html(n, 0);
    printf("%s", s);
    free(s);
    free_node(n);
    return 0;
}