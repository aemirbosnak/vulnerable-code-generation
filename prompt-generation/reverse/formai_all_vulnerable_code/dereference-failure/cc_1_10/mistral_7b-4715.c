//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define WORD_LENGTH 50
#define BUFFER_SIZE 1024
#define NUM_ROUNDS 5
#define TIME_PER_ROUND 10

typedef struct {
    char *word;
    int length;
} Word;

Word words[NUM_ROUNDS];
int current_round = 0;

void generate_random_word(Word *word) {
    word->length = rand() % WORD_LENGTH + 1;
    word->word = malloc(word->length + 1);

    for (int i = 0; i < word->length; i++) {
        word->word[i] = (char) (rand() % 26 + 'a');
        word->word[word->length] = '\0';
    }
}

void print_word(Word word) {
    printf("%s\n", word.word);
}

void type_word(Word word) {
    char user_input[BUFFER_SIZE];
    fflush(stdout);
    clock_t start = clock();

    printf("Type the following word:\n");
    print_word(word);

    fgets(user_input, BUFFER_SIZE, stdin);
    user_input[strlen(user_input) - 1] = '\0';

    clock_t end = clock();
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    if (strcmp(word.word, user_input) == 0) {
        printf("Correct! You typed '%s' in %.2f seconds.\n", user_input, elapsed_time);
    } else {
        printf("Incorrect! The correct answer was '%s'. Try again.\n", word.word);
        type_word(word);
    }
}

void setup_round() {
    generate_random_word(&words[current_round]);
}

void end_round() {
    free(words[current_round].word);
    current_round++;
}

void check_for_interrupt() {
    int c = getchar();
    if (c == 'q') {
        printf("Quitting the program...\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_ROUNDS; i++) {
        setup_round();
        type_word(words[i]);
        end_round();
    }

    printf("Congratulations, you have completed the typing speed test!\n");

    signal(SIGINT, check_for_interrupt);

    while (1) {
        usleep(100000);
    }

    return 0;
}