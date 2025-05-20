//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITERS " \t\n\r,"

// Function to reverse the string pointed to by str
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to split a line into words using delimiters
int split_line(char *line, char **words, int max_words) {
    int num_words = 0;
    char *token = strtok(line, WORD_DELIMITERS);

    while (token != NULL && num_words < max_words) {
        words[num_words++] = token;
        token = strtok(NULL, WORD_DELIMITERS);
    }

    return num_words;
}

// Function to reverse the words in an array of words
void reverse_words(char **words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        reverse_string(words[i]);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *words[MAX_LINE_LENGTH / sizeof(char *)];
    int num_words;

    printf("Enter a line: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    num_words = split_line(line, words, MAX_LINE_LENGTH / sizeof(char *));

    reverse_words(words, num_words);

    printf("Reversed words: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    free(words);

    return 0;
}