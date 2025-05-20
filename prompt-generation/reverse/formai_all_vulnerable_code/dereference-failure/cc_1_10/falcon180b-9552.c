//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to count characters in a string
int countChars(char* str) {
    int count = 0;
    while (*str!= '\0') {
        str++;
        count++;
    }
    return count;
}

// Function to count sentences in a string
int countSentences(char* str) {
    int count = 0;
    char* sentence = strtok(str, ".");
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to count paragraphs in a string
int countParagraphs(char* str) {
    int count = 0;
    char* paragraph = strtok(str, "\n");
    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n");
    }
    return count;
}

int main() {
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* text = NULL;
    int totalWords = 0;
    int totalChars = 0;
    int totalSentences = 0;
    int totalParagraphs = 0;

    // Open the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the file line by line
    while ((read = getline(&line, &len, file))!= -1) {
        // Append the line to the text
        text = realloc(text, strlen(text) + read + 1);
        strcat(text, line);

        // Count words, characters, sentences, and paragraphs
        totalWords += countWords(line);
        totalChars += countChars(line);
        totalSentences += countSentences(line);
        totalParagraphs += countParagraphs(line);
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Total words: %d\n", totalWords);
    printf("Total characters: %d\n", totalChars);
    printf("Total sentences: %d\n", totalSentences);
    printf("Total paragraphs: %d\n", totalParagraphs);

    // Free memory
    free(line);
    free(text);

    return 0;
}