//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} Word;

void generate_word(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
}

int main() {
    srand(time(NULL));
    Word words[MAX_WORDS];
    int num_words = 0;
    char input[MAX_WORD_LENGTH];

    for (int i = 0; i < MAX_WORDS; i++) {
        generate_word(words[i].word, rand() % 10 + 1);
        num_words++;
    }

    printf("Words to type:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%d. %s\n", i+1, words[i].word);
    }

    int correct_count = 0;
    int total_count = 0;

    printf("\nStart typing:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    while (strcmp(input, "done")!= 0) {
        int word_index = -1;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].word) == 0) {
                word_index = i;
                break;
            }
        }

        if (word_index >= 0) {
            correct_count++;
        }

        total_count++;
        printf("\nWord %d:\n", total_count);
        fgets(input, MAX_WORD_LENGTH, stdin);
    }

    printf("\nResults:\n");
    printf("Correct words: %d\n", correct_count);
    printf("Total words: %d\n", total_count);
    printf("Accuracy: %.2f%%\n", (float)correct_count / total_count * 100);

    return 0;
}