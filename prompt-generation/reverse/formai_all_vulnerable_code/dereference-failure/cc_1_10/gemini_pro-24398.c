//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char* generate_random_string(int n)
{
    // Create a string of length n+1 (for null character)
    char* str = (char*)malloc((n+1) * sizeof(char));

    // Generate random characters for the string
    for (int i = 0; i < n; i++)
    {
        str[i] = (char)('a' + rand() % 26);
    }

    // Terminate the string with a null character
    str[n] = '\0';

    // Return the generated string
    return str;
}

// Function to test the typing speed of the user
int test_typing_speed()
{
    // Get the current time in milliseconds
    clock_t start_time = clock();

    // Generate a random string of length 100
    char* str = generate_random_string(100);

    // Prompt the user to start typing
    printf("Start typing the following string:\n%s\n", str);

    // Get the user input
    char input[101];
    scanf("%s", input);

    // Get the current time in milliseconds
    clock_t end_time = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute (WPM)
    int wpm = (int)((strlen(str) / 5) / time_taken * 60);

    // Free the allocated memory
    free(str);

    // Return the typing speed
    return wpm;
}

// Function to print the result of the typing speed test
void print_result(int wpm)
{
    if (wpm >= 60)
    {
        printf("Excellent! Your typing speed is %d WPM.\n", wpm);
    }
    else if (wpm >= 40)
    {
        printf("Good! Your typing speed is %d WPM.\n", wpm);
    }
    else if (wpm >= 20)
    {
        printf("Average. Your typing speed is %d WPM.\n", wpm);
    }
    else
    {
        printf("Needs improvement. Your typing speed is %d WPM.\n", wpm);
    }
}

// Main function
int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    int wpm = test_typing_speed();

    // Print the result of the test
    print_result(wpm);

    return 0;
}