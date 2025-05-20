//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of a given length
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to compare two strings and return the number of errors
int compare_strings(char *string1, char *string2) {
    int errors = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i]) {
            errors++;
        }
    }
    return errors;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's desired test length
    int length;
    printf("Enter the desired length of the test (in characters): ");
    scanf("%d", &length);

    // Generate a random string of the desired length
    char *original_string = generate_string(length);

    // Display the original string to the user
    printf("Original string:\n%s\n", original_string);

    // Get the user's input
    char *user_string = malloc(length + 1);
    printf("Type the string as quickly and accurately as possible:\n");
    scanf("%s", user_string);

    // Calculate the number of errors
    int errors = compare_strings(original_string, user_string);

    // Display the results
    printf("You made %d errors.\n", errors);

    // Calculate the words per minute
    int wpm = (length / 5) * 60 / (time(NULL) - clock());
    printf("Your typing speed is approximately %d words per minute.\n", wpm);

    // Free the allocated memory
    free(original_string);
    free(user_string);

    return 0;
}