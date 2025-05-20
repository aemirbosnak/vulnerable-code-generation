//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 20
#define NUM_WORDS 10
#define BUFFER_SIZE 1024

void generate_words(char *words[NUM_WORDS]);
void print_word(const char *word);
int main() {
    char *words[NUM_WORDS];
    generate_words(words);

    clock_t start = clock();

    int score = 0;
    int incorrect = 0;

    printf("Get ready for a SURPRISE typing test!\n");
    printf("You will be typing %d words.\n", NUM_WORDS);
    printf("Each word will be displayed only once!\n");
    printf("Type the word exactly as it is shown!\n");
    printf("Press enter after each word to continue.\n\n");

    for (int i = 0; i < NUM_WORDS; i++) {
        print_word(words[i]);
        char input[WORD_LENGTH];
        fgets(input, BUFFER_SIZE, stdin);

        if (strcmp(input, words[i]) != 0) {
            incorrect++;
            printf("Incorrect! Please try again.\n");
            printf("The correct word was: %s\n", words[i]);
            continue;
        }

        score++;
        printf("Correct! Great job!\n");
    }

    clock_t end = clock();
    double elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;

    printf("\nYou have typed %d words correctly in %f seconds.\n", score, elapsed_time);
    printf("Your typing speed is %f words per minute.\n", score / (elapsed_time / 60));

    return 0;
}

void generate_words(char *words[]) {
    char words_file[30] = "words.txt";
    FILE *file = fopen(words_file, "r");

    for (int i = 0; i < NUM_WORDS; i++) {
        fscanf(file, "%s", words[i]);
        words[i][strlen(words[i]) - 1] = '\0'; // Remove newline character
    }

    fclose(file);
}

void print_word(const char *word) {
    printf("\033[2J"); // Clear console
    printf("\033[%d;%dH", 1, 1); // Move cursor to top-left corner
    printf("%s\n", word);
}