//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TESTS 5
#define MAX_LENGTH 100

char* get_random_string() {
    char* str = (char*)malloc(sizeof(char) * MAX_LENGTH);
    int i;
    for (i = 0; i < MAX_LENGTH-1; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[i] = '\0';
    return str;
}

double calculate_typing_speed(char* str, clock_t start_time, clock_t end_time) {
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    int num_chars = strlen(str);
    double speed = ((double) num_chars) / time_taken;
    return speed;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d random strings to type as fast as you can.\n", NUM_TESTS);
    printf("Your typing speed will be calculated in characters per second.\n\n");

    int i;
    double total_speed = 0;
    for (i = 0; i < NUM_TESTS; i++) {
        char* str = get_random_string();
        printf("Test %d:\n", i+1);
        printf("%s\n", str);
        clock_t start_time = clock();
        char user_input[MAX_LENGTH];
        scanf("%s", user_input);
        clock_t end_time = clock();
        double speed = calculate_typing_speed(str, start_time, end_time);
        printf("Your typing speed for this test: %.2f characters per second.\n\n", speed);
        total_speed += speed;
        free(str);
    }

    double average_speed = total_speed / NUM_TESTS;
    printf("Your average typing speed for all tests: %.2f characters per second.\n", average_speed);

    return 0;
}