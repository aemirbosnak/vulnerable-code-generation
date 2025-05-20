//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function returns the total number of words in a given string
int wordCount(char *str) {
    int count = 0, i = 0;
    char prev = ' ';

    while (str[i] != '\0') {
        if ((prev == ' ' || prev == '\n' || prev == '\t') && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')) {
            count++;
        }
        prev = str[i];
        i++;
    }

    return count;
}

// This function splits the input string into individual words
char** splitWords(char *str, int totalWords) {
    char **words = malloc(sizeof(char*) * totalWords);
    int i = 0;
    char *word = strtok(str, " \n\t");

    while (word != NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " \n\t");
    }

    return words;
}

int main() {
    char inputString[1000];
    int totalWords;
    printf("Enter a string: ");
    fgets(inputString, 1000, stdin);

    totalWords = wordCount(inputString);
    char **words = splitWords(inputString, totalWords);
    printf("Number of words: %d\n", totalWords);
    printf("Words:\n");

    for (int i = 0; i < totalWords; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}