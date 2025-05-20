//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define MAX_TEST_DURATION 60

struct Word {
    char word[MAX_WORD_LEN];
    int len;
};

int main() {
    int num_words = 0;
    struct Word *words = malloc(MAX_WORDS * sizeof(struct Word));

    printf("Enter words to test typing speed: ");
    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, stdin)) {
        strcpy(words[num_words].word, word);
        words[num_words].len = strlen(word);
        num_words++;
        if (num_words >= MAX_WORDS) {
            break;
        }
    }

    srand(time(NULL));
    int rand_index = rand() % num_words;
    struct Word *test_word = &words[rand_index];

    int start_time = time(NULL);

    printf("Start typing the word %s when ready.\n", test_word->word);

    char input[MAX_WORD_LEN];
    while (fgets(input, MAX_WORD_LEN, stdin)) {
        if (strcmp(input, test_word->word) == 0) {
            int end_time = time(NULL);
            int duration = end_time - start_time;
            printf("You typed %s in %d seconds.\n", test_word->word, duration);
            break;
        }
    }

    free(words);
    return 0;
}