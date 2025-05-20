//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the frequency of each word */
void getFrequency(char *text, char **words, int *freq, int n) {
    int i, j;
    char *str, *token;
    /* Copy the text to a mutable string */
    str = malloc(strlen(text) + 1);
    strcpy(str, text);
    /* Tokenize the string and compare with each word */
    token = strtok(str, " ");
    while (token != NULL) {
        for (i = 0; i < n; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
            }
        }
        token = strtok(NULL, " ");
    }
    free(str);
}

/* Function to normalize the words in the text */
void normalizeText(char **words, int n) {
    int i, j;
    char *str;
    /* Allocate memory for the longest word in the array */
    str = malloc(strlen(words[0]) + 1);
    /* Copy each word to str, normalize it, and copy back */
    for (i = 0; i < n; i++) {
        strcpy(str, words[i]);
        for (j = 0; str[j]; j++) {
            str[j] = tolower(str[j]);
        }
        strcpy(words[i], str);
    }
    free(str);
}

int main() {
    char text[500], *token, *str;
    char *keywords[10] = {"peaceful", "calm", "relaxing", "tranquil", "serene", "harmonious", "pleasant", "placid", "gentle", "quiet"};
    int frequency[10] = {0};
    int i, max, index;
    /* Input the text */
    printf("Enter the text: ");
    fgets(text, 500, stdin);
    /* Tokenize the text and normalize the words */
    str = malloc(strlen(text) + 1);
    strcpy(str, text);
    i = 0;
    token = strtok(str, " .,!?\n");
    while (token != NULL) {
        keywords[i] = malloc(strlen(token) + 1);
        strcpy(keywords[i], token);
        token = strtok(NULL, " .,!?\n");
        i++;
    }
    normalizeText(keywords, 10);
    /* Calculate the frequency of each keyword */
    getFrequency(text, keywords, frequency, 10);
    /* Find the keyword with the maximum frequency */
    max = frequency[0];
    index = 0;
    for (i = 1; i < 10; i++) {
        if (frequency[i] > max) {
            max = frequency[i];
            index = i;
        }
    }
    /* Print the most frequent keyword */
    printf("The most frequent keyword is %s.\n", keywords[index]);
    return 0;
}