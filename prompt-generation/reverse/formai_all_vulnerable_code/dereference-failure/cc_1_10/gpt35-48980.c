//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILEPATH_LEN 255
#define MAX_FILENAME_LEN 50
#define MAX_METADATA_LEN 1024

char *read_file(char *filepath, size_t *file_size);
char *extract_metadata(char *file_contents, size_t file_size);
void print_metadata(char *metadata);

int main(int argc, char *argv[]) {
    char filepath[MAX_FILEPATH_LEN];
    char *file_contents;
    size_t file_size;
    char *metadata;

    printf("Enter the filepath to the file whose metadata you want to extract:\n");
    fgets(filepath, MAX_FILEPATH_LEN, stdin);
    strtok(filepath, "\n");

    file_contents = read_file(filepath, &file_size);
    if (file_contents == NULL) {
        printf("Error: Could not read file '%s'\n", filepath);
        return 1;
    }

    metadata = extract_metadata(file_contents, file_size);

    if (metadata == NULL) {
        printf("Error: Could not extract metadata from file '%s'\n", filepath);
        free(file_contents);
        return 1;
    }

    printf("\nMetadata for file '%s':\n", filepath);
    print_metadata(metadata);

    free(file_contents);
    free(metadata);

    return 0;
}

char *read_file(char *filepath, size_t *file_size) {
    FILE *file;
    char *file_contents;
    
    file = fopen(filepath, "rb");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_contents = (char*) malloc(*file_size);
    fread(file_contents, 1, *file_size, file);
    fclose(file);

    return file_contents;
}

char *extract_metadata(char *file_contents, size_t file_size) {
    char *metadata;
    char filename[MAX_FILENAME_LEN];
    char filetype[MAX_FILENAME_LEN];
    char filedate[MAX_FILENAME_LEN];
    int num_bytes_read;
    metadata = (char*) malloc(MAX_METADATA_LEN);
    if (metadata == NULL) {
        return NULL;
    }

    /* reverse engineer metadata from file contents */
    num_bytes_read = sscanf(file_contents, "%[^|]|%[^|]|%[^|]|", filename, filetype, filedate);

    if (num_bytes_read != 3) {
        free(metadata);
        return NULL;
    }

    /* format metadata into user-friendly format */
    sprintf(metadata, "Filename: %s\nFiletype: %s\nDate Created: %s\n", filename, filetype, filedate);

    return metadata;
}

void print_metadata(char *metadata) {
    printf("%s", metadata);
}