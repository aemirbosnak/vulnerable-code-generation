//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t length;
    const char *value;
} String;

typedef struct {
    const char *name;
    String *value;
} Metadata;

typedef struct {
    size_t length;
    Metadata *metadata;
} MetadataList;

const String *find_metadata(const MetadataList *list, const char *name) {
    for (size_t i = 0; i < list->length; i++) {
        if (strcmp(list->metadata[i].name, name) == 0) {
            return list->metadata[i].value;
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    char *file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        perror("malloc");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';
    fclose(file);

    char *metadata_start = strstr(file_content, "metadata:");
    if (metadata_start == NULL) {
        fprintf(stderr, "No metadata found in file\n");
        free(file_content);
        return EXIT_FAILURE;
    }

    char *metadata_end = strstr(metadata_start, "\n\n");
    if (metadata_end == NULL) {
        metadata_end = metadata_start + strlen(metadata_start);
    }

    String metadata_string = {
        .length = metadata_end - metadata_start,
        .value = metadata_start + 9,
    };

    char *metadata_line_start = metadata_string.value;
    MetadataList metadata_list = {
        .length = 0,
        .metadata = NULL,
    };

    while (metadata_line_start != metadata_end) {
        char *metadata_line_end = strchr(metadata_line_start, '\n');
        if (metadata_line_end == NULL) {
            metadata_line_end = metadata_end;
        }

        char *name_end = strchr(metadata_line_start, ':');
        if (name_end == NULL) {
            fprintf(stderr, "Invalid metadata line: %.*s\n", (int)(metadata_line_end - metadata_line_start), metadata_line_start);
            free(file_content);
            return EXIT_FAILURE;
        }

        String name = {
            .length = name_end - metadata_line_start,
            .value = metadata_line_start,
        };

        String value = {
            .length = metadata_line_end - name_end - 1,
            .value = name_end + 1,
        };

        Metadata metadata = {
            .name = name.value,
            .value = &value,
        };

        metadata_list.length++;
        metadata_list.metadata = realloc(metadata_list.metadata, metadata_list.length * sizeof(Metadata));
        metadata_list.metadata[metadata_list.length - 1] = metadata;

        metadata_line_start = metadata_line_end + 1;
    }

    const String *title = find_metadata(&metadata_list, "title");
    if (title != NULL) {
        printf("Title: %.*s\n", (int)title->length, title->value);
    }

    const String *author = find_metadata(&metadata_list, "author");
    if (author != NULL) {
        printf("Author: %.*s\n", (int)author->length, author->value);
    }

    const String *date = find_metadata(&metadata_list, "date");
    if (date != NULL) {
        printf("Date: %.*s\n", (int)date->length, date->value);
    }

    free(metadata_list.metadata);
    free(file_content);
    return EXIT_SUCCESS;
}