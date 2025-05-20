//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX_TAGS 100
#define MAX_ATTRIBUTES 100
#define MAX_VALUE_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    char *value;
} attribute_t;

typedef struct {
    char *name;
    int num_attributes;
    attribute_t *attributes;
} tag_t;

void add_attribute(tag_t *tag, char *name, char *value) {
    if (tag->num_attributes >= MAX_ATTRIBUTES) {
        printf("Error: Too many attributes for tag '%s'\n", tag->name);
        exit(1);
    }
    attribute_t *attr = &tag->attributes[tag->num_attributes];
    attr->name = strdup(name);
    attr->value = strdup(value);
    tag->num_attributes++;
}

void print_tag(tag_t *tag) {
    printf("<%s", tag->name);
    for (int i = 0; i < tag->num_attributes; i++) {
        attribute_t *attr = &tag->attributes[i];
        printf(" %s=\"%s\"", attr->name, attr->value);
    }
    printf(">");
}

void close_tag(tag_t *tag) {
    printf("</%s>", tag->name);
}

void start_document() {
    printf("<!DOCTYPE html>\n<html>\n");
}

void end_document() {
    printf("</html>\n");
}

int main() {
    start_document();

    tag_t body_tag;
    body_tag.name = "body";
    body_tag.num_attributes = 0;

    char *text = "Hello, world!";
    tag_t p_tag;
    p_tag.name = "p";
    add_attribute(&p_tag, "class", "my-class");
    p_tag.num_attributes = 1;

    print_tag(&body_tag);
    printf("%s", text);
    close_tag(&p_tag);

    end_document();
    return 0;
}