//Falcon-180B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function to compare two strings in a case-insensitive manner
int compare_strings(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;

    while (*str1 && *str2) {
        if (tolower(*str1)!= tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }

    if (*str1) {
        return 1;
    } else if (*str2) {
        return -1;
    } else {
        return 0;
    }
}

// Function to split a string into words
void split_string(char *str, char **words) {
    char *token = strtok(str, " ");
    int word_count = 0;

    while (token!= NULL) {
        if (word_count >= MAX_WORDS) {
            printf("Error: Too many words in input string.\n");
            exit(1);
        }

        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        words[word_count] = malloc(strlen(token) + 1);
        if (words[word_count] == NULL) {
            printf("Error: Out of memory.\n");
            exit(1);
        }

        strcpy(words[word_count], token);
        word_count++;

        token = strtok(NULL, " ");
    }
}

// Function to sort an array of strings
void sort_words(char **words, int word_count) {
    qsort(words, word_count, sizeof(char *), compare_strings);
}

// Function to print an array of strings
void print_words(char **words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    char input_string[1000];
    printf("Enter a string to sort: ");
    fgets(input_string, sizeof(input_string), stdin);

    char *words[MAX_WORDS];
    split_string(input_string, words);

    sort_words(words, strlen(input_string));

    print_words(words, strlen(input_string));

    for (int i = 0; i < strlen(input_string); i++) {
        free(words[i]);
    }

    return 0;
}