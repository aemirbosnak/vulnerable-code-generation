//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: random
// C Typing Speed Test
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_SIZE 100

// Function to calculate typing speed
int calculate_typing_speed(char *word, char *input) {
    int i, j, k;
    int errors = 0;
    int words = 0;
    int correct = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            words++;
        }
    }

    for (i = 0, j = 0, k = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            if (strncmp(word + j, input + k, i - k) == 0) {
                correct++;
            } else {
                errors++;
            }
            j = i + 1;
            k = i + 1;
        }
    }

    return (correct * 100) / (words * 5);
}

// Function to get input from user
void get_input(char *input, int size) {
    int i = 0;
    char ch;

    while (1) {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
        input[i++] = ch;
    }
    input[i] = '\0';
}

// Main function
int main() {
    char word[MAX_STRING_SIZE];
    char input[MAX_STRING_SIZE];
    int speed;

    // Generate random word
    srand(time(NULL));
    int rand_num = rand() % 1000 + 1;
    sprintf(word, "word%d", rand_num);

    // Get input from user
    printf("Enter the word: ");
    get_input(input, MAX_STRING_SIZE);

    // Calculate typing speed
    speed = calculate_typing_speed(word, input);

    // Print result
    printf("Your typing speed is: %d WPM\n", speed);

    return 0;
}