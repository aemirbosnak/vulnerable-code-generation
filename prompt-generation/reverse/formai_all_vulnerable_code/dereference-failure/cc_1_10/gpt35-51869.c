//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct metadata {
    char* author;
    char* title;
    int year;
    char* publisher;
    char* language;
} metadata;

metadata* extract_metadata(const char* filename) {
    metadata* md = calloc(1, sizeof(metadata));
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Failed to open file \"%s\" for reading.\n", filename);
        return NULL;
    }
    char buffer[1024], key[64], value[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%[^:]: %[^\n]\n", key, value);
        if (strcmp(key, "Author") == 0) {
            md->author = strdup(value);
        } else if (strcmp(key, "Title") == 0) {
            md->title = strdup(value);
        } else if (strcmp(key, "Year") == 0) {
            md->year = atoi(value);
        } else if (strcmp(key, "Publisher") == 0) {
            md->publisher = strdup(value);
        } else if (strcmp(key, "Language") == 0) {
            md->language = strdup(value);
        }
    }
    fclose(fp);
    return md;
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    metadata* md = extract_metadata(argv[1]);
    if (md) {
        printf("Author: %s\n", md->author ? md->author : "(unknown)");
        printf("Title: %s\n", md->title ? md->title : "(untitled)");
        printf("Year: %d\n", md->year);
        printf("Publisher: %s\n", md->publisher ? md->publisher : "(unknown)");
        printf("Language: %s\n", md->language ? md->language : "(unknown)");
        free(md->author);
        free(md->title);
        free(md->publisher);
        free(md->language);
        free(md);
    }
    return 0;
}