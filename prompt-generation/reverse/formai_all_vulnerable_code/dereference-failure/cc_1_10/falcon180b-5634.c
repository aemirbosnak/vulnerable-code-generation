//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    char *filename;
    int num_tags;
    tag_t tags[MAX_NUM_TAGS];
} metadata_t;

void add_tag(metadata_t *metadata, char *name, char *value) {
    if (metadata->num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags reached.\n");
        return;
    }

    for (int i = 0; i < metadata->num_tags; i++) {
        if (strcmp(metadata->tags[i].name, name) == 0) {
            printf("Warning: Duplicate tag name.\n");
            return;
        }
    }

    metadata->tags[metadata->num_tags].name = strdup(name);
    metadata->tags[metadata->num_tags].value = strdup(value);
    metadata->num_tags++;
}

void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Number of tags: %d\n", metadata->num_tags);

    for (int i = 0; i < metadata->num_tags; i++) {
        printf("Tag name: %s\n", metadata->tags[i].name);
        printf("Tag value: %s\n", metadata->tags[i].value);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <metadata>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *metadata_str = argv[2];
    metadata_t metadata;

    metadata.filename = strdup(filename);
    metadata.num_tags = 0;

    char *tag_start = metadata_str;
    char *tag_name_start = metadata_str;
    char *tag_value_start = metadata_str;

    while (*metadata_str!= '\0') {
        if (*metadata_str == '<') {
            tag_name_start = metadata_str + 1;
            while (*metadata_str!= '>' && *metadata_str!= '\0') {
                metadata_str++;
            }

            if (*metadata_str == '>') {
                metadata_str++;
                tag_value_start = metadata_str;

                while (*metadata_str!= '<' && *metadata_str!= '\0') {
                    metadata_str++;
                }

                if (*metadata_str == '<') {
                    metadata_str++;

                    char *name = malloc(metadata_str - tag_name_start + 1);
                    strncpy(name, tag_name_start, metadata_str - tag_name_start);
                    name[metadata_str - tag_name_start] = '\0';

                    char *value = malloc(metadata_str - tag_value_start + 1);
                    strncpy(value, tag_value_start, metadata_str - tag_value_start);
                    value[metadata_str - tag_value_start] = '\0';

                    add_tag(&metadata, name, value);
                }
            }
        }

        metadata_str++;
    }

    print_metadata(&metadata);

    return 0;
}