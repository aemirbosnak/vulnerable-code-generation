//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define metadata struct
struct metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
};

void print_metadata(struct metadata *file) {
    printf("Title: %s\n", file->title);
    printf("Artist: %s\n", file->artist);
    printf("Album: %s\n", file->album);
    printf("Year: %d\n", file->year);
    printf("Genre: %s\n", file->genre);
}

struct metadata *extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s not found\n", filename);
        exit(1);
    }
    char line[100];
    struct metadata *file = malloc(sizeof(struct metadata));
    while (fgets(line, 100, fp)) {
        char *field = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (strcmp(field, "Title") == 0) {
            strcpy(file->title, value);
        } else if (strcmp(field, "Artist") == 0) {
            strcpy(file->artist, value);
        } else if (strcmp(field, "Album") == 0) {
            strcpy(file->album, value);
        } else if (strcmp(field, "Year") == 0) {
            file->year = atoi(value);
        } else if (strcmp(field, "Genre") == 0) {
            strcpy(file->genre, value);
        }
    }
    fclose(fp);
    return file;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Error: usage %s <filename>\n", argv[0]);
        exit(1);
    }
    struct metadata *file = extract_metadata(argv[1]);
    print_metadata(file);
    free(file);
    return 0;
}