//Falcon-180B DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 100
#define MAX_WORDS 50

char *get_word(char *line) {
    char *word = malloc(MAX_CHARS * sizeof(char));
    int len = 0;
    while (isspace(*line)) {
        line++;
    }
    while (!isspace(*line)) {
        if (len >= MAX_CHARS - 1) {
            printf("Error: word is too long\n");
            exit(1);
        }
        word[len] = tolower(*line);
        line++;
        len++;
    }
    word[len] = '\0';
    return word;
}

int is_palindrome(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i]!= word[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char line[MAX_CHARS];
    printf("Enter a sentence: ");
    fgets(line, MAX_CHARS, stdin);
    int num_words = 0;
    char *words[MAX_WORDS];
    char *word = strtok(line, " ");
    while (word!= NULL && num_words < MAX_WORDS) {
        words[num_words] = get_word(word);
        word = strtok(NULL, " ");
        num_words++;
    }
    printf("Number of words: %d\n", num_words);
    for (int i = 0; i < num_words; i++) {
        if (is_palindrome(words[i])) {
            printf("Palindrome found: %s\n", words[i]);
        }
    }
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    return 0;
}