//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_LENGTH 50

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int count_words(char *str, int *words) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
        if (count >= MAX_WORDS) {
            *words = count;
            return 1;
        }
    }
    *words = count + 1;
    return 0;
}

void reverse_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

int main() {
    char input[MAX_LENGTH];
    char *words[MAX_WORDS];
    int num_words;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (count_words(input, &num_words) == 1) {
        printf("Maximum number of words allowed is %d.\n", MAX_WORDS);
        return 1;
    }

    int size = sizeof(words) / sizeof(words[0]);
    char *token;

    for (int i = 0, index = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            words[index] = malloc(i - index);
            strncpy(words[index], input + index, i - index);
            index++;
            i += strlen(words[index]) + 1;
        }
    }

    words[num_words - 1] = malloc(strlen(input) - (num_words - 1) * strlen(words[num_words - 1]) - (num_words - 1));
    strcpy(words[num_words - 1], input + strlen(input) - (num_words - 1) * strlen(words[num_words - 1]));

    for (int i = 0; i < num_words; i++) {
        reverse_word(words[i]);
        printf("Reversed word %d: %s\n", i + 1, words[i]);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}