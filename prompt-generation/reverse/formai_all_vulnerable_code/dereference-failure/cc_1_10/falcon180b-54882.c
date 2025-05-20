//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

// Struct to hold each line of the ebook
typedef struct {
    char text[MAX_LINE_LENGTH];
    int length;
} EbookLine;

// Struct to hold the ebook data
typedef struct {
    EbookLine lines[MAX_NUM_LINES];
    int numLines;
} Ebook;

// Function to load an ebook from a file
Ebook* loadEbook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    Ebook* ebook = malloc(sizeof(Ebook));
    ebook->numLines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }

        EbookLine* newLine = malloc(sizeof(EbookLine));
        newLine->length = length;
        strcpy(newLine->text, line);

        ebook->lines[ebook->numLines++] = *newLine;
    }

    fclose(file);
    return ebook;
}

// Function to print an ebook
void printEbook(Ebook* ebook) {
    for (int i = 0; i < ebook->numLines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

// Function to search an ebook for a phrase
int searchEbook(Ebook* ebook, char* phrase) {
    for (int i = 0; i < ebook->numLines; i++) {
        if (strstr(ebook->lines[i].text, phrase)!= NULL) {
            return i + 1; // Return the line number (1-based)
        }
    }
    return 0; // Phrase not found
}

int main() {
    Ebook* ebook = loadEbook("example.txt");
    printEbook(ebook);

    int result = searchEbook(ebook, "Lorem ipsum");
    if (result > 0) {
        printf("Phrase found on line %d\n", result);
    } else {
        printf("Phrase not found\n");
    }

    free(ebook);
    return 0;
}