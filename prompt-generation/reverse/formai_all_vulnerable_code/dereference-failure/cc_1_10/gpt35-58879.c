//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WORD_LEN 15 // length of longest word in dictionary

// function prototypes
void get_dictionary(char **dictionary, char *filename);
bool spell_check(char *word, char **dictionary);

int main(int argc, char *argv[]) {
    // initialization
    char *dictionary[99000];
    char *dict_file = "dictionary.txt";
    char *line = (char *) malloc(sizeof(char) * WORD_LEN);
    int num_misspelled = 0;
    
    // fill dictionary with words from file
    get_dictionary(dictionary, dict_file);
    
    // spell check each word in input file
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (fgets(line, WORD_LEN, fp)) {
        // remove newline character if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        // convert word to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }
        // check if word is spelled correctly
        bool is_correct = spell_check(line, dictionary);
        if (!is_correct) {
            printf("%s\n", line);
            num_misspelled++;
        }
    }
    fclose(fp);
    
    printf("\n%d misspelled words found\n", num_misspelled);
    
    // free memory allocated for dictionary and line
    for (int i = 0; i < 99000; i++) {
        free(dictionary[i]);
    }
    free(line);
    
    return 0;
}

/*
 * Fills the given dictionary array with words from the file with the given filename
 */
void get_dictionary(char **dictionary, char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char *line = (char *) malloc(sizeof(char) * WORD_LEN);
    int index = 0;
    while (fgets(line, WORD_LEN, fp)) {
        // remove newline character if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        // copy word into dictionary array
        dictionary[index] = (char *) malloc(sizeof(char) * strlen(line) + 1);
        strcpy(dictionary[index], line);
        index++;
    }
    fclose(fp);
    free(line);
}

/*
 * Returns true if the given word is spelled correctly (appears in the dictionary), false otherwise
 */
bool spell_check(char *word, char **dictionary) {
    int low = 0;
    int high = 98999;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(word, dictionary[mid]);
        if (cmp == 0) {
            return true;
        } else if (cmp > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}