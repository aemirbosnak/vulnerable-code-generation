//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototype
int countWordsInLine(char *line);
int countWordsRecursively(FILE *file);

// Main function to handle user input and call the recursive function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    int totalWords = countWordsRecursively(file);
    
    fclose(file);
    printf("Total words in the file: %d\n", totalWords);
    return EXIT_SUCCESS;
}

// Recursive function to count words in the file line by line
int countWordsRecursively(FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) != NULL) {
        return countWordsInLine(line) + countWordsRecursively(file);
    }
    return 0;
}

// Function to count words in a single line
int countWordsInLine(char *line) {
    int count = 0;
    char *token;
    
    // Strip leading and trailing whitespace
    char *start = line;
    while (isspace((unsigned char)*start)) start++;
    char *end = line + strlen(line) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    end[1] = '\0'; // null-terminate after trimming

    // Use strtok to tokenize the line into words
    token = strtok(start, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    
    return count;
}