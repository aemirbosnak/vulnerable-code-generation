//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define WORD_LENGTH 20
#define DELAY 100000

// Happy function to print a random happy message
void print_happy_message() {
    int random_number = rand() % 5;
    switch (random_number) {
        case 0:
            printf("Yippee! You are awesome!\n");
            break;
        case 1:
            printf("Hurray! You rock!\n");
            break;
        case 2:
            printf("Woot woot! Keep it up!\n");
            break;
        case 3:
            printf("Fantastic! You're on a roll!\n");
            break;
        case 4:
            printf("Bravo! You're making progress!\n");
            break;
    }
}

// Function to generate random words
char* generate_random_word() {
    char* word = (char*)malloc(WORD_LENGTH * sizeof(char));
    for (int i = 0; i < WORD_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[WORD_LENGTH] = '\0';
    return word;
}

int main() {
    srand(time(NULL));
    int words_typed = 0;
    int start_time = time(NULL);
    int elapsed_time;

    printf("Get ready to type some happy words!\n");
    print_happy_message();

    for (int i = 0; i < MAX_WORDS; i++) {
        char* word = generate_random_word();
        printf("Type the following word: %s\n", word);
        fflush(stdout);

        clock_t start = clock();
        fgets(word, WORD_LENGTH, stdin);
        elapsed_time = clock() - start;

        if (strcmp(word, word) == 0) {
            words_typed++;
            printf("Well done! You typed the word: %s\n", word);
            free(word);
            print_happy_message();
            usleep(DELAY);
        } else {
            printf("Oops! Please try again. The correct word was: %s\n", word);
            free(word);
            i--;
        }
    }

    int end_time = time(NULL);
    double typing_speed = ((double)words_typed * WORD_LENGTH) / ((end_time - start_time) / 60);
    printf("Congratulations! Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}