//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_META_LENGTH 256
#define MAX_META_KEYS 50

typedef struct {
    char *key;
    char *value;
} meta_t;

meta_t *meta_list;
int num_meta_entries;

void init_metadata() {
    meta_list = (meta_t *)malloc(sizeof(meta_t));
    num_meta_entries = 0;
}

void add_meta(char *key, char *value) {
    if (num_meta_entries >= MAX_META_KEYS) {
        printf("Error: Too many metadata entries!\n");
        exit(1);
    }
    meta_list[num_meta_entries].key = strdup(key);
    meta_list[num_meta_entries].value = strdup(value);
    num_meta_entries++;
}

void print_meta() {
    for (int i = 0; i < num_meta_entries; i++) {
        printf("%s: %s\n", meta_list[i].key, meta_list[i].value);
    }
}

char *read_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    return strdup(line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    init_metadata();

    char *line;
    while ((line = read_line(file))!= NULL) {
        if (line[0] == '#') {
            char *key, *value;
            if (sscanf(line, "#%*s %s %s", key, value) == 2) {
                add_meta(key, value);
            }
        }
    }

    fclose(file);
    print_meta();

    return 0;
}