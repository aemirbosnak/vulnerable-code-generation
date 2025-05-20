//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct word {
    char *string;
    int length;
};

struct test {
    struct word *words;
    int num_words;
    int total_length;
};

struct result {
    int num_correct;
    int num_incorrect;
    double speed;
};

int main(void) {
    // Initialize the test
    struct test test;
    test.num_words = 100;
    test.total_length = 0;
    test.words = malloc(sizeof(struct word) * test.num_words);

    // Generate the test words
    srand(time(NULL));
    for (int i = 0; i < test.num_words; i++) {
        int length = rand() % 10 + 1;
        test.words[i].length = length;
        test.words[i].string = malloc(length + 1);
        for (int j = 0; j < length; j++) {
            test.words[i].string[j] = 'a' + rand() % 26;
        }
        test.words[i].string[length] = '\0';
        test.total_length += length;
    }

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[test.total_length + 1];
    printf("Type the following words as quickly and accurately as possible:\n");
    for (int i = 0; i < test.num_words; i++) {
        printf("%s ", test.words[i].string);
    }
    printf("\n");
    fgets(input, test.total_length + 1, stdin);

    // Stop the timer
    clock_t end = clock();

    // Check the user's input
    struct result result;
    result.num_correct = 0;
    result.num_incorrect = 0;
    for (int i = 0; i < test.num_words; i++) {
        if (strcmp(input, test.words[i].string) == 0) {
            result.num_correct++;
        } else {
            result.num_incorrect++;
        }
    }

    // Calculate the speed
    result.speed = (double)result.num_correct / ((double)(end - start) / CLOCKS_PER_SEC);

    // Display the results
    printf("Results:\n");
    printf("Number of correct words: %d\n", result.num_correct);
    printf("Number of incorrect words: %d\n", result.num_incorrect);
    printf("Speed: %.2f words per minute\n", result.speed);

    // Free the memory
    for (int i = 0; i < test.num_words; i++) {
        free(test.words[i].string);
    }
    free(test.words);

    return 0;
}