//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *metadata_str) {
    char *delimiter = "=";
    char *token = strtok(metadata_str, delimiter);
    metadata_t *metadata = malloc(sizeof(metadata_t));

    while (token!= NULL) {
        if (metadata->name == NULL) {
            metadata->name = strdup(token);
        } else if (metadata->value == NULL) {
            metadata->value = strdup(token);
        }

        token = strtok(NULL, delimiter);
    }

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

int main() {
    char input_file_name[MAX_LINE_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    FILE *input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input_file))!= -1) {
        if (line[0] == '#') {
            metadata_t *metadata = parse_metadata(line + 1);
            print_metadata(metadata);
            free(metadata->name);
            free(metadata->value);
            free(metadata);
        }
    }

    free(line);
    fclose(input_file);

    return 0;
}