//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS_PER_TEST 10
#define MAX_WORDS_PER_MINUTE 200

typedef struct {
    char *text;
    int length;
} Word;

Word *generate_words(int num_words) {
    Word *words = malloc(num_words * sizeof(Word));
    for (int i = 0; i < num_words; i++) {
        char *word = malloc(10 * sizeof(char));
        sprintf(word, "word%d", i + 1);
        words[i].text = word;
        words[i].length = strlen(word);
    }
    return words;
}

int main() {
    srand(time(NULL));
    int num_words = rand() % MAX_WORDS_PER_TEST + 1;
    Word *words = generate_words(num_words);

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", num_words);

    int correct_count = 0;
    int incorrect_count = 0;

    clock_t start_time = clock();
    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        fflush(stdout);
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].text) == 0) {
            correct_count++;
        } else {
            incorrect_count++;
        }

        free(words[i].text);
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    int words_per_minute = (int)(MAX_WORDS_PER_MINUTE * ((double)correct_count / (double)num_words));

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_count, incorrect_count);
    printf("Your typing speed is %d words per minute.\n", words_per_minute);

    return 0;
}