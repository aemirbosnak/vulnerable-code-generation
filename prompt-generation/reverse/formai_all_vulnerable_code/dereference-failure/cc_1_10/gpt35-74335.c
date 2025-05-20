//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50  // maximum length of a word 
#define MAX_NUM_WORDS 1000  // maximum number of words in the dictionary

// Configurable options:
#define DICTIONARY_FILE "dictionary.txt" // file containing the dictionary
#define INPUT_FILE "input.txt" // file containing the text to be spell-checked
#define OUTPUT_FILE "output.txt" // file to write the corrected text to
#define DELIMITERS " \t\n.,:;!?-" // characters that indicate the end of a word

void to_lowercase(char *word) {
    // converts a word to lowercase
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }
}

int is_valid_word(char *word, char **dictionary, int num_words) {
    // checks if a word is valid by comparing it to the dictionary
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // word is valid
        }
    }
    return 0; // word is not valid
}

void spell_check(char **dictionary, int num_words, char *input_filename, char *output_filename) {
    // spell-checks the input file and writes the corrected text to the output file
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(input_file, "%s", word) != EOF) {
        // remove delimiters at beginning and end of word
        while (strchr(DELIMITERS, word[0]) != NULL) {
            memmove(word, word+1, strlen(word));
        }
        while (strchr(DELIMITERS, word[strlen(word)-1]) != NULL) {
            word[strlen(word)-1] = '\0';
        }
        if (!is_valid_word(word, dictionary, num_words)) {
            // word is not valid, so correct it
            to_lowercase(word); // convert to lowercase for easier comparison
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, dictionary[j]) == 0) {
                    // found a valid replacement word, so use it
                    fprintf(output_file, "%s ", dictionary[j]);
                    break;
                }
            }
            if (j == num_words) {
                // did not find a valid replacement word, so keep original word
                fprintf(output_file, "%s ", word);
            }
        } else {
            // word is already valid, so keep it
            fprintf(output_file, "%s ", word);
        }
        i++;
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    // read the dictionary file into an array of words
    char *dictionary[MAX_NUM_WORDS];
    int num_words = 0;
    FILE *dictionary_file = fopen(DICTIONARY_FILE, "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word) != EOF) {
        dictionary[num_words] = malloc(strlen(word) + 1); // allocate space for the word
        strcpy(dictionary[num_words], word);
        num_words++;
    }
    fclose(dictionary_file);

    // spell-check the input file and write the corrected text to the output file
    spell_check(dictionary, num_words, INPUT_FILE, OUTPUT_FILE);

    // free memory allocated for dictionary
    for (int i = 0; i < num_words; i++) {
        free(dictionary[i]);
    }

    return 0;
}