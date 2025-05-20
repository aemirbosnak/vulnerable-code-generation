//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_SIZE 50

// Function to check if two strings are equal, ignoring case
int str_equal_ignore_case(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    for (size_t i = 0; i < len1 && i < len2; i++) {
        if (tolower((unsigned char)str1[i]) != tolower((unsigned char)str2[i])) {
            return 0;
        }
    }

    return len1 == len2;
}

// Function to trim whitespace from the beginning and end of a string
void trim_whitespace(char *str) {
    size_t start = 0;
    size_t end = strlen(str) - 1;

    while (isspace((unsigned char)str[start])) {
        start++;
    }

    while (isspace((unsigned char)str[end]) && end > start) {
        end--;
    }

    size_t len = end - start + 1;
    if (len > WORD_SIZE) {
        len = WORD_SIZE;
        str[len] = '\0';
    }

    memmove(str, str + start, len);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file 'input.txt'\n");
        return 1;
    }

    int num_words = 0;
    char words[MAX_WORDS][WORD_SIZE];

    while (fgets(words[num_words], WORD_SIZE, file)) {
        trim_whitespace(words[num_words]);

        int duplicate = 0;
        for (int i = 0; i < num_words && !duplicate; i++) {
            if (str_equal_ignore_case(words[i], words[num_words])) {
                duplicate = 1;
            }
        }

        if (!duplicate) {
            num_words++;
        }
    }

    fclose(file);

    if (num_words > 0) {
        qsort(words, num_words, sizeof(words[0]), strcmp);

        printf("Unique words in alphabetical order:\n");
        for (int i = 0; i < num_words; i++) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}