//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 50
#define MAX_LENGTH 200
#define NUM_TESTS 5

// Function to generate a random string of length 'len'
char *generateRandomString(int len) {
    char *str = (char *)malloc((len + 1) * sizeof(char));
    int i;

    for(i = 0; i < len; i++) {
        str[i] = 'A' + (rand() % 26);
    }

    str[len] = '\0';
    return str;
}

int main() {
    int i, j, k;
    int len, tests_passed = 0;
    clock_t start, end;
    double time_diff;

    printf("\n***** Welcome to the Cheerful C Typing Speed Test *****\n");
    printf("                      Yippee! \n\n");

    for(i = 0; i < NUM_TESTS; i++) {
        len = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
        char *str = generateRandomString(len);

        printf("\nTest %d: Type the following string:\n", i + 1);
        printf("%s\n", str);

        start = clock();

        for(j = 0; j < len; j++) {
            for(k = 0; k < 10; k++); // Do some work to simulate typing
        }

        end = clock();
        time_diff = (double)(end - start) / CLOCKS_PER_SEC;

        free(str);

        if(time_diff < 3.0) {
            printf("Wow! You're a speedy typist! You completed the test in %.2f seconds.\n\n", time_diff);
            tests_passed++;
        } else {
            printf("You can do better than that! You took %.2f seconds to complete the test.\n\n", time_diff);
        }
    }

    printf("You passed %d out of %d tests. Keep practicing and you'll be a typing champion!\n", tests_passed, NUM_TESTS);

    return 0;
}