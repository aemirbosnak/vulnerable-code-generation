//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char *key;
    char *value;
} tag_t;

typedef struct {
    int num_tags;
    tag_t tags[MAX_NUM_TAGS];
} metadata_t;

metadata_t *create_metadata(void) {
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        printf("Error: could not allocate memory for metadata.\n");
        exit(1);
    }
    metadata->num_tags = 0;
    return metadata;
}

void destroy_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        free(metadata->tags[i].key);
        free(metadata->tags[i].value);
    }
    free(metadata);
}

void add_tag(metadata_t *metadata, const char *key, const char *value) {
    if (metadata->num_tags >= MAX_NUM_TAGS) {
        printf("Error: maximum number of tags reached.\n");
        exit(1);
    }
    tag_t *tag = &metadata->tags[metadata->num_tags];
    tag->key = strdup(key);
    tag->value = strdup(value);
    metadata->num_tags++;
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("%s: %s\n", metadata->tags[i].key, metadata->tags[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open metadata file.\n");
        return 1;
    }
    metadata_t *metadata = create_metadata();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key_start = line;
        char *value_start = strchr(key_start, ':');
        if (value_start == NULL) {
            printf("Error: invalid metadata format.\n");
            destroy_metadata(metadata);
            fclose(fp);
            return 1;
        }
        *value_start = '\0';
        value_start++;
        while (isspace(*value_start)) {
            value_start++;
        }
        add_tag(metadata, key_start, value_start);
    }
    fclose(fp);
    print_metadata(metadata);
    destroy_metadata(metadata);
    return 0;
}