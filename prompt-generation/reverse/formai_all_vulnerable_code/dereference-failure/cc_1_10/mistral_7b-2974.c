//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHAR 256
#define MAX_WORD 10000

// Function to check if character is alphabets or not
int isAlphabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to count the frequency of a word
void countWordFrequency(char **words, int *freq, int *counter, int wordLength) {
    int i;
    for (i = 0; i < wordLength; i++) {
        if (isAlphabet(words[*counter][i])) {
            int index = (tolower(words[*counter][i]) - 'a');
            freq[index]++;
        }
    }
    (*counter)++;
}

// Function to split the given string into words
void splitIntoWords(char str[], char **words, int *counter) {
    int i = 0, j = 0, wordLength = 0;
    char word[MAX_WORD];

    while (str[i] != '\0') {
        if (isAlphabet(str[i])) {
            if (j >= wordLength) {
                wordLength += 10;
                words = (char **)realloc(words, sizeof(char *) * (*counter + 1) * (wordLength / 10 + 2));
                strcpy(word, "");
            }
            word[j++] = str[i];
        } else if (j > 0) {
            word[j] = '\0';
            countWordFrequency(words, NULL, counter, strlen(word));
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        word[j] = '\0';
        countWordFrequency(words, NULL, counter, strlen(word));
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage : %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char str[MAX_CHAR];
    char **words = NULL;
    int counter = 0, i, wordLength = 0;
    int freq[MAX_CHAR];
    memset(freq, 0, sizeof(freq));

    while (fgets(str, sizeof(str), file) != NULL) {
        splitIntoWords(str, words, &counter);
    }

    fclose(file);

    printf("Frequency of each character in the given text:\n");
    for (i = 0; i < MAX_CHAR; i++) {
        if (isalnum(i))
            printf("%c : %d\n", i, freq[i]);
    }

    free(words);
    return 0;
}