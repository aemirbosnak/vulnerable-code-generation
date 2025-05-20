//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
int num_words = sizeof(words) / sizeof(char *);

void print_words() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main() {
    int i, j, k;
    int correct_chars = 0, total_chars = 0, wpm = 0;
    char input[100];
    bool timed_out = false;
    clock_t start_time, end_time;

    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        j = rand() % num_words;
        k = rand() % strlen(words[j]);
        strncpy(input, words[j], k);
        input[k] = '\0';
    }

    start_time = clock();
    while (!timed_out) {
        printf("Type the following:\n");
        printf("%s\n", input);
        fgets(input, 100, stdin);
        total_chars += strlen(input);
        if (strcmp(input, words[0]) == 0) {
            correct_chars++;
        }
        if (clock() - start_time >= CLOCKS_PER_SEC * 60) {
            timed_out = true;
        }
    }

    end_time = clock();
    wpm = (60 * correct_chars) / ((end_time - start_time) / (double)CLOCKS_PER_SEC);

    printf("\nYou typed %d correct characters out of %d total characters.\n", correct_chars, total_chars);
    printf("Your typing speed is %d words per minute.\n", wpm);

    return 0;
}