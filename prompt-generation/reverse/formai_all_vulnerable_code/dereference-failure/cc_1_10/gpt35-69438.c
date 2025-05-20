//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function declarations
int is_alpha(char c);
int is_whitespace(char c);
int get_random_char();
void generate_random_string(char *str, int length);
int calculate_typing_speed(int time_elapsed, int chars_typed);

int main()
{
    int length = 1000; // length of the string to be typed
    char *expected = (char *)malloc(length * sizeof(char)); // string to be typed
    generate_random_string(expected, length); // generate random string for typing

    // print instructions to the user
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following string as fast as you can:\n%s\n", expected);
    printf("Press Enter to begin...\n");
    getchar();

    // variables to track time and characters typed
    time_t start_time = time(NULL);
    int chars_typed = 0;

    // loop to get user input until the entire string is typed
    while(chars_typed < length) {
        char c = getchar();

        if(is_alpha(c) || is_whitespace(c)) {
            if(c == expected[chars_typed]) {
                chars_typed++;
                printf("%c", c);
            } else {
                printf("\nYou made a mistake! Try again...\n");
            }
        }
    }

    int time_elapsed = (int)(time(NULL) - start_time);
    printf("\nCongratulations! You typed the string in %d seconds.\n", time_elapsed);

    int typing_speed = calculate_typing_speed(time_elapsed, length);
    printf("Your typing speed was %d characters per minute.\n", typing_speed);

    free(expected); // free memory allocated for expected string
    return 0;
}

/**
 * Check if a character is an alphabetical character.
 */
int is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * Check if a character is a whitespace character.
 */
int is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

/**
 * Generate a random character.
 */
int get_random_char()
{
    int r = rand() % 63;

    if(r < 26) {
        return 'a' + r;
    } else if(r < 52) {
        return 'A' + r - 26;
    } else if(r < 62) {
        return '0' + r - 52;
    } else {
        return ' ';
    }
}

/**
 * Generate a random string of a given length.
 */
void generate_random_string(char *str, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        str[i] = get_random_char();
    }
    str[length] = '\0';
}

/**
 * Calculate the typing speed given the time elapsed and the number of characters typed.
 */
int calculate_typing_speed(int time_elapsed, int chars_typed)
{
    double minutes = (double)time_elapsed / 60;
    int speed = (int)((double)chars_typed / minutes);
    return speed;
}