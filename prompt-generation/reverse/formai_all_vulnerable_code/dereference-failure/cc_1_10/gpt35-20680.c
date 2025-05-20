//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* tag_name;
    char** attributes;
    char** values;
    int num_attrs;
} XMLTag;

// Function to parse an XML tag
XMLTag* parse_tag(char* line) {
    XMLTag* tag = (XMLTag*)malloc(sizeof(XMLTag));
    char* start = strchr(line, '<') + 1;
    char* end = strchr(start, ' ');

    if (end == NULL) {
        end = strchr(start, '>');
        tag->num_attrs = 0;
    } else {
        tag->num_attrs = 1;
        while (*end != '>') {
            end = strchr(end + 1, ' ');
            tag->num_attrs++;
        }
    }

    tag->tag_name = (char*)malloc(end - start + 1);
    memcpy(tag->tag_name, start, end - start);
    tag->tag_name[end - start] = '\0';

    tag->attributes = (char**)malloc(tag->num_attrs * sizeof(char*));
    tag->values = (char**)malloc(tag->num_attrs * sizeof(char*));

    char* name_start = start;
    char* value_start = strchr(start, ' ');

    for (int i = 0; i < tag->num_attrs; i++) {
        name_start = value_start + 1;
        value_start = strchr(name_start, '\"');
        tag->attributes[i] = (char*)malloc((value_start - name_start) + 1);
        memcpy(tag->attributes[i], name_start, value_start - name_start);
        tag->attributes[i][value_start - name_start] = '\0';

        char* value_end = strchr(value_start + 1, '\"');
        size_t value_length = value_end - (value_start + 1);
        tag->values[i] = (char*)malloc(value_length + 1);
        memcpy(tag->values[i], value_start + 1, value_length);
        tag->values[i][value_length] = '\0';
    }

    return tag;
}

int main(int argc, char** argv) {
    FILE* fp = fopen("example.xml", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int line_number = 1;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        XMLTag* tag = parse_tag(buffer);
        printf("Tag %d: %s\nAttributes:\n", line_number, tag->tag_name);
        for (int i = 0; i < tag->num_attrs; i++) {
            printf("\t%s: %s\n", tag->attributes[i], tag->values[i]);
        }
        line_number++;
    }

    fclose(fp);

    return 0;
}