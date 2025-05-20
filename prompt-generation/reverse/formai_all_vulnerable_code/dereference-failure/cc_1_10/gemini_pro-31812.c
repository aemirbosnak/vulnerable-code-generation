//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char *name;
    char *value;
} metadata_entry_t;

metadata_entry_t *metadata_entries;
int metadata_entries_count;

void metadata_extractor_init() {
    metadata_entries = NULL;
    metadata_entries_count = 0;
}

void metadata_extractor_free() {
    for (int i = 0; i < metadata_entries_count; i++) {
        free(metadata_entries[i].name);
        free(metadata_entries[i].value);
    }
    free(metadata_entries);
}

int metadata_extractor_add_entry(char *name, char *value) {
    metadata_entries = realloc(metadata_entries, (metadata_entries_count + 1) * sizeof(metadata_entry_t));
    if (metadata_entries == NULL) {
        return -1;
    }

    metadata_entries[metadata_entries_count].name = strdup(name);
    metadata_entries[metadata_entries_count].value = strdup(value);
    metadata_entries_count++;

    return 0;
}

char *metadata_extractor_get_entry(char *name) {
    for (int i = 0; i < metadata_entries_count; i++) {
        if (strcmp(metadata_entries[i].name, name) == 0) {
            return metadata_entries[i].value;
        }
    }

    return NULL;
}

int main() {
    // Initialize the metadata extractor
    metadata_extractor_init();

    // Open the file to extract metadata from
    int fd = open("metadata.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the file contents into a buffer
    char *buffer = malloc(1024);
    int bytes_read = read(fd, buffer, 1024);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    // Extract the metadata from the buffer
    char *line;
    char *name;
    char *value;
    while ((line = strtok(buffer, "\n")) != NULL) {
        // Split the line into name and value
        name = strtok(line, ":");
        value = strtok(NULL, "\n");

        // Add the metadata entry to the metadata extractor
        metadata_extractor_add_entry(name, value);
    }

    // Free the buffer
    free(buffer);

    // Get the value of a specific metadata entry
    char *metadata_value = metadata_extractor_get_entry("Title");

    // Print the value of the metadata entry
    printf("Title: %s\n", metadata_value);

    // Free the metadata extractor
    metadata_extractor_free();

    return EXIT_SUCCESS;
}