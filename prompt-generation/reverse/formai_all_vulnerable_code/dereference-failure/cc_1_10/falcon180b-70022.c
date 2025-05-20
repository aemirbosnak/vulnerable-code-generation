//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 10

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    int num_tags;
    tag_t tags[MAX_NUM_TAGS];
} metadata_t;

metadata_t *metadata_extract(FILE *file) {
    metadata_t *result = malloc(sizeof(metadata_t));
    if (result == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int num_tags = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == ':') {
                line[i] = '\0';
                tag_t *tag = malloc(sizeof(tag_t));
                if (tag == NULL) {
                    printf("Error: Failed to allocate memory.\n");
                    exit(1);
                }

                tag->name = strdup(&line[i+1]);
                tag->value = strdup(line);

                result->tags[num_tags++] = *tag;
                if (num_tags >= MAX_NUM_TAGS) {
                    printf("Error: Maximum number of tags exceeded.\n");
                    exit(1);
                }
                break;
            }
        }
    }

    result->num_tags = num_tags;
    return result;
}

void metadata_print(metadata_t *metadata) {
    printf("Number of tags: %d\n", metadata->num_tags);

    int i;
    for (i = 0; i < metadata->num_tags; i++) {
        printf("\tName: %s\n", metadata->tags[i].name);
        printf("\tValue: %s\n", metadata->tags[i].value);
        printf("\n");
    }
}

void metadata_free(metadata_t *metadata) {
    int i;
    for (i = 0; i < metadata->num_tags; i++) {
        free(metadata->tags[i].name);
        free(metadata->tags[i].value);
    }
    free(metadata);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    metadata_t *metadata = metadata_extract(file);
    metadata_print(metadata);
    metadata_free(metadata);

    fclose(file);
    return 0;
}