//Falcon-180B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

// Function to read a string from the user
char* readString(char* prompt) {
    char input[MAX_STR_LEN];
    printf("%s", prompt);
    fgets(input, MAX_STR_LEN, stdin);
    return strdup(input);
}

// Function to write a string to a file
void writeStringToFile(FILE* file, char* str) {
    fprintf(file, "%s", str);
}

// Function to read a string from a file
char* readStringFromFile(FILE* file) {
    char input[MAX_STR_LEN];
    fgets(input, MAX_STR_LEN, file);
    return strdup(input);
}

int main() {
    char filename[MAX_STR_LEN];
    FILE* file;

    // Prompt the user for the filename
    printf("Enter the filename: ");
    filename[0] = '\0';
    readString(filename);

    // Open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Get the user's input and write it to the file
    char* input = readString("Enter the text to write to the file: ");
    writeStringToFile(file, input);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Read the file contents and print them to the console
    char* line = readStringFromFile(file);
    while (line!= NULL) {
        printf("%s", line);
        free(line);
        line = readStringFromFile(file);
    }

    // Close the file
    fclose(file);

    return 0;
}