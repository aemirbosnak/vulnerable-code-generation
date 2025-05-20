//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count words in a string
int countWords(char *str) {
    int count = 0, i;

    // Iterate through each character of the string
    for (i = 0; str[i] != '\0'; i++) {
        // If current character is a space or newline, increment the count
        if (str[i] == ' ' || str[i] == '\n') {
            count++;
        }
    }

    // If there are trailing spaces or newlines, ignore them
    while (str[i - 1] == ' ' || str[i - 1] == '\n') {
        count--;
        i--;
    }

    return count + 1; // Add 1 to the count to include the last word
}

// Function to read a file and count the number of words
int countWordsFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");

    // If file cannot be opened, return -1
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return -1;
    }

    // Read contents of file into a string
    char str[10000];
    fgets(str, 10000, file);

    // Close the file
    fclose(file);

    // Count words in the string
    int count = countWords(str);

    return count;
}

int main() {
    // Read file name from user
    char fileName[100];
    printf("Enter file name (with extension): ");
    scanf("%s", fileName);

    // Get word count from file
    int count = countWordsFromFile(fileName);

    // If file could not be opened, exit the program
    if (count == -1) {
        return 0;
    }

    // Print word count
    printf("Number of words in file: %d\n", count);

    return 0;
}