//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char name[50];
    char letter[100];
} LoveLetter;

LoveLetter *love_letters_matrix;

int read_csv(FILE *file, int rows, int cols, LoveLetter **matrix) {
    int i, j;
    char line[1024];

    *matrix = (LoveLetter *)malloc(rows * sizeof(LoveLetter));

    for (i = 0; i < rows; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            free(*matrix);
            return -1;
        }

        sscanf(line, "%[%,99s],%[^,],%[^\n]", (*matrix + i)->name, (*matrix + i)->letter, line + strlen((*matrix + i)->letter) + strlen((*matrix + i)->letter));

        for (j = strlen((*matrix + i)->letter); j < sizeof((*matrix + i)->letter) - 1; j++) {
            if ((*matrix + i)->letter[j] != '\n') {
                (*matrix + i)->letter[j] = (*matrix + i)->letter[j + 1];
                (*matrix + i)->letter[j + 1] = '\0';
            }
        }
    }

    return rows;
}

int main() {
    FILE *file;
    int rows;

    file = fopen("love_letters.csv", "r");

    if (file == NULL) {
        printf("Could not open file.\n");
        return -1;
    }

    love_letters_matrix = (LoveLetter *)calloc(MAX_ROWS, sizeof(LoveLetter));

    rows = read_csv(file, MAX_ROWS, MAX_COLS, &love_letters_matrix);

    if (rows < 0) {
        printf("Error reading CSV file.\n");
        free(love_letters_matrix);
        fclose(file);
        return -1;
    }

    printf("Read %d love letters from the file.\n", rows);

    for (int i = 0; i < rows; i++) {
        printf("Letter from %s:\n", love_letters_matrix[i].name);
        printf("%s\n", love_letters_matrix[i].letter);
    }

    free(love_letters_matrix);
    fclose(file);

    return 0;
}