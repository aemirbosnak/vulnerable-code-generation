//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char magic_word[20];

    // Initialize magic word
    strcpy(magic_word, "THE_ANSWER_TO_THE_UNIVERSE");

    // Get two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    // Check if the numbers are valid
    if (num1 < 0 || num2 < 0) {
        printf("Invalid input! Please enter positive numbers.\n");
        return 1;
    }

    // Calculate the sum of the two numbers
    sum = num1 + num2;

    // Check if the sum is equal to the magic number
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You have found the magic number %d!\n", MAGIC_NUMBER);
    } else {
        printf("Too bad, the sum is not %d. Try again!\n", MAGIC_NUMBER);
    }

    // Print the magic word
    printf("The magic word is: %s\n", magic_word);

    // Get the user's guess for the magic word
    printf("Guess a letter: ");
    char guess = getchar();

    // Check if the guess is correct
    int correct = 0;
    for (int i = 0; i < strlen(magic_word); i++) {
        if (guess == magic_word[i]) {
            correct++;
        }
    }

    // Print the result
    if (correct == strlen(magic_word)) {
        printf("Congratulations! You guessed the magic word %s correctly!\n", magic_word);
    } else {
        printf("Too bad, you only got %d correct guesses. Try again!\n", correct);
    }

    return 0;
}