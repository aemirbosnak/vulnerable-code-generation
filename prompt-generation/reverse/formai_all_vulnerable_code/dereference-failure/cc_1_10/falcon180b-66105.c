//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_TAGS 50

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    tag_t tags[MAX_NUM_TAGS];
    int num_tags;
} metadata_t;

metadata_t *metadata_new(void) {
    metadata_t *m = malloc(sizeof(metadata_t));
    m->num_tags = 0;
    return m;
}

void metadata_free(metadata_t *m) {
    for (int i = 0; i < m->num_tags; i++) {
        free(m->tags[i].name);
        free(m->tags[i].value);
    }
    free(m);
}

void metadata_add_tag(metadata_t *m, const char *name, const char *value) {
    if (m->num_tags >= MAX_NUM_TAGS) {
        printf("Error: Too many tags\n");
        exit(1);
    }
    tag_t *t = &m->tags[m->num_tags];
    t->name = strdup(name);
    t->value = strdup(value);
    m->num_tags++;
}

void metadata_print(metadata_t *m) {
    for (int i = 0; i < m->num_tags; i++) {
        printf("%s: %s\n", m->tags[i].name, m->tags[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Could not open file\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = metadata_new();
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, ":");
        if (!name ||!value) {
            printf("Error: Invalid metadata line\n");
            metadata_free(metadata);
            fclose(fp);
            return 1;
        }
        metadata_add_tag(metadata, name, value);
    }
    fclose(fp);
    metadata_print(metadata);
    metadata_free(metadata);
    return 0;
}