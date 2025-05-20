//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20 // maximum word length
#define MIN_WORD_LENGTH 5 // minimum word length
#define MAX_TIME 60 // maximum time for test in seconds

char* generate_word(); // function to generate random word
void wait(int seconds); // function to wait for some time
void clear_input_buffer(); // function to clear input buffer

int main() {
    srand(time(NULL)); // initializing random seed

    printf("Welcome to the Brave Typing Speed Test!\n");
    printf("You will be given a random word and you have to type it as fast as you can.\n");
    printf("You have a maximum of %d seconds to complete the test.\n", MAX_TIME);

    printf("Press enter to start the test...");
    getchar(); // wait for user to press enter

    int count = 0; // initializing count of correct words typed
    time_t start_time = time(NULL); // starting timer

    while(difftime(time(NULL),start_time) < MAX_TIME) { // looping until max time is reached
        char* word = generate_word(); // generating random word
        printf("\nType the word: %s\n", word);

        time_t word_start_time = time(NULL); // starting timer for current word

        char input[MAX_WORD_LENGTH+1]; // initializing input buffer
        fgets(input, MAX_WORD_LENGTH+1, stdin); // getting user input

        if (input[strlen(input)-1] != '\n') { // checking if input buffer overflowed
            clear_input_buffer(); // clearing input buffer
            printf("Your input was too long. Try again.\n");
            continue;
        }

        input[strlen(input)-1] = '\0'; // replacing newline character with null character

        if (strcmp(input, word) == 0) { // checking if user input matches generated word
            printf("Correct!\n");
            count++; // incrementing count of correct words
        } else {
            printf("Incorrect. The correct word was: %s\n", word);
        }

        free(word); // freeing memory allocated to word
        wait(1); // waiting for 1 second before showing next word
    }

    printf("\nTime is up!\n");
    printf("You typed %d words correctly in %d seconds.\n", count, MAX_TIME);
    printf("Your typing speed is: %d words per minute.\n", (count*60)/MAX_TIME);

    return 0; // exiting program
}

char* generate_word() {
    int length = (rand() % (MAX_WORD_LENGTH-MIN_WORD_LENGTH+1)) + MIN_WORD_LENGTH; // generating random length for word
    char* word = malloc((length+1)*sizeof(char)); // allocating memory for word

    for (int i = 0; i < length; i++) { // generating random characters for word
        int type = rand() % 3; // generating random character type (lowercase, uppercase, digit)

        if (type == 0) {
            word[i] = 'a' + (rand() % 26); // generating random lowercase letter
        } else if (type == 1) {
            word[i] = 'A' + (rand() % 26); // generating random uppercase letter
        } else {
            word[i] = '0' + (rand() % 10); // generating random digit
        }
    }

    word[length] = '\0'; // terminating word with null character
    return word; // returning pointer to word
}

void wait(int seconds) {
    clock_t end_wait;
    end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait) {
    }
}

void clear_input_buffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}