//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *text;
    int length;
} Text;

int main() {
    Text text;
    int cpm;
    int wpm;
    int errors;
    time_t start;
    time_t end;
    char input[1024];

    // Get the text from the user.
    printf("Enter the text you want to test on:\n");
    text.text = malloc(1024);
    fgets(text.text, 1024, stdin);
    text.length = strlen(text.text);

    // Start the timer.
    start = time(NULL);

    // Get the input from the user.
    printf("Start typing:\n");
    fgets(input, 1024, stdin);

    // Stop the timer.
    end = time(NULL);

    // Calculate the CPM and WPM.
    cpm = (text.length / 5) / (end - start);
    wpm = cpm / 5;

    // Calculate the errors.
    errors = 0;
    for (int i = 0; i < text.length; i++) {
        if (input[i] != text.text[i]) {
            errors++;
        }
    }

    // Print the results.
    printf("Your CPM is %d.\n", cpm);
    printf("Your WPM is %d.\n", wpm);
    printf("You made %d errors.\n", errors);

    // Free the text.
    free(text.text);

    return 0;
}