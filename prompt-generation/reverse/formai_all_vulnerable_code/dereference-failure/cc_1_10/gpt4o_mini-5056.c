//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEY_LENGTH 128
#define MAX_VALUE_LENGTH 128

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

void extract_metadata(const char *filename, Metadata **metadata, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    *count = 0;
    *metadata = NULL;

    while (fgets(line, sizeof(line), file)) {
        *metadata = realloc(*metadata, sizeof(Metadata) * (*count + 1));
        if (*metadata == NULL) {
            perror("Failed to allocate memory");
            fclose(file);
            return;
        }

        char *colon_pos = strchr(line, ':');
        if (colon_pos) {
            *colon_pos = '\0';  // Split the line into key and value
            strncpy((*metadata)[*count].key, line, MAX_KEY_LENGTH);
            strncpy((*metadata)[*count].value, colon_pos + 1, MAX_VALUE_LENGTH);
            (*metadata)[*count].value[strcspn((*metadata)[*count].value, "\n")] = 0; // Remove newline
            (*count)++;
        }
    }

    fclose(file);
}

void display_metadata(const Metadata *metadata, int count) {
    printf("Extracted Metadata:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }
}

void free_metadata(Metadata *metadata) {
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata *metadata = NULL;
    int count = 0;

    extract_metadata(argv[1], &metadata, &count);
    display_metadata(metadata, count);
    free_metadata(metadata);

    return EXIT_SUCCESS;
}