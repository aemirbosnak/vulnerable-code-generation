//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// metadata structure to hold extracted data
typedef struct {
    char* artist;
    char* album;
    int year;
} Metadata;

// function to extract metadata from input string
Metadata* extractMetadata(char* input) {
    Metadata* meta = malloc(sizeof(Metadata));
    meta->artist = NULL;
    meta->album = NULL;
    meta->year = 0;

    char* token;
    char* str = strdup(input);
    char* delimiters = ", ";
    token = strtok(str, delimiters);

    while (token != NULL) {
        if (strstr(token, "Artist:")) {
            meta->artist = strdup(token + 7);
        } else if (strstr(token, "Album:")) {
            meta->album = strdup(token + 6);
        } else if (strstr(token, "Year:")) {
            meta->year = atoi(token + 5);
        }
        token = strtok(NULL, delimiters);
    }

    free(str);
    return meta;
}

int main() {
    char input[200];

    printf("Enter metadata in the format 'Artist:album, Year:####':\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    Metadata* extracted = extractMetadata(input);

    printf("\nExtracted Metadata:\n");
    printf("Artist: %s\n", extracted->artist);
    printf("Album: %s\n", extracted->album);
    printf("Year: %d\n", extracted->year);

    free(extracted->artist);
    free(extracted->album);
    free(extracted);
    return 0;
}