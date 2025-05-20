//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *words[] = {"Dennis", "Ritchie", "was", "a", "great", "programmer"};
    int num_words = sizeof(words) / sizeof(char *);
    int word_index = 0;
    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int num_incorrect_chars = 0;
    int total_chars = 0;
    int total_correct_chars = 0;
    int wpm = 0;
    int accuracy = 0;
    int i;
    int j;
    int k;
    struct timespec start_time, end_time;
    double elapsed_time;

    srand(time(NULL));

    for (i = 0; i < num_words; i++) {
        word_index = rand() % num_words;
        printf("%s ", words[word_index]);
    }
    printf("\n");

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    while (1) {
        if (getchar() == '\n') {
            break;
        }
        total_chars++;
        if (word_index >= num_words) {
            word_index = 0;
        }
        if (getchar() == words[word_index][total_chars - 1]) {
            correct_words++;
            total_correct_chars++;
        } else {
            incorrect_words++;
            num_incorrect_chars++;
        }
        word_index++;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    if (total_chars > 0) {
        wpm = (int) (total_chars / (elapsed_time / 60.0));
    }

    if (correct_words > 0) {
        accuracy = (int) ((float) correct_words / correct_words + incorrect_words * 100.0);
    }

    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}