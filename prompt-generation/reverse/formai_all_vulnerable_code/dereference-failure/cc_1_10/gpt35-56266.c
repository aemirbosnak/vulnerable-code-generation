//FormAI DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define a custom error message function
void error(char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check that the user has provided the correct arguments
    if (argc != 3) {
        error("Usage: cspell <wordfile> <testfile>");
    }

    // Open the word file and read its contents into memory
    FILE *wordfile = fopen(argv[1], "r");
    if (!wordfile) {
        error("Cannot open word file");
    }
    char **words = malloc(sizeof(char*) * 10000);
    int nwords = 0;
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), wordfile)) {
        words[nwords++] = strdup(buffer);
    }
    fclose(wordfile);

    // Open the test file and scan it for misspelled words
    FILE *testfile = fopen(argv[2], "r");
    if (!testfile) {
        error("Cannot open test file");
    }
    int linenumber = 1;
    while (fgets(buffer, sizeof(buffer), testfile)) {
        char *line = strdup(buffer);
        char *word = strtok(line, " ,\n");
        while (word) {
            int found = 0;
            // Strip any punctuation from the word
            char *lastchar = word + strlen(word) - 1;
            if (ispunct(*lastchar)) {
                *lastchar = '\0';
            }
            // Convert the word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            // Search for the word in the word list
            for (int i = 0; i < nwords; i++) {
                if (strcmp(words[i], word) == 0) {
                    found = 1;
                    break;
                }
            }
            // Print an error message if the word is not found
            if (!found) {
                printf("Error found in line %d: %s\n", linenumber, word);
            }
            word = strtok(NULL, " ,\n");
        }
        free(line);
        linenumber++;
    }
    fclose(testfile);

    // Free the memory used by the word list
    for (int i = 0; i < nwords; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}