//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10
#define NUM_TESTS 10

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

struct word words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (length > 0 && length <= MAX_WORD_LENGTH) {
            strcpy(words[num_words].word, line);
            words[num_words].length = length;
            num_words++;
        }
    }
    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < num_words - 1; i++) {
        int j = rand() % num_words;
        struct word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

void run_test() {
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    srand(time(NULL));
    shuffle_words();
    for (int i = 0; i < NUM_TESTS; i++) {
        struct word *current_word = &words[i % num_words];
        printf("Word %d: ", i + 1);
        for (int j = 0; j < current_word->length; j++) {
            printf("*");
        }
        printf("\n");
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, current_word->word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
    }
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Accuracy: %.2f%%\n", (float)correct / total * 100);
}

int main() {
    load_words();
    run_test();
    return 0;
}