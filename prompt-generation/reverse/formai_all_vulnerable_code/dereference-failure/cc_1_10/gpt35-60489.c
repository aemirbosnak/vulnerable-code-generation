//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_TAG_VALUE 100

typedef struct xml_tag {
    char *name;
    char *value;
} xml_tag;

void parse_tag(char *tag, xml_tag *xml_tag) {
    char *start_ptr, *end_ptr;
    char tag_name[MAX_TAG_NAME];
    char tag_value[MAX_TAG_VALUE];
    int tag_len, name_len, value_len;

    start_ptr = strchr(tag, '<');
    end_ptr = strchr(tag, '>');

    tag_len = end_ptr - start_ptr - 1;

    strncpy(tag_name, start_ptr + 1, tag_len);

    name_len = strchr(tag_name, ' ') - tag_name;

    strncpy(xml_tag->name, tag_name, name_len);

    tag_value[0] = '\0';

    if (strchr(tag, '"') != NULL) {
        start_ptr = strchr(tag, '"') + 1;
        end_ptr = strchr(start_ptr, '"');
        value_len = end_ptr - start_ptr;
        strncpy(tag_value, start_ptr, value_len);
        tag_value[value_len] = '\0';
        strncpy(xml_tag->value, tag_value, value_len);
    }
}

int main() {
    char tag[100];
    xml_tag *xml_tag;
    int tag_count = 0;

    while (fgets(tag, MAX_TAG_VALUE, stdin) != NULL) {
        xml_tag = malloc(sizeof(xml_tag));
        xml_tag->name = malloc(MAX_TAG_NAME);
        xml_tag->value = malloc(MAX_TAG_VALUE);

        parse_tag(tag, xml_tag);
        printf("Tag %d: %s = '%s'\n", ++tag_count, xml_tag->name, xml_tag->value);

        free(xml_tag->name);
        free(xml_tag->value);
        free(xml_tag);
    }

    return 0;
}