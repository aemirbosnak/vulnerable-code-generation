//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char *title;
    char *author;
    char *date;
    char *description;
} metadata;

metadata *extract_metadata(char *file_path) {
    // Some code to extract metadata from file_path and populate metadata struct
    metadata *result = (metadata*) malloc(sizeof(metadata));
    
    if (result == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for metadata struct\n");
        exit(1);
    }
    
    result->title = "Unknown Title";
    result->author = "Unknown Author";
    result->date = "Unknown Date";
    result->description = "Unknown Description";
    
    FILE* file = fopen(file_path, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Error: File not found at %s\n", file_path);
        exit(1);
    }
    
    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "<title>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            int len = end - start;
            result->title = (char*) malloc((len + 1) * sizeof(char));
            strncpy(result->title, start, len);
            result->title[len] = '\0';
        }
        else if (strstr(line, "<author>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            int len = end - start;
            result->author = (char*) malloc((len + 1) * sizeof(char));
            strncpy(result->author, start, len);
            result->author[len] = '\0';
        }
        else if (strstr(line, "<date>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            int len = end - start;
            result->date = (char*) malloc((len + 1) * sizeof(char));
            strncpy(result->date, start, len);
            result->date[len] = '\0';
        }
        else if (strstr(line, "<description>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            int len = end - start;
            result->description = (char*) malloc((len + 1) * sizeof(char));
            strncpy(result->description, start, len);
            result->description[len] = '\0';
        }
    }
    
    fclose(file);
    
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file_path\n", argv[0]);
        exit(1);
    }
    
    metadata *data = extract_metadata(argv[1]);
    
    printf("Title: %s\n", data->title);
    printf("Author: %s\n", data->author);
    printf("Date: %s\n", data->date);
    printf("Description: %s\n", data->description);
    
    free(data->title);
    free(data->author);
    free(data->date);
    free(data->description);
    free(data);

    return 0;
}