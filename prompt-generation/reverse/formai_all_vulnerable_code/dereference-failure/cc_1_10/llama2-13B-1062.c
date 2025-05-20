//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_WORD_LENGTH 256
#define MAX_SENTENCE_LENGTH 1024
#define MIN_SENTENCE_LENGTH 5

// Function to generate a random sentence
void generate_sentence(char *buffer) {
    int word_count = rand() % 5 + 2;
    int i;

    for (i = 0; i < word_count; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char word[word_length];
        int j;

        for (j = 0; j < word_length; j++) {
            word[j] = 'a' + (rand() % 26);
        }
        strcat(buffer, word);
        if (i < word_count - 1) {
            strcat(buffer, " ");
        }
    }
}

// Function to check if a sentence is valid
int is_valid_sentence(char *sentence) {
    int i;
    for (i = 0; i < strlen(sentence); i++) {
        if (!isalnum(sentence[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    generate_sentence(sentence);

    // Check if the sentence is valid
    if (!is_valid_sentence(sentence)) {
        printf("The sentence is not valid\n");
        return 1;
    }

    printf("The sentence is: %s\n", sentence);
    return 0;
}