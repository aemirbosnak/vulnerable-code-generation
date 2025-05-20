//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_PER_PAGE 25
#define MAGIC_NUMBER 42

// Function to count the number of words in a string
int wordCount(const char* str) {
    int words = 0;
    char* p = strtok(str, " ");
    while (p != NULL && *p != '\0') {
        words++;
        p = strtok(NULL, " ");
    }
    return words;
}

// Function to print the word count and other stats
void printStats(int words, int pages) {
    printf("Word Count: %d\n", words);
    printf("Pages: %d\n", pages);
    printf("Average Words per Page: %d\n", words / pages);
    printf("Magic Number: %d\n", MAGIC_NUMBER);
}

int main() {
    // Get the input file name from the user
    printf("Enter the file name: ");
    char filename[100];
    scanf("%s", filename);

    // Open the input file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Get the file size in bytes
    long filesize = ftell(file);
    if (filesize == -1L) {
        printf("Error getting file size\n");
        return 1;
    }

    // Calculate the number of words in the file
    int words = 0;
    char buffer[1024];
    while (fread(buffer, 1, 1024, file) > 0) {
        words += wordCount(buffer);
    }

    // Calculate the number of pages needed
    int pages = ceil(filesize / (1024 * 1024 * WORDS_PER_PAGE));

    // Print the stats
    printStats(words, pages);

    // Close the file
    fclose(file);

    return 0;
}