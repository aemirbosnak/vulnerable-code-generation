//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a constant to represent the maximum number of characters for each line
#define MAX_LINE_LENGTH 100

// Define a structure to store each line of the CSV file
typedef struct line {
    char* data[10]; // Assume CSV file has maximum 10 columns
    struct line *next; // Pointer to next line
} Line;

// Define a function to read a CSV file and return a pointer to the first line
Line* readCSVFile(char* filename) {
    // Open the CSV file
    FILE* file = fopen(filename, "r");

    // Check if file is open successfully
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Initialize variables
    char lineStr[MAX_LINE_LENGTH];
    int lineCount = 0;
    Line* firstLine = NULL;
    Line* lastLine = NULL;

    // Read the CSV file line by line
    while (fgets(lineStr, MAX_LINE_LENGTH, file)) {
        // Parse the line, splitting by commas
        char* token;
        int tokenCount = 0;
        Line* currentLine = malloc(sizeof(Line));
        currentLine->next = NULL;
        token = strtok(lineStr, ",");
        while (token) {
            currentLine->data[tokenCount] = malloc(strlen(token) + 1);
            strcpy(currentLine->data[tokenCount], token);
            token = strtok(NULL, ",");
            tokenCount++;
        }

        // Add the current line to the linked list of lines
        if (lineCount == 0) {
            firstLine = currentLine;
            lastLine = currentLine;
        } else {
            lastLine->next = currentLine;
            lastLine = currentLine;
        }

        lineCount++;
    }

    // Close the file
    fclose(file);

    // Return a pointer to the first line
    return firstLine;
}

// Define a function to print all the lines of a CSV file
void printCSVFile(Line* firstLine) {
    // Loop through all the lines and print each line
    Line* currentLine = firstLine;
    while (currentLine) {
        for (int i = 0; i < 10 && currentLine->data[i]; i++) {
            printf("%s ", currentLine->data[i]);
        }
        printf("\n");
        currentLine = currentLine->next;
    }
}

int main() {
    // Read the CSV file and print its contents
    Line* firstLine = readCSVFile("example.csv");
    printCSVFile(firstLine);

    return 0;
}