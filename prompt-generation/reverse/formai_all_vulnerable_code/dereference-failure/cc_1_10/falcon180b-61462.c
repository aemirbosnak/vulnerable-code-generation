//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int length;
} Word;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Word word;
    char *filename = "ebook.txt";
    int count = 0;

    // Open the ebook file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open ebook file.\n");
        exit(1);
    }

    // Read the ebook line by line
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        count++;
        printf("Line %d:\n", count);
        printf("%s", line);

        // Find the longest word in the line
        word.word = strtok(line, " \n\t\r\f\v\b");
        word.length = strlen(word.word);
        while ((word.word = strtok(NULL, " \n\t\r\f\v\b"))!= NULL) {
            if (word.length > strlen(word.word)) {
                word.length = strlen(word.word);
            }
        }

        // Print the length of the longest word
        printf("\nLongest word: %s (length: %d)\n\n", word.word, word.length);
    }

    // Close the ebook file
    fclose(fp);

    return 0;
}