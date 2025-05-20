//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 1000
#define WORD_LENGTH 5

char *words[NUM_WORDS];
int word_lengths[NUM_WORDS];

// Function to generate random words
void generate_words() {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        words[i] = (char *) malloc(WORD_LENGTH + 1);
        word_lengths[i] = rand() % WORD_LENGTH + 1;
        int j;
        for (j = 0; j < word_lengths[i]; j++) {
            int k = rand() % 26 + 'a';
            words[i][j] = k;
        }
        words[i][word_lengths[i]] = '\0';
    }
}

// Function to print the words to be typed
void print_words() {
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to check if the typed word is correct
int check_word(char *typed_word, char *correct_word) {
    int i;
    for (i = 0; i < strlen(correct_word); i++) {
        if (typed_word[i]!= correct_word[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the WPM
double calculate_wpm(int num_words, double time_taken) {
    return (double) num_words / (time_taken / 60);
}

int main() {
    srand(time(NULL));
    generate_words();
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("Type %s: ", words[i]);
        char typed_word[WORD_LENGTH + 1];
        scanf("%s", typed_word);
        if (check_word(typed_word, words[i])) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }
    double wpm = calculate_wpm(NUM_WORDS, (double) clock() / CLOCKS_PER_SEC);
    printf("Your typing speed is %.2f WPM.\n", wpm);
    return 0;
}