//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the metadata struct
typedef struct {
    char *filename;
    int lines;
    int words;
    int characters;
} Metadata;

// Function to count lines in a file
int count_lines(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

// Function to count words in a file
int count_words(FILE *file) {
    int count = 0;
    char c;
    char *word = malloc(1000);
    while ((c = fgetc(file))!= EOF) {
        if (isspace(c)) {
            if (strlen(word) > 0) {
                count++;
            }
            memset(word, 0, 1000);
        } else {
            strncat(word, &c, 1);
        }
    }
    if (strlen(word) > 0) {
        count++;
    }
    free(word);
    return count;
}

// Function to count characters in a file
int count_characters(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        count++;
    }
    return count;
}

// Function to extract metadata from a file
Metadata extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return (Metadata) { NULL, 0, 0, 0 };
    }
    Metadata metadata = (Metadata) { strdup(filename), count_lines(file), count_words(file), count_characters(file) };
    fclose(file);
    return metadata;
}

// Function to print metadata
void print_metadata(Metadata metadata) {
    if (metadata.filename == NULL) {
        printf("File not found.\n");
        return;
    }
    printf("Filename: %s\n", metadata.filename);
    printf("Lines: %d\n", metadata.lines);
    printf("Words: %d\n", metadata.words);
    printf("Characters: %d\n", metadata.characters);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    Metadata metadata = extract_metadata(argv[1]);
    print_metadata(metadata);
    free(metadata.filename);
    return 0;
}