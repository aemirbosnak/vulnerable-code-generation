//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void extract_metadata(FILE *file, char *filename);
void print_metadata(char *filename, char *author, char *title, char *date);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char filename[256];
    strcpy(filename, argv[1]);
    extract_metadata(file, filename);

    fclose(file);
    return 0;
}

void extract_metadata(FILE *file, char *filename) {
    char line[1024];
    char author[256] = "";
    char title[256] = "";
    char date[256] = "";

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "Author:")!= NULL) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                strcat(author, token);
                strcat(author, " ");
                token = strtok(NULL, " ");
            }
        } else if (strstr(line, "Title:")!= NULL) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                strcat(title, token);
                strcat(title, " ");
                token = strtok(NULL, " ");
            }
        } else if (strstr(line, "Date:")!= NULL) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                strcat(date, token);
                strcat(date, " ");
                token = strtok(NULL, " ");
            }
        }
    }

    print_metadata(filename, author, title, date);
}

void print_metadata(char *filename, char *author, char *title, char *date) {
    printf("Metadata for file '%s'\n", filename);
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Date: %s\n", date);
}