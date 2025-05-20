//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to generate random text
char *generate_text(int length) {
    char *text = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        text[i] = 'a' + rand() % 26;
    }
    text[length] = '\0';
    return text;
}

// Function to get user input
char *get_user_input(int length) {
    char *input = malloc(length + 1);
    printf("Type the following text as quickly and accurately as possible:\n\n%s\n\n", generate_text(length));
    fgets(input, length + 1, stdin);
    return input;
}

// Function to calculate typing speed
float calculate_typing_speed(char *text, char *input, int length) {
    int correct_characters = 0;
    for (int i = 0; i < length; i++) {
        if (text[i] == input[i]) {
            correct_characters++;
        }
    }
    return (float)correct_characters / length * 60;
}

// Function to print results
void print_results(float speed) {
    printf("\nYour typing speed is %.2f words per minute.\n", speed);
}

int main() {
    srand(time(NULL));

    int length = 100;
    char *text = generate_text(length);
    char *input = get_user_input(length);

    float speed = calculate_typing_speed(text, input, length);

    print_results(speed);

    free(text);
    free(input);

    return 0;
}