//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 500
#define MAX_WORD_LENGTH 10
#define MIN_WPM 10
#define MAX_WPM 100

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_random_word(struct word *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word->word[i] = 'a' + rand() % 26;
    }
    word->length = i;
}

int main() {
    int num_words, num_correct, num_incorrect, total_time;
    int wpm, accuracy;
    struct word words[MAX_WORDS];
    char input[MAX_WORD_LENGTH];
    int i, j, correct = 0;

    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n");

    printf("How many words would you like to type? (Between %d and %d)\n", MIN_WPM, MAX_WPM);
    scanf("%d", &num_words);

    printf("Enter your name: ");
    scanf("%s", input);

    printf("Hello, %s! Let's get started!\n", input);

    for (i = 0; i < num_words; i++) {
        generate_random_word(&words[i]);
    }

    total_time = 0;
    for (i = 0; i < num_words; i++) {
        printf("Type the following word: %s\n", words[i].word);
        fflush(stdout);
        for (j = 0; j < words[i].length; j++) {
            if (scanf("%c", &input[j])!= 1) {
                printf("Invalid input. Please try again.\n");
                fflush(stdout);
                j--;
            }
        }
        input[words[i].length] = '\0';
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            num_incorrect++;
        }
        total_time += words[i].length;
    }

    wpm = (int) (MAX_WPM * num_words / (total_time / num_words));
    accuracy = (int) ((float) correct / num_words * 100);

    printf("You typed %d words with a speed of %d WPM and an accuracy of %d%%!\n", num_words, wpm, accuracy);

    return 0;
}