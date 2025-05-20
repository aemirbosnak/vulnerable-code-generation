//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (char)('a' + rand() % 26);
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the typing speed
int calculate_speed(int num_words, int time_taken) {
    return (num_words / 5) * (60 / time_taken);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of words from the user
    int num_words;
    printf("Enter the number of words you want to type: ");
    scanf("%d", &num_words);

    // Generate a random string of words
    char* str = generate_string(num_words * 5);

    // Display the string to the user
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* typed_str = malloc(num_words * 5 + 1);
    fgets(typed_str, num_words * 5 + 1, stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    int time_taken = (end - start) / CLOCKS_PER_SEC;

    // Compare the two strings
    int correct = compare_strings(str, typed_str);

    // Calculate the typing speed
    int speed = calculate_speed(num_words, time_taken);

    // Display the results
    if (correct) {
        printf("Congratulations! You typed the string correctly.\n");
    } else {
        printf("Sorry, you made some mistakes in typing the string.\n");
    }
    printf("Your typing speed is %d words per minute.\n", speed);

    // Free the allocated memory
    free(str);
    free(typed_str);

    return 0;
}