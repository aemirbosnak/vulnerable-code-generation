//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);

    int spam_score = calculate_spam_score(words);

    if (spam_score > 50) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}

int tokenize(char *text, char **words) {
    int num_words = 0;
    char *word = strtok(text, " ");

    while (word) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    return num_words;
}

int calculate_spam_score(char **words) {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(words[i], "free") == 0) {
            score++;
        }
        if (strcmp(words[i], "lottery") == 0) {
            score++;
        }
        if (strcmp(words[i], "prize") == 0) {
            score++;
        }
    }

    return score;
}