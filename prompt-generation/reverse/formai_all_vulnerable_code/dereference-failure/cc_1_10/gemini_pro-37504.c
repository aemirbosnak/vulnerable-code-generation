//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    int i;
    for (i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to get the user's input
char* get_input(int n) {
    char* str = malloc(n + 1);
    int i;
    for (i = 0; i < n; i++) {
        str[i] = getchar();
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int i;
    for (i = 0; i < strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the accuracy
float calculate_accuracy(char* str1, char* str2) {
    int i;
    int correct_chars = 0;
    for (i = 0; i < strlen(str1); i++) {
        if (str1[i] == str2[i]) {
            correct_chars++;
        }
    }
    return (float)correct_chars / strlen(str1);
}

// Function to calculate the speed
float calculate_speed(char* str1, time_t start_time, time_t end_time) {
    float elapsed_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    return (float)strlen(str1) / elapsed_time;
}

int main() {
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

    srand(time(NULL));
    char* original_string = generate_string(n);

    printf("Type the following string:\n%s\n", original_string);

    time_t start_time = clock();
    char* user_input = get_input(n);
    time_t end_time = clock();

    int correct = compare_strings(original_string, user_input);
    float accuracy = calculate_accuracy(original_string, user_input);
    float speed = calculate_speed(original_string, start_time, end_time);

    printf("\nResults:\n");
    if (correct) {
        printf("Congratulations! You typed the string correctly.\n");
    } else {
        printf("Oops! You made some mistakes.\n");
    }
    printf("Accuracy: %.2f%%\n", accuracy * 100);
    printf("Speed: %.2f characters per second\n", speed);

    free(original_string);
    free(user_input);
    return 0;
}