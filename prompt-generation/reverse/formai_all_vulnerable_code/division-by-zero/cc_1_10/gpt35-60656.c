//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char input[100]; // array to store user input
    int i, len; // variables for iteration and string length
    clock_t begin, end; // clock variables for timing
    double time_spent; // variable to store time taken to complete test

    // welcome message
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following sentence as quickly and accurately as possible:\n\n");

    // sentence for user to type
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    // prompt user to begin typing
    printf("Press Enter to start typing...");
    getchar(); // wait for user to press Enter

    // start timing
    begin = clock();

    // get user input
    fgets(input, 100, stdin);

    // remove newline character at end of user input
    len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // calculate time taken to complete test
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    // calculate typing speed in words per minute
    float wpm = (strlen(input) / 5.0) / (time_spent / 60.0);

    // calculate accuracy as percentage
    int accuracy = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == "The quick brown fox jumps over the lazy dog."[i]) {
            accuracy += 1;
        }
    }
    accuracy = (accuracy / strlen(input)) * 100;

    // display results
    printf("\n\nYou typed: %s\n\n", input);
    printf("Time taken: %.2f seconds\n\n", time_spent);
    printf("Typing speed: %.2f words per minute\n\n", wpm);
    printf("Accuracy: %d%%\n\n", accuracy);

    // display motivational message
    char messages[3][100] = {"Great job!", "Keep practicing!", "You can do better!"};
    srand(time(0)); // set random seed
    int r = rand() % 3; // choose random motivational message
    printf("%s\n\n", messages[r]);
    
    // end program
    return 0;
}