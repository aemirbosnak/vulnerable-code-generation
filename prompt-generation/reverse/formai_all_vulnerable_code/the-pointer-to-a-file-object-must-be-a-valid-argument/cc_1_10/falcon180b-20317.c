//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 50

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_array = NULL;
int metadata_count = 0;

char *get_next_token(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        line = NULL;
        token = strtok(line, " ");
    }
    return token;
}

void add_metadata(char *key, char *value) {
    metadata_t *new_metadata = (metadata_t *) malloc(sizeof(metadata_t));
    new_metadata->key = strdup(key);
    new_metadata->value = strdup(value);

    metadata_array = (metadata_t *) realloc(metadata_array, sizeof(metadata_t) * ++metadata_count);
    metadata_array[metadata_count - 1] = *new_metadata;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("example.txt", "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = get_next_token(line);
        while (token!= NULL) {
            if (strncmp(token, "title:", 6) == 0) {
                add_metadata("title", token + 6);
            } else if (strncmp(token, "author:", 7) == 0) {
                add_metadata("author", token + 7);
            } else if (strncmp(token, "date:", 5) == 0) {
                add_metadata("date", token + 5);
            }

            token = get_next_token(NULL);
        }
    }

    fclose(file);

    printf("Title: %s\n", metadata_array[0].value);
    printf("Author: %s\n", metadata_array[1].value);
    printf("Date: %s\n", metadata_array[2].value);

    for (int i = 0; i < metadata_count; i++) {
        free(metadata_array[i].key);
        free(metadata_array[i].value);
    }
    free(metadata_array);

    return 0;
}