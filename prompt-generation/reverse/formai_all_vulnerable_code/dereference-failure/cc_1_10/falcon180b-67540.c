//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    char input[MAX_STRING_LENGTH];
    char *token;
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter a string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input string
    token = strtok(input, " ");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            return 1;
        }
        words[num_words].word = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(words[num_words].word, token);
        words[num_words].length = strlen(token);
        num_words++;
        token = strtok(NULL, " ");
    }

    // Sort words by length
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].length > words[j].length) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print sorted words
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}