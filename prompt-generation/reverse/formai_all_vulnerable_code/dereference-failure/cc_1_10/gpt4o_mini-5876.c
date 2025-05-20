//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 256

void welcomeMessage() {
    printf("🦄 Welcome to the Cheery CSV Reader! 🎉\n");
    printf("Let's have fun reading your CSV files! 📊\n\n");
}

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "😞 Oops! Cannot open file '%s'. Please check the file name.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *token;
    char *rows[MAX_ROWS][MAX_COLS];
    int rowCount = 0;
    int colCount = 0;

    printf("📖 Reading the file: %s\n", filename);

    // Read each line until EOF
    while (fgets(line, sizeof(line), file)) {
        colCount = 0; // Reset column count for each new row
        token = strtok(line, ","); // Tokenize based on commas

        while (token != NULL && colCount < MAX_COLS) {
            rows[rowCount][colCount] = malloc(strlen(token) + 1);
            strcpy(rows[rowCount][colCount], token);
            token = strtok(NULL, ",");
            colCount++;
        }

        rowCount++;
        if (rowCount >= MAX_ROWS) {
            break; // We have hit the limit of rows
        }
    }

    fclose(file); // Important to close the file
    printf("🎉 Successfully read %d rows and %d columns!\n\n", rowCount, colCount);
    
    // Print out the CSV content in a colorful manner
    printf("✨ Here is the data you have:\n");
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            // Print each cell with some sparkle!
            printf("✨ %s ", rows[i][j]);
            free(rows[i][j]); // Free memory after printing
        }
        printf("\n");
    }
    
    printf("\nThank you for using the Cheery CSV Reader! 🌈\n");
}

int main(int argc, char *argv[]) {
    welcomeMessage();

    if (argc < 2) {
        printf("🌟 Please provide a CSV file name as an argument! 🌟\n");
        return 1;
    }

    readCSV(argv[1]);

    return 0;
}