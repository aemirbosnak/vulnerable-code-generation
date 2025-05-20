//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to hold the attributes of an XML tag
struct Attribute {
    char *name;
    char *value;
};

// Structure to hold information about an XML tag
struct XMLTag {
    char *name;
    int n_attributes;
    int max_attributes;
    struct Attribute *attributes;
};

// Function to read an XML tag name from the input stream
char *read_tag_name(FILE *input) {
    char buffer[1024];
    int i = 0;
    int c;
    while ((c = fgetc(input)) != EOF && isspace(c));
    if (c == EOF || c == '/' || c == '>') return NULL;
    buffer[i++] = c;
    while ((c = fgetc(input)) != EOF && !isspace(c) && c != '/' && c != '>') {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return strdup(buffer);
}

// Function to read an XML attribute name from the input stream
char *read_attribute_name(FILE *input) {
    char buffer[1024];
    int i = 0;
    int c;
    while ((c = fgetc(input)) != EOF && isspace(c));
    if (c == EOF || c == '/' || c == '>' || c == '=') return NULL;
    buffer[i++] = c;
    while ((c = fgetc(input)) != EOF && !isspace(c) && c != '/' && c != '>' && c != '=') {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return strdup(buffer);
}

// Function to read an XML attribute value from the input stream
char *read_attribute_value(FILE *input) {
    char buffer[1024];
    int i = 0;
    int c;
    while ((c = fgetc(input)) != EOF && isspace(c));
    if (c == EOF || c == '/' || c == '>' || c != '=') return NULL;
    while ((c = fgetc(input)) != EOF && isspace(c));
    if (c != '"' && c != '\'') return NULL;
    const int quote = c;
    while ((c = fgetc(input)) != EOF && c != quote) {
        if (c == '\\') {
            c = fgetc(input);
            if (c == EOF) break;
            buffer[i++] = '\\';
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return strdup(buffer);
}

// Function to create a new XML tag
struct XMLTag *create_tag(const char *name) {
    struct XMLTag *tag = malloc(sizeof(struct XMLTag));
    tag->name = strdup(name);
    tag->n_attributes = 0;
    tag->max_attributes = 8;
    tag->attributes = malloc(sizeof(struct Attribute) * tag->max_attributes);
    return tag;
}

// Function to add an attribute to an XML tag
void add_attribute(struct XMLTag *tag, const char *name, const char *value) {
    if (tag->n_attributes >= tag->max_attributes) {
        tag->max_attributes *= 2;
        tag->attributes = realloc(tag->attributes, sizeof(struct Attribute) * tag->max_attributes);
    }
    tag->attributes[tag->n_attributes].name = strdup(name);
    tag->attributes[tag->n_attributes].value = strdup(value);
    tag->n_attributes++;
}

// Function to parse an XML tag
// Returns 1 if successful, 0 if error or end of input
int parse_tag(FILE *input, struct XMLTag **tag) {
    int c;
    while ((c = fgetc(input)) != EOF && isspace(c));
    if (c == EOF) return 0;
    if (c != '<') return 0;
    if ((c = fgetc(input)) == EOF) return 0;
    if (c == '/') return 0;
    char *name = read_tag_name(input);
    if (name == NULL) return 0;
    *tag = create_tag(name);
    int error = 0;
    while (!error && (c = fgetc(input)) != EOF && c != '>') {
        if (isspace(c)) continue;
        ungetc(c, input);
        char *attribute_name = read_attribute_name(input);
        if (attribute_name == NULL) {
            error = 1;
            break;
        }
        char *attribute_value = read_attribute_value(input);
        if (attribute_value == NULL) {
            error = 1;
            free(attribute_name);
            break;
        }
        add_attribute(*tag, attribute_name, attribute_value);
        free(attribute_name);
        free(attribute_value);
    }
    if (error) {
        free((*tag)->name);
        free((*tag)->attributes);
        free(*tag);
        return 0;
    }
    if (c == EOF) {
        free((*tag)->name);
        free((*tag)->attributes);
        free(*tag);
        return 0;
    }
    return 1;
}

// Function to print an XML tag
void print_tag(struct XMLTag *tag) {
    printf("<%s", tag->name);
    for (int i = 0; i < tag->n_attributes; i++) {
        printf(" %s=\"%s\"", tag->attributes[i].name, tag->attributes[i].value);
    }
    printf(">");
}

int main(int argc, char **argv) {
    struct XMLTag *tag;
    while (parse_tag(stdin, &tag)) {
        print_tag(tag);
        free(tag->name);
        for (int i = 0; i < tag->n_attributes; i++) {
            free(tag->attributes[i].name);
            free(tag->attributes[i].value);
        }
        free(tag->attributes);
        free(tag);
    }
    return 0;
}