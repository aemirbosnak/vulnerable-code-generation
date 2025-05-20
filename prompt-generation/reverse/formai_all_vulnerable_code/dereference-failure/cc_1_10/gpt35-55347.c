//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_FILE_LENGTH 10000

/* Returns 1 if the word is spelled correctly, 0 otherwise */
int check_word_spelling(char *word) {
    /* open file containing correctly spelled words */
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        exit(1);
    }

    /* read in file contents and split into individual words */
    char file_contents[MAX_FILE_LENGTH];
    fread(file_contents, 1, MAX_FILE_LENGTH, file);
    char *word_list[MAX_FILE_LENGTH];
    char *temp_str = strtok(file_contents, " \n");
    int i = 0;
    while (temp_str != NULL) {
        word_list[i++] = temp_str;
        temp_str = strtok(NULL, " \n");
    }

    /* compare input word to each word in list */
    int num_words = i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, word_list[i]) == 0) {
            return 1;
        }
    }

    /* input word not found in list */
    return 0;
}

/* Returns a pointer to an array of misspelled words */
char **check_spelling(char *input_text, int *num_misspelled) {
    /* allocate memory for output array */
    char **misspelled_words = (char **)malloc(sizeof(char *));
    if (misspelled_words == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        exit(1);
    }
    *num_misspelled = 0;

    /* split input text into individual words and check spelling */
    char *word_list[MAX_FILE_LENGTH];
    char *temp_str = strtok(input_text, " \n");
    int i = 0;
    while (temp_str != NULL) {
        word_list[i++] = temp_str;
        temp_str = strtok(NULL, " \n");
    }
    int num_words = i;
    for (i = 0; i < num_words; i++) {
        /* remove non-alphabetic characters from word */
        int j = 0;
        char cleaned_word[MAX_WORD_LENGTH];
        while (word_list[i][j] != '\0') {
            if (isalpha(word_list[i][j])) {
                cleaned_word[j] = tolower(word_list[i][j]);
            }
            j++;
        }
        cleaned_word[j] = '\0';

        /* check spelling of cleaned word */
        if (!check_word_spelling(cleaned_word)) {
            /* add misspelled word to output array */
            int curr_num_misspelled = *num_misspelled;
            misspelled_words = (char **)realloc(misspelled_words, (curr_num_misspelled + 1) * sizeof(char *));
            if (misspelled_words == NULL) {
                fprintf(stderr, "Error: could not allocate memory\n");
                exit(1);
            }
            misspelled_words[curr_num_misspelled] = (char *)malloc(strlen(word_list[i]) + 1);
            if (misspelled_words[curr_num_misspelled] == NULL) {
                fprintf(stderr, "Error: could not allocate memory\n");
                exit(1);
            }
            strcpy(misspelled_words[curr_num_misspelled], word_list[i]);
            (*num_misspelled)++;
        }
    }

    /* return pointer to array of misspelled words */
    return misspelled_words;
}

int main() {
    /* read in input text from file */
    FILE *file = fopen("input_text.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        exit(1);
    }
    char input_text[MAX_FILE_LENGTH];
    fread(input_text, 1, MAX_FILE_LENGTH, file);

    /* check spelling of input text */
    int num_misspelled;
    char **misspelled_words = check_spelling(input_text, &num_misspelled);

    /* print out misspelled words */
    printf("Misspelled words (%d total):\n", num_misspelled);
    int i;
    for (i = 0; i < num_misspelled; i++) {
        printf("%s\n", misspelled_words[i]);
    }

    /* free memory */
    for (i = 0; i < num_misspelled; i++) {
        free(misspelled_words[i]);
    }
    free(misspelled_words);

    return 0;
}