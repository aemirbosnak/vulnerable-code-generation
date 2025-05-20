//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

void investigate(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        lineCount++;

        // Tokenize the line according to commas.
        char *token = strtok(line, ",");
        int fieldCount = 0;

        while (token != NULL && fieldCount < MAX_FIELDS) {
            fields[fieldCount] = token;
            fieldCount++;
            token = strtok(NULL, ",");
        }

        // Delve into the details of each field.
        printf("Line %d: Found %d fields.\n", lineCount, fieldCount);
        for (int i = 0; i < fieldCount; i++) {
            // Trim whitespaces around fields
            char *field = fields[i];
            field[strcspn(field, "\n")] = 0; // Remove newline character
            printf("Field %d: \"%s\"\n", i + 1, field);
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void extractClues(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Elementary, my dear Watson! We shall examine the clues in the CSV...\n");
    
    investigate(file);
    
    fclose(file);
    printf("The investigation is complete. All clues have been examined.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Ah, the game is afoot! We must uncover the truth hidden within: %s\n", argv[1]);
    extractClues(argv[1]);

    return EXIT_SUCCESS;
}