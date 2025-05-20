//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CHARS 1000
#define MAX_WORDS 100

char input_string[MAX_CHARS];
int num_words;
char *words[MAX_WORDS];

void read_string() {
    printf("Enter a string: ");
    fgets(input_string, MAX_CHARS, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';
}

void tokenize_string() {
    char *token = strtok(input_string, " ");
    int i = 0;

    while (token!= NULL && i < MAX_WORDS) {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    num_words = i;
}

void reverse_string(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }

    rev[len] = '\0';

    printf("Reversed string: %s\n", rev);
}

void count_vowels() {
    int count = 0;

    for (int i = 0; i < num_words; i++) {
        int j = 0;

        while (words[i][j]!= '\0') {
            if (tolower(words[i][j]) == 'a' || tolower(words[i][j]) == 'e' || tolower(words[i][j]) == 'i' || tolower(words[i][j]) == 'o' || tolower(words[i][j]) == 'u') {
                count++;
            }

            j++;
        }
    }

    printf("Total number of vowels: %d\n", count);
}

void main() {
    read_string();
    tokenize_string();
    reverse_string(input_string);
    count_vowels();
}