//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_FILE_SIZE 100000
#define MAX_LINE_LENGTH 50

// Global variables
char *filePath = "example.txt";
char line[MAX_LINE_LENGTH];
int lineCount = 0;

// Function to read a line from the file
void readLine() {
    int bytesRead;
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return;
    }

    bytesRead = fread(line, 1, MAX_LINE_LENGTH, file);
    line[bytesRead] = '\0';

    if (ferror(file)) {
        printf("Error: Read error\n");
        fclose(file);
        return;
    }

    fclose(file);
}

// Function to write a line to the file
void writeLine() {
    int bytesWritten;
    FILE *file = fopen(filePath, "a");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return;
    }

    bytesWritten = fwrite(line, 1, MAX_LINE_LENGTH, file);
    if (ferror(file)) {
        printf("Error: Write error\n");
        fclose(file);
        return;
    }

    fclose(file);
}

// Main function
int main() {
    srand(time(NULL));

    // Create a random file path
    char *filePath = malloc(sizeof(char) * 20);
    for (int i = 0; i < 20; i++) {
        filePath[i] = 'a' + (rand() % 26);
    }

    // Open the file in read mode
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return 1;
    }

    // Read a line from the file
    readLine();

    // Print the line
    printf("Line read from file: %s\n", line);

    // Close the file
    fclose(file);

    // Create a new file
    file = fopen(filePath, "w");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filePath);
        return 1;
    }

    // Write a line to the file
    writeLine();

    // Close the file
    fclose(file);

    // Print the line that was written
    printf("Line written to file: %s\n", line);

    return 0;
}