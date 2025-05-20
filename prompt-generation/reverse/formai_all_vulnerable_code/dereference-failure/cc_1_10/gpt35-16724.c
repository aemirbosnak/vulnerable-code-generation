//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void to_lower_case(char* str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void print_word_count(int count[MAX_WORDS], char* words[MAX_WORDS], int total_words) {
    for (int i = 0; i < total_words; i++) {
        printf("%10s : %3d\n", words[i], count[i]);
    }
    printf("Total words: %d\n", total_words);
}

int main() {
    char input_str[MAX_WORDS * MAX_WORD_LENGTH];
    char* words[MAX_WORDS];
    int count[MAX_WORDS];
    int total_words = 0;

    printf("Enter text: ");
    fgets(input_str, MAX_WORDS * MAX_WORD_LENGTH, stdin);

    char* token = strtok(input_str, " \t\n");

    while (token != NULL) {
        to_lower_case(token);

        int flag = 0;
        for (int i = 0; i < total_words; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            words[total_words] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(words[total_words], token);
            count[total_words] = 1;
            total_words++;
        }

        token = strtok(NULL, " \t\n");
    }

    print_word_count(count, words, total_words);

    for (int i = 0; i < total_words; i++) {
        free(words[i]);
    }

    return 0;
}