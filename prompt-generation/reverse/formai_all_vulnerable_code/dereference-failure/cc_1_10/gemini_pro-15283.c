//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A struct to store the user's input
typedef struct {
    char *input;
    int length;
} UserInput;

// A function to get the user's input
UserInput getUserInput() {
    char *input = malloc(sizeof(char) * 100);
    int length = 0;

    printf("Type your sweet message: ");
    scanf(" %s", input);

    length = strlen(input);

    UserInput userInput;
    userInput.input = input;
    userInput.length = length;

    return userInput;
}

// A function to calculate the user's typing speed
float calculateTypingSpeed(UserInput userInput) {
    float speed = 0.0;
    float time = 0.0;

    // Get the current time
    time = clock();

    // Process the user's input
    for (int i = 0; i < userInput.length; i++) {
        // Check if the character is a space
        if (userInput.input[i] == ' ') {
            // Increment the word count
            speed++;
        }
    }

    // Calculate the typing speed
    speed = speed / time * 60.0;

    return speed;
}

int main() {
    // Get the user's input
    UserInput userInput = getUserInput();

    // Calculate the user's typing speed
    float speed = calculateTypingSpeed(userInput);

    // Print the user's typing speed
    printf("Your typing speed is: %.2f words per minute\n", speed);

    return 0;
}