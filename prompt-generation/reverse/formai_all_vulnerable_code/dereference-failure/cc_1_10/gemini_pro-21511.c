//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

int main() {
    char *words[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                     "j", "k", "l", "m", "n", "o", "p", "q", "r",
                     "s", "t", "u", "v", "w", "x", "y", "z"};
    int num_words = sizeof(words) / sizeof(words[0]);
    char *sentence = malloc(1024);
    int sentence_length = 0;
    int num_correct = 0;
    int num_incorrect = 0;
    int num_total = 0;
    int start_time;
    int end_time;
    int elapsed_time;
    double speed;
    int i;

    srand((unsigned int)time(NULL));

    printf("Welcome to the typing speed test!\n");
    printf("Press any key to start...\n");
    getchar();

    start_time = time(NULL);

    while (1) {
        // Generate a random sentence
        sentence_length = rand() % 10 + 1;
        for (i = 0; i < sentence_length; i++) {
            sentence[i] = words[rand() % num_words];
        }
        sentence[sentence_length] = '\0';

        // Print the sentence
        printf("%s\n", sentence);

        // Get the user's input
        fgets(sentence, 1024, stdin);

        // Check if the user's input is correct
        if (strcmp(sentence, sentence) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        num_total++;

        // Check if the user wants to quit
        if (sentence[0] == 'q') {
            break;
        }
    }

    end_time = time(NULL);

    // Calculate the elapsed time
    elapsed_time = end_time - start_time;

    // Calculate the speed
    speed = (double)num_correct / elapsed_time * 60;

    // Print the results
    printf("Your typing speed is %.2f words per minute.\n", speed);
    printf("You typed %d words correctly, %d words incorrectly, and %d words total.\n", num_correct, num_incorrect, num_total);

    free(sentence);

    return 0;
}