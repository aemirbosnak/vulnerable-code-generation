//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORDS 10
#define MAX_WORDS 50
#define WORD_LENGTH 30

void print_word(const char *word) {
    printf("%s ", word);
}

int main() {
    srand(time(NULL));
    int words_count = 0;
    int min_words = MIN_WORDS;
    int max_words = MAX_WORDS;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Press Enter to start the test...\n");
    getchar();

    char **words_list = malloc(sizeof(char *) * (max_words + 1));
    for (int i = 0; i <= max_words; ++i) {
        words_list[i] = malloc(sizeof(char) * (WORD_LENGTH + 1));
        for (int j = 0; j < WORD_LENGTH; ++j) {
            words_list[i][j] = 'a' + rand() % 26;
        }
        words_list[i][WORD_LENGTH] = '\0';
        ++words_count;
    }

    clock_t start_time = clock();
    for (int i = 0; i < min_words; ++i) {
        print_word(words_list[rand() % (words_count)]);
        printf("\nType the word below and press Enter: ");
        char input[WORD_LENGTH];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(words_list[rand() % (words_count)], input) != 0) {
            printf("Incorrect! Try again.\n");
            i--;
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    free(words_list);

    printf("\nTest completed! You typed %d words in %.2fs.\n", min_words, elapsed_time);

    return 0;
}