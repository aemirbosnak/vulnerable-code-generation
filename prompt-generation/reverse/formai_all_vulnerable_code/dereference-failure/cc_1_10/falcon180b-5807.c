//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

typedef struct {
    char *name;
    char *value;
} metadata_t;

int read_metadata(FILE *file, metadata_t *metadata) {
    char line[MAX_LINE];
    char *name = NULL;
    char *value = NULL;
    char *equal = NULL;

    while (fgets(line, MAX_LINE, file)!= NULL) {
        if (name!= NULL) {
            equal = strchr(line, '=');
            if (equal!= NULL) {
                *equal = '\0';
                value = strdup(equal + 1);
                break;
            }
        } else if (strncmp(line, "name=", 5) == 0) {
            name = strdup(line + 5);
        }
    }

    if (name == NULL || value == NULL) {
        return -1;
    }

    metadata->name = name;
    metadata->value = value;

    return 0;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

int main(int argc, char *argv[]) {
    FILE *file;
    metadata_t metadata;

    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (read_metadata(file, &metadata)!= 0) {
        fclose(file);
        return 1;
    }

    print_metadata(&metadata);

    fclose(file);

    return 0;
}