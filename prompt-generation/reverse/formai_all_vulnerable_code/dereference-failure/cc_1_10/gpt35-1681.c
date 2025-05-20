//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define IN 1
#define OUT 0

// Function to check if a character is a valid alphabet
int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert a string to lower case
void to_lower_case(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char c, word[MAX_WORD_LENGTH];
    int state = OUT, word_length = 0;
    int char_count = 0, word_count = 0;
    int *frequency = (int*) calloc(26, sizeof(int));

    printf("Enter some text:\n");
    while ((c = getchar()) != EOF) {
        char_count++;

        if (is_alpha(c)) {
            state = IN;
            word[word_length++] = c;
        } else {
            if (state == IN) {
                state = OUT;
                word[word_length] = '\0';
                to_lower_case(word);
                frequency[word[0] - 'a']++;
                word_count++;
                word_length = 0;
            }
        }
    }

    printf("\nWord Frequency:\n");
    printf("----------------\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }

    printf("\nTotal characters: %d\n", char_count);
    printf("Total words: %d\n", word_count);

    free(frequency);
    return 0;
}