//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_PER_MIN 200
#define TEST_DURATION 60

typedef struct {
    char *word;
    int length;
} word_t;

word_t* generate_words(int num_words) {
    word_t *words = malloc(sizeof(word_t) * num_words);
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("Error opening words file");
        exit(1);
    }
    for (int i = 0; i < num_words; i++) {
        char buffer[100];
        if (fgets(buffer, sizeof(buffer), file) == NULL) {
            perror("Error reading from words file");
            exit(1);
        }
        words[i].word = strdup(buffer);
        words[i].length = strlen(buffer) - 1; // remove newline
    }
    fclose(file);
    return words;
}

void free_words(word_t *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);
}

int main() {
    // Generate test words
    int num_words = WORDS_PER_MIN * TEST_DURATION;
    word_t *words = generate_words(num_words);

    // Get user input
    printf("Type as fast as you can for %d seconds:\n", TEST_DURATION);
    time_t start_time = time(NULL);
    char input[100];
    int num_correct = 0;
    while (time(NULL) - start_time < TEST_DURATION) {
        printf("%s ", words[num_correct].word);
        scanf("%s", input);
        if (strcmp(input, words[num_correct].word) == 0) {
            num_correct++;
        }
    }

    // Calculate and print results
    double wpm = (double)num_correct / TEST_DURATION;
    printf("\nYour typing speed is %.2f WPM.\n", wpm);
    free_words(words, num_words);
    return 0;
}