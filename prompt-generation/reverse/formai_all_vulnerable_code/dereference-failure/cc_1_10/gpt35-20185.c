//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* tag_name;
    char** attributes;
    int num_attributes;
    char* value;
} XMLTag;

void parse_element(char* buf, int len);
void parse_tag(char* tag_str, XMLTag* tag);
char** parse_attributes(char* attr_str, int* num_attrs);
int is_valid_char(char c);
void error(char* msg);

int main() {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    int len;

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        error("Failed to open file");
    }

    len = fread(buffer, 1, BUFFER_SIZE, fp); // read from file
    while (len > 0) {
        parse_element(buffer, len);
        len = fread(buffer, 1, BUFFER_SIZE, fp);
    }

    fclose(fp);
    return 0;
}

void parse_element(char* buf, int len) {
    int i;
    XMLTag tag;

    for (i = 0; i < len; i++) {
        if (buf[i] == '<') {
            tag.tag_name = malloc(sizeof(char) * BUFFER_SIZE);
            tag.attributes = NULL;
            tag.num_attributes = 0;
            tag.value = "";

            // get tag string
            int end_idx = i + 1;
            while (end_idx < len && buf[end_idx] != '>') {
                end_idx++;
            }
            char* tag_str = malloc(sizeof(char) * (end_idx - i));
            strncpy(tag_str, buf + i + 1, end_idx - i - 1);
            tag_str[end_idx - i - 1] = '\0';

            parse_tag(tag_str, &tag);
            printf("Found tag: %s with %d attributes\n", tag.tag_name, tag.num_attributes);
            for (int j = 0; j < tag.num_attributes; j++) {
                printf("Attribute %d: %s\n", j + 1, tag.attributes[j]);
            }

            free(tag.tag_name); // free memory
            free(tag_str);
            for (int j = 0; j < tag.num_attributes; j++) {
                free(tag.attributes[j]);
            }
            free(tag.attributes);
        }
    }
}

void parse_tag(char* tag_str, XMLTag* tag) {
    int len = strlen(tag_str);
    int i = 0;

    // get tag name
    while (i < len && is_valid_char(tag_str[i])) {
        tag->tag_name[i] = tag_str[i];
        i++;
    }
    tag->tag_name[i] = '\0';

    // get tag attributes
    if (tag_str[i] != '>') {
        char* attr_str = malloc(sizeof(char) * BUFFER_SIZE);
        strncpy(attr_str, tag_str + i + 1, len - i - 2);
        attr_str[len - i - 2] = '\0';

        tag->attributes = parse_attributes(attr_str, &tag->num_attributes);
        free(attr_str);
    }
}

char** parse_attributes(char* attr_str, int* num_attrs) {
    char** attrs = malloc(sizeof(char*) * 10);
    int len = strlen(attr_str);
    int i = 0, j = 0;

    while (i < len) {
        char* attr = malloc(sizeof(char) * BUFFER_SIZE);
        int attr_len = 0;

        while (i < len && !is_valid_char(attr_str[i])) {
            i++;
        }

        while (i < len && is_valid_char(attr_str[i])) {
            attr[attr_len] = attr_str[i];
            i++;
            attr_len++;
        }
        attr[attr_len] = '\0';

        attrs[j] = attr;
        j++;
    }

    *num_attrs = j;
    return attrs;
}

int is_valid_char(char c) {
    return c != ' ' && c != '=' && c != '\t' && c != '\n';
}

void error(char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}