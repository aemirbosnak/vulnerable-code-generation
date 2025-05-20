//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
/*
 * This is an imaginative C program that checks the spelling of words entered by the user.
 * The program checks each word in a sentence to see if it matches any words stored in a dictionary file.
 * If a word is not found in the dictionary, the program suggests a possible replacement for the misspelled word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length for a word
#define MAX_WORD_LENGTH 30

// define the maximum size for the dictionary
#define MAX_DICTIONARY_SIZE 50000

// function to remove '\n' from a string
void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {

    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    FILE *fp;
    char filepath[] = "dictionary.txt";

    // read the dictionary file into memory
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file!");
        exit(1);
    }
    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, fp) != NULL && i < MAX_DICTIONARY_SIZE) {
        remove_newline(word);
        strcpy(dictionary[i], word);
        i++;
    }
    fclose(fp);

    // prompt the user to enter a sentence
    printf("Enter a sentence: ");
    char sentence[MAX_DICTIONARY_SIZE * MAX_WORD_LENGTH];
    fgets(sentence, MAX_DICTIONARY_SIZE * MAX_WORD_LENGTH, stdin);
    remove_newline(sentence);

    // split the sentence into words
    char *word_ptr;
    char *delim = " ";
    word_ptr = strtok(sentence, delim);
    while (word_ptr != NULL) {

        // check if the word is in the dictionary
        int found = 0;
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(word_ptr, dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }

        // suggest a replacement if the word is misspelled
        if (!found) {
            printf("'%s' is misspelled. Did you mean '", word_ptr);
            int k;
            int word_length = strlen(word_ptr);
            for (k = 0; k < i; k++) {
                int diff = 0;
                int l;
                for (l = 0; l < word_length; l++) {
                    if (word_ptr[l] != dictionary[k][l]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    printf("%s'?", dictionary[k]);
                    break;
                }
            }
            printf("\n");
        }

        // get the next word in the sentence
        word_ptr = strtok(NULL, delim);
    }

    return 0;
}