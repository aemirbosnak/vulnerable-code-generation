//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char **lines;
    int count;
} TextData;

void initializeTextData(TextData *textData, int maxLines) {
    textData->lines = (char **)malloc(sizeof(char *) * maxLines);
    for (int i = 0; i < maxLines; ++i) {
        textData->lines[i] = (char *)malloc(sizeof(char) * MAX_LENGTH);
    }
    textData->count = 0;
}

void freeTextData(TextData *textData) {
    for (int i = 0; i < textData->count; ++i) {
        free(textData->lines[i]);
    }
    free(textData->lines);
}

void loadTextFromFile(const char *filename, TextData *textData) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(textData->lines[textData->count], MAX_LENGTH, file) != NULL && textData->count < MAX_LINES) {
        textData->count++;
    }

    fclose(file);
}

void displayTextData(const TextData *textData) {
    for (int i = 0; i < textData->count; ++i) {
        printf("%d: %s", i + 1, textData->lines[i]);
    }
}

void saveTextToFile(const char *filename, const TextData *textData) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < textData->count; ++i) {
        fprintf(file, "%s", textData->lines[i]);
    }

    fclose(file);
}

void sortTextLines(TextData *textData) {
    for (int i = 0; i < textData->count - 1; ++i) {
        for (int j = i + 1; j < textData->count; ++j) {
            if (strcmp(textData->lines[i], textData->lines[j]) > 0) {
                char *temp = textData->lines[i];
                textData->lines[i] = textData->lines[j];
                textData->lines[j] = temp;
            }
        }
    }
}

void searchLines(const TextData *textData, const char *query) {
    printf("\nSearch results for '%s':\n", query);
    int found = 0;
    for (int i = 0; i < textData->count; ++i) {
        if (strstr(textData->lines[i], query) != NULL) {
            printf("%d: %s", i + 1, textData->lines[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("No matching lines found.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    TextData textData;
    initializeTextData(&textData, MAX_LINES);
    
    loadTextFromFile(argv[1], &textData);
    printf("Loaded %d lines from %s:\n", textData.count, argv[1]);
    displayTextData(&textData);
    
    printf("\nSorting lines...\n");
    sortTextLines(&textData);
    printf("Sorted lines:\n");
    displayTextData(&textData);
    
    saveTextToFile(argv[2], &textData);
    printf("\nSaved sorted lines to %s\n", argv[2]);

    char query[MAX_LENGTH];
    printf("\nEnter a search term: ");
    fgets(query, MAX_LENGTH, stdin);
    // Remove newline
    query[strcspn(query, "\n")] = 0;

    searchLines(&textData, query);

    freeTextData(&textData);
    
    return EXIT_SUCCESS;
}