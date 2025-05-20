//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random string of length n
char *gen_rand_str(int n) {
    char *str = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Test the typing speed of the user
void test_typing_speed() {
    // Generate a random string
    char *str = gen_rand_str(100);

    // Get the start time
    clock_t start = clock();

    // Prompt the user to type the string
    printf("Type the following string as quickly as possible:\n%s\n", str);

    // Get the user's input
    char *user_input = malloc(sizeof(char) * 101);
    scanf("%s", user_input);

    // Get the end time
    clock_t end = clock();

    // Calculate the typing speed
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double typing_speed = strlen(str) / time_taken;

    // Print the typing speed
    printf("Your typing speed is: %.2f words per minute\n", typing_speed);

    // Free the allocated memory
    free(str);
    free(user_input);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the typing speed of the user
    test_typing_speed();

    return 0;
}