//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_COUNT 10
#define WORD_LENGTH_MIN 5
#define WORD_LENGTH_MAX 20

typedef struct Word {
    char *word;
    int length;
} Word;

void generate_words(Word **words, int count) {
    int i;
    for (i = 0; i < count; ++i) {
        int length = rand() % (WORD_LENGTH_MAX - WORD_LENGTH_MIN + 1) + WORD_LENGTH_MIN;
        *words = realloc(*words, sizeof(Word) * (i + 2));
        (*words + i + 1)->word = malloc(length + 1);
        (*words + i + 1)->length = length;
        for (int j = 0; j <= length; ++j) {
            (*words + i + 1)->word[j] = 'a' + rand() % 26;
        }
        (*words + i + 1)->word[length] = '\0';
    }
    (*words + i)->word = NULL;
}

int main() {
    srand(time(NULL));

    Word *words;
    int words_count = WORDS_COUNT;
    generate_words(&words, words_count + 1);

    clock_t start = clock();
    int correct_count = 0;

    puts("Typing Speed Test\n");
    puts("------------------\n");

    for (int i = 0; words[i].word != NULL; ++i) {
        printf("%s\n", words[i].word);
        char user_input[words[i].length + 1];
        scanf("%s", user_input);

        if (strcmp(words[i].word, user_input) == 0) {
            ++correct_count;
        }

        free(words[i].word);
    }

    clock_t end = clock();
    double time_taken = (end - start) / CLOCKS_PER_SEC;
    double words_per_minute = (double) correct_count * 60.0 / time_taken;

    printf("You typed %d words correctly in %f seconds.\n", correct_count, time_taken);
    printf("Your typing speed is %f words per minute.\n", words_per_minute);

    for (int i = 0; words[i].word != NULL; ++i) {
        free(words[i].word);
        free(words + i + 1);
    }
    free(words);

    return 0;
}