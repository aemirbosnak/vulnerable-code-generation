//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    char value[50];
} Attribute;

typedef struct {
    char name[50];
    Attribute attributes[10];
    int n_attributes;
} Tag;

typedef struct {
    char tag_name[50];
    char text[100];
} Data;

typedef struct {
    Tag tags[100];
    Data data[100];
    int n_tags;
    int n_data;
} XMLParser;

void parseData(char *line, XMLParser *parser) {
    Data newData;

    int name_length = strchr(line, '>') - line - 1;
    strncpy(newData.tag_name, line + 1, name_length);

    char *text = strchr(line, '>') + 1;
    strcpy(newData.text, text);

    parser->data[parser->n_data++] = newData;
}

void parseAttributes(char *tag, Tag *newTag) {
    char *name_start = tag + 1;
    char *value_start = strchr(tag, '=') + 2;

    int name_length = strchr(tag, ' ') - name_start;
    strncpy(newTag->name, name_start, name_length);

    int value_length = strchr(value_start, '"') - value_start;
    strncpy(newTag->attributes[newTag->n_attributes].name, name_start, name_length);
    strncpy(newTag->attributes[newTag->n_attributes].value, value_start, value_length);

    newTag->n_attributes++;
}

bool isTag(char *line) {
    if (line[0] == '<' && line[1] != '/') {
        return true;
    }
    return false;
}

void parseTag(char *line, XMLParser *parser) {
    Tag newTag;
    newTag.n_attributes = 0;

    char *tag_start = line + 1;
    char *tag_end = strchr(line, '>');

    int tag_length = tag_end - tag_start;
    strncpy(newTag.name, tag_start, tag_length);

    char *attribute_start = strchr(tag_start, ' ') + 1;
    char *attribute_end = strchr(tag_start, '>');

    while (attribute_start != attribute_end && attribute_start != NULL) {
        char *next_attribute_start = strchr(attribute_start + 1, ' ') + 1;
        if (next_attribute_start > attribute_end) {
            next_attribute_start = attribute_end;
        }

        char *attribute = malloc(next_attribute_start - attribute_start + 1);
        strncpy(attribute, attribute_start, next_attribute_start - attribute_start);
        attribute[next_attribute_start - attribute_start] = '\0';

        parseAttributes(attribute, &newTag);
        attribute_start = next_attribute_start;
        free(attribute);
    }

    parser->tags[parser->n_tags++] = newTag;
}

XMLParser parseXML(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    XMLParser parser;
    parser.n_tags = 0;
    parser.n_data = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (isTag(line)) {
            parseTag(line, &parser);
        } else {
            parseData(line, &parser);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    return parser;
}

int main() {
    XMLParser parser = parseXML("example.xml");

    printf("Tags:\n");
    for (int i = 0; i < parser.n_tags; i++) {
        Tag tag = parser.tags[i];
        printf("<%s", tag.name);
        for (int j = 0; j < tag.n_attributes; j++) {
            Attribute attribute = tag.attributes[j];
            printf(" %s=\"%s\"", attribute.name, attribute.value);
        }
        printf(">\n");
    }

    printf("\nData:\n");
    for (int i = 0; i < parser.n_data; i++) {
        Data data = parser.data[i];
        printf("<%s>%s</%s>\n", data.tag_name, data.text, data.tag_name);
    }

    return 0;
}