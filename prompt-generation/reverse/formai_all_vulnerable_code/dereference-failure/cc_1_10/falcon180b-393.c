//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} metadata_t;

char *trim_whitespace(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            str[i] = toupper(str[i]);
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
    return str;
}

metadata_t *parse_metadata_line(char *line) {
    char *key = NULL;
    char *value = NULL;
    char *token = strtok(line, ":");
    if (token!= NULL) {
        key = trim_whitespace(token);
        value = trim_whitespace(strtok(NULL, ":"));
    }
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->key = strdup(key);
    metadata->value = strdup(value);
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;

    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (metadata!= NULL) {
            free_metadata(metadata);
        }
        metadata = parse_metadata_line(line);
        print_metadata(metadata);
    }

    if (metadata!= NULL) {
        free_metadata(metadata);
    }

    fclose(file);
    return 0;
}