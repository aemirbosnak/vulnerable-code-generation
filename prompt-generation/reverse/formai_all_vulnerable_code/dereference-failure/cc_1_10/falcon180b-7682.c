//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to check if a word is in the dictionary
int is_word(const char* word) {
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary_file)!= NULL) {
        if (strcmp(line, word) == 0) {
            fclose(dictionary_file);
            return 1;
        }
    }

    fclose(dictionary_file);
    return 0;
}

// Function to check if a sentence is in the dictionary
int is_sentence(const char* sentence) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        if (!is_word(token)) {
            return 0;
        }
        token = strtok(NULL, " ");
    }
    return 1;
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        if (is_sentence(line)) {
            printf("%s\n", line);
        } else {
            printf("Error: %s\n", line);
        }
    }

    fclose(input_file);
    return 0;
}