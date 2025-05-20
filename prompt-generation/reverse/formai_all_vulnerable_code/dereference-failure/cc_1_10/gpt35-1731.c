//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// function to convert all characters to lower case
void toLowerCase(char *s) {
    int i;
    for (i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

// function to remove punctuation from a string
void removePunctuation(char *s) {
    int i;
    for (i = 0; s[i]; i++) {
        if (!isalpha(s[i]) && !isspace(s[i])) {
            s[i] = ' ';
        }
    }
}

// function to count the frequency of each word in a string
void countWords(char *str,int *freq) {
    char *word;
    int i = 0;
    while ((word = strtok(str, " ")) != NULL) { // tokenize string on spaces
        toLowerCase(word); // convert word to lower case
        freq[i] = 1; // set frequency of new word to 1
        int j;
        for (j = 0; j < i; j++) { // compare word to all previous words
            if (strcmp(word, str[j]) == 0) { // if word is found, increment frequency and set to empty string
                ++freq[j];
                *word = '\0';
                break;
            }
        }
        if (*word != '\0') {
            str[i++] = word; // add new word to string
        }
        str = NULL; // set strtok to NULL to get next token
    }
}

int main() {
    char text[MAX_SIZE], copy[MAX_SIZE];
    int frequency[MAX_SIZE/2] = {0}; // array to store word frequencies
    printf("Enter text:\n");
    fgets(text, MAX_SIZE, stdin); // get user input
    strcpy(copy, text); // create a copy to preserve original input
    removePunctuation(copy); // remove punctuation from copy
    countWords(copy, frequency); // count word frequency
    printf("\nWord Frequency:\n");
    int i;
    for (i = 0; copy[i]; i++) {
        if (frequency[i]) { // if frequency is non-zero
            printf("%s: %d\n", copy[i], frequency[i]); // print word and frequency
        }
    }
    return 0;
}