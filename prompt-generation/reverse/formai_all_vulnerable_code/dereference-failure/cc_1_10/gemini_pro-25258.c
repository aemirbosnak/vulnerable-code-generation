//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_random_string(int n)
{
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++)
    {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
double calculate_typing_speed(char *str, double time_taken)
{
    // Convert the string to lowercase
    char *lower_str = malloc(strlen(str) + 1);
    strcpy(lower_str, str);
    for (int i = 0; i < strlen(str); i++)
    {
        lower_str[i] = tolower(lower_str[i]);
    }

    // Split the string into words
    char *words[1000];
    int num_words = 0;
    char *token = strtok(lower_str, " ");
    while (token != NULL)
    {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the typing speed in WPM
    double wpm = (num_words / 5.0) * (60.0 / time_taken);
    return wpm;
}

int main()
{
    // Set the random seed
    srand(time(NULL));

    // Generate a random string of length 200
    char *str = generate_random_string(200);

    // Print the string to the console
    printf("Type the following sentence as quickly and accurately as possible:\n\n");
    printf("%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Wait for the user to finish typing
    char input[200];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in WPM
    double wpm = calculate_typing_speed(input, time_taken);

    // Print the typing speed to the console
    printf("\nYour typing speed is %.2f WPM.\n", wpm);

    return 0;
}