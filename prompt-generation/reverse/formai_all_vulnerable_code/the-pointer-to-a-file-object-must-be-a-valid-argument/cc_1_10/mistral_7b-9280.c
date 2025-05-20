//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 30
#define NUM_WORDS 50

char *words[NUM_WORDS];

void prepare_words() {
    FILE *file = fopen("words.txt", "r");
    int i = 0;

    while (fgets(words[i], WORD_LENGTH, file)) {
        words[i][strlen(words[i]) - 1] = '\0'; // Remove newline character
        i++;
    }

    fclose(file);
}

void print_word(char *word) {
    for (int i = 0; word[i]; i++) {
        printf("%c", word[i]);
        fflush(stdout); // Flush output buffer to simulate typing
        usleep(100000); // Sleep for 100ms to simulate typing speed
    }
    printf("\n");
}

int main() {
    clock_t start, end;
    double elapsed_time;
    int i;

    prepare_words();

    start = clock();

    for (i = 0; i < NUM_WORDS; i++) {
        print_word(words[i]);
    }

    end = clock();
    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTotal time taken: %.2f seconds\n", elapsed_time);

    return 0;
}