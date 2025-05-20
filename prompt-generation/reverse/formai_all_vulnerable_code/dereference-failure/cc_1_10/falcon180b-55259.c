//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char* generate_random_string(int length) {
    char* result = malloc(length + 1);
    if (result == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }

    result[length] = '\0';
    return result;
}

int main() {
    srand(time(NULL));

    int length = 10; // Length of the random string to be typed
    int correct_answers = 0;
    int incorrect_answers = 0;
    int total_answers = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following random string:\n");

    char* random_string = generate_random_string(length);
    printf("%s\n", random_string);

    char input_string[length + 1];
    fgets(input_string, length + 1, stdin);

    if (strcmp(input_string, random_string) == 0) {
        printf("Congratulations! You have typed the correct string.\n");
        correct_answers++;
    } else {
        printf("Incorrect answer. The correct string was: %s\n", random_string);
        incorrect_answers++;
    }

    total_answers++;

    int speed = 0;
    if (total_answers > 0) {
        speed = (int) (length * 60 / (double) total_answers);
    }

    printf("Your typing speed is %d words per minute.\n", speed);

    return 0;
}