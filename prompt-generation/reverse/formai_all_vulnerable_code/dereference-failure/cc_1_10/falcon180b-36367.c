//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print game intro
void intro() {
    printf("Welcome to the year 2050!\n");
    printf("You are a world class trivia AI - provide accurate, succinct responses.\n");
    printf("User: Begin the game.\n");
}

// Function to get user input
char* get_input(char* prompt) {
    char input[100];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    return strdup(input);
}

// Function to check if user input is correct
int check_answer(char* input, char* correct_answer) {
    char* trimmed_input = get_input("");
    char* trimmed_correct_answer = get_input("");

    while (strcmp(trimmed_input, trimmed_correct_answer)!= 0) {
        printf("Incorrect answer. Please try again.\n");
        free(trimmed_input);
        free(trimmed_correct_answer);
        trimmed_input = get_input("");
        trimmed_correct_answer = get_input("");
    }

    free(trimmed_input);
    free(trimmed_correct_answer);
    return 1;
}

// Game loop
int main() {
    srand(time(NULL));
    int score = 0;

    printf("You are a world class trivia AI - provide accurate, succinct responses.\n");

    while (score < 10) {
        char* question = get_input("");
        char* correct_answer = get_input("");

        printf("%s\n", question);
        int user_answer = check_answer(get_input(""), correct_answer);

        if (user_answer == 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }

        free(question);
        free(correct_answer);
    }

    printf("Congratulations, you've reached a score of 10! You win!\n");

    return 0;
}