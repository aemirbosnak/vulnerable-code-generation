//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Turing machine states
enum {
    STATE_START,
    STATE_READ_RATING,
    STATE_CHECK_RATING,
    STATE_ACCEPT,
    STATE_REJECT
};

// Turing machine symbol set
char const * const SYMBOLS = "0123456789";

// Turing machine tape
char *tape;

// Turing machine head position
int head;

// Turing machine state
int state;

// Turing machine input string
char *input;

// Turing machine output string
char *output;

// Turing machine transition function
void transition(void) {
    switch (state) {
        case STATE_START:
            if (*tape == SYMBOLS[0]) {
                state = STATE_READ_RATING;
                head++;
            } else {
                state = STATE_REJECT;
            }
            break;
        case STATE_READ_RATING:
            if (*tape == SYMBOLS[0]) {
                head++;
            } else {
                state = STATE_CHECK_RATING;
            }
            break;
        case STATE_CHECK_RATING:
            if (*tape >= SYMBOLS[0] && *tape <= SYMBOLS[9]) {
                state = STATE_ACCEPT;
            } else {
                state = STATE_REJECT;
            }
            break;
        case STATE_ACCEPT:
            *output++ = 'A';
            state = STATE_START;
            break;
        case STATE_REJECT:
            *output++ = 'R';
            state = STATE_START;
            break;
    }
}

// Turing machine main loop
void run(void) {
    while (state != STATE_ACCEPT && state != STATE_REJECT) {
        transition();
    }
}

// Turing machine input and output
void input_output(void) {
    printf("Enter the movie rating: ");
    scanf("%s", input);
    printf("The movie rating is: %s\n", output);
}

// Turing machine main function
int main(void) {
    // Allocate memory for the Turing machine tape
    tape = malloc(100);

    // Set the Turing machine head position
    head = 0;

    // Set the Turing machine state
    state = STATE_START;

    // Allocate memory for the Turing machine input string
    input = malloc(100);

    // Allocate memory for the Turing machine output string
    output = malloc(100);

    // Input and output the Turing machine
    input_output();

    // Run the Turing machine
    run();

    // Free the memory allocated for the Turing machine
    free(tape);
    free(input);
    free(output);

    return 0;
}