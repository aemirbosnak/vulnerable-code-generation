//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define NUM_TRIALS 5

char* getRandomString(int length) {
    char* str = malloc(length+1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

int main() {
    srand(time(NULL));
    char input[MAX_STRING_LENGTH];
    int numCorrectChars = 0;
    double totalTime = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have to type %d randomly generated strings.\n", NUM_TRIALS);

    for (int i = 0; i < NUM_TRIALS; i++) {
        char* str = getRandomString(rand() % MAX_STRING_LENGTH + 1);
        printf("\nString %d: %s\n", i+1, str);

        clock_t start = clock();
        fgets(input, MAX_STRING_LENGTH, stdin);
        clock_t end = clock();

        double time = (double)(end - start) / CLOCKS_PER_SEC;
        totalTime += time;

        for (int j = 0; j < strlen(str); j++) {
            if (input[j] == str[j]) {
                numCorrectChars++;
            }
        }

        printf("Time: %f seconds\n", time);
        free(str);
    }

    printf("\nTyping test complete!\n");
    printf("Avg time per string: %f seconds\n", totalTime / NUM_TRIALS);
    printf("Accuracy: %.2f%%\n", (double) numCorrectChars / (NUM_TRIALS * MAX_STRING_LENGTH) * 100);

    return 0;
}