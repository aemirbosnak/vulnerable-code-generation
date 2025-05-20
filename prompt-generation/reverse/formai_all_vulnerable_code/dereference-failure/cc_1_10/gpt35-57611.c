//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the number of files to be created
#define NUM_FILES 3

// Declare the file pointers
FILE *files[NUM_FILES];

// Define the decentralized function to create the files
void create_files() {
    for (int i=0; i<NUM_FILES; i++) {
        char filename[MAX_WORD_LENGTH];
        sprintf(filename, "file%d.txt", i+1);
        files[i] = fopen(filename, "w");
    }
}

// Define the decentralized function to add words to the files
void add_words(char *word) {
    // Get the index of the file to add the word to
    int index = strlen(word) % NUM_FILES;
    // Add the word to the file
    fprintf(files[index], "%s\n", word);
}

// Define the main function
int main() {
    // Create the files
    create_files();

    // Open the input file for reading
    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read each word from the input file and add it to the appropriate file
    char word[MAX_WORD_LENGTH];
    while (fscanf(infile, "%s", word) == 1) {
        add_words(word);
    }

    // Close the input file
    fclose(infile);

    // Close the files
    for (int i=0; i<NUM_FILES; i++) {
        fclose(files[i]);
    }

    return 0;
}