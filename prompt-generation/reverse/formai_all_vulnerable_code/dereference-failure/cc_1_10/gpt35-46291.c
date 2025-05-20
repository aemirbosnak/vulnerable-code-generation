//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meta_data {
    char* file_name;
    char* author_name;
    char* date_created;
    char* date_modified;
};

void extract_metadata(struct meta_data* md, const char* file_path) {
    FILE* file = fopen(file_path, "r");

    if (!file) {
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* buffer = malloc(file_size * sizeof(char));
    fread(buffer, sizeof(char), file_size, file);

    char* delimiter = "\n";
    char* token = strtok(buffer, delimiter);

    while (token) {
        if (strncmp(token, "Title:", 6) == 0) {
            md->file_name = token + 7;
        } else if (strncmp(token, "Author:", 7) == 0) {
            md->author_name = token + 8;
        } else if (strncmp(token, "Created:", 8) == 0) {
            md->date_created = token + 9;
        } else if (strncmp(token, "Modified:", 9) == 0) {
            md->date_modified = token + 10;
        }

        token = strtok(NULL, delimiter);
    }

    free(buffer);
    fclose(file);
}

int main() {
    struct meta_data md;

    memset(&md, 0, sizeof(md));
    extract_metadata(&md, "example.txt");

    printf("File name: %s\n", md.file_name ? md.file_name : "unknown");
    printf("Author: %s\n", md.author_name ? md.author_name : "unknown");
    printf("Date created: %s\n", md.date_created ? md.date_created : "unknown");
    printf("Date modified: %s\n", md.date_modified ? md.date_modified : "unknown");

    return 0;
}