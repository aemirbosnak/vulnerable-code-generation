//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100  // maximum length of a line in the input file
#define MAX_WORD_LENGTH 20   // maximum length of a word in the input file
#define DICTIONARY_PATH "dictionary.txt"   // path to the dictionary file
#define ERROR_COLOR "\x1b[31m"   // ANSI escape code for red color
#define RESET_COLOR "\x1b[0m"   // ANSI escape code for resetting the color

// function to check if a word is present in the dictionary
int checkWord(char* word, char** dictionary, int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;   // word found in dictionary
        }
    }
    return 0;   // word not found in dictionary
}

int main(int argc, char* argv[]) {
    // open the input file
    if (argc < 2) {
        printf("Please provide the input file path.\n");
        return 1;
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Could not open the input file.\n");
        return 1;
    }

    // load the dictionary file into memory
    FILE* dictionaryFile = fopen(DICTIONARY_PATH, "r");
    if (dictionaryFile == NULL) {
        printf("Could not open the dictionary file.\n");
        fclose(inputFile);
        return 1;
    }
    char** dictionary = (char**)malloc(sizeof(char*) * MAX_LINE_LENGTH);   // allocate memory for storing the dictionary words
    int dictionarySize = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, dictionaryFile) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';   // remove the newline character from the line
        dictionary[dictionarySize] = (char*)malloc(sizeof(char) * MAX_WORD_LENGTH);   // allocate memory for storing a dictionary word
        strcpy(dictionary[dictionarySize], line);   // copy the word into the dictionary array
        dictionarySize++;
    }
    fclose(dictionaryFile);

    // read each line from the input file and check for spelling errors
    int lineNo = 1;
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        char* word = strtok(line, " \r\n");   // get the first word from the line
        int wordNo = 1;
        while (word != NULL) {
            if (!checkWord(word, dictionary, dictionarySize)) {
                printf(ERROR_COLOR "Line %d, word %d: %s\n" RESET_COLOR, lineNo, wordNo, word);
            }
            word = strtok(NULL, " \r\n");   // get the next word from the line
            wordNo++;
        }
        lineNo++;
    }

    // free the memory allocated for dictionary words
    for (int i = 0; i < dictionarySize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    // close the input file
    fclose(inputFile);

    return 0;
}