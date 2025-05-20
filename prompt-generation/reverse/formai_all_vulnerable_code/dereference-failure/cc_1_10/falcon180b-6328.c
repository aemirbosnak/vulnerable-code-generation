//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to read a line from the file
char* readLine(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    fgets(line, MAX_LINE_SIZE, file);
    return line;
}

// Function to write a line to the file
void writeLine(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to count the number of lines in the file
int countLines(FILE* file) {
    int count = 0;
    char ch;
    rewind(file);
    while ((ch = fgetc(file))!= EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    return count;
}

// Function to print the contents of the file
void printFile(FILE* file) {
    char* line;
    while ((line = readLine(file))!= NULL) {
        printf("%s", line);
    }
}

int main() {
    FILE* file;
    char filename[50];
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Print the contents of the file
    printf("\nContents of the file:\n");
    printFile(file);

    // Count the number of lines in the file
    int numLines = countLines(file);
    printf("\nNumber of lines in the file: %d\n", numLines);

    // Write a new line to the file
    char newLine[50];
    printf("Enter a new line to add to the file: ");
    scanf("%s", newLine);
    writeLine(file, newLine);

    // Print the updated contents of the file
    rewind(file);
    printf("\nUpdated contents of the file:\n");
    printFile(file);

    // Close the file
    fclose(file);
    return 0;
}