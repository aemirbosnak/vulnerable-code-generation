//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_ATTEMPTS 3

char *get_random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
    return str;
}

int main() {
    srand(time(0));

    printf("\nWelcome to the Typing Speed Test\n");
    printf("You will be given a random string to type as fast as possible\n");

    int length = 5 + (rand() % 5);
    char *correct_string = get_random_string(length);
    char user_string[MAX_STRING_LENGTH];

    int num_attempts = 0;
    time_t start_time = time(NULL);
    double elapsed_time;

    do {
        printf("\nType this string as fast as possible: %s\n", correct_string);
        fgets(user_string, MAX_STRING_LENGTH, stdin);

        // Remove newline character from user input
        int length = strlen(user_string);
        if (length > 0 && user_string[length - 1] == '\n') {
            user_string[length - 1] = '\0';
        }

        if (strcmp(correct_string, user_string) == 0) {
            time_t end_time = time(NULL);
            elapsed_time = difftime(end_time, start_time);
            printf("Congratulations! You typed the string in %f seconds\n", elapsed_time);
            break;
        } else {
            printf("Incorrect, please try again!\n");
            num_attempts++;
        }
    } while (num_attempts < MAX_NUM_ATTEMPTS);

    if (num_attempts == MAX_NUM_ATTEMPTS) {
        printf("Sorry, you did not type the correct string within the maximum number of attempts\n");
    }

    free(correct_string);
    return 0;
}