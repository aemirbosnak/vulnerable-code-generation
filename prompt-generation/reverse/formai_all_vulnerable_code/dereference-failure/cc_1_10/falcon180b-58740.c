//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to read a line from the CSV file
char* readLine(FILE* file) {
    char* line = malloc(100);
    fgets(line, 100, file);
    return line;
}

// Function to split a line into an array of strings
char** splitLine(char* line) {
    int count = 0;
    char* token = strtok(line, ",");
    char** array = malloc(100 * sizeof(char*));
    while (token!= NULL) {
        array[count++] = token;
        token = strtok(NULL, ",");
    }
    array[count] = NULL;
    return array;
}

// Function to print an array of strings
void printArray(char** array) {
    for (int i = 0; array[i]!= NULL; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

// Main function to read the CSV file and print its contents
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a CSV file as an argument.\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char* line;
    while ((line = readLine(file))!= NULL) {
        char** array = splitLine(line);
        printArray(array);
        free(line);
        for (int i = 0; array[i]!= NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
    fclose(file);
    return 0;
}