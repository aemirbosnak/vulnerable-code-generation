//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_CHAR 33
#define MAX_CHAR 126
#define TEST_LENGTH 200
#define MAX_TIME 30 // in seconds

typedef struct {
    int correct;
    int incorrect;
} Result;

void print_test(char* test) {
    printf("\nType the following text:\n%s\n", test);
}

char* generate_test() {
    char* test = malloc(sizeof(char) * TEST_LENGTH + 1);
    int i;
    srand(time(0));
    for (i = 0; i < TEST_LENGTH; i++) {
        test[i] = (char) (rand() % (MAX_CHAR - MIN_CHAR + 1) + MIN_CHAR);
    }
    test[i] = '\0';
    return test;
}

void start_timer() {
    printf("\nYou have %d seconds to finish the test.\n", MAX_TIME);
    time_t now = time(0);
    time_t end_time = now + MAX_TIME;
    while (now < end_time) {
        now = time(0);
    }
}

bool check_result(char* test, char* result) {
    int i;
    for (i = 0; i < TEST_LENGTH; i++) {
        if (test[i] != result[i]) {
            return false;
        }
    }
    return true;
}

Result calculate_result(char* test, char* result) {
    Result res;
    int i;
    for (i = 0; i < TEST_LENGTH; i++) {
        if (test[i] == result[i]) {
            res.correct++;
        } else {
            res.incorrect++;
        }
    }
    return res;
}

int main() {
    char* test = generate_test();
    char* result = malloc(sizeof(char) * TEST_LENGTH + 1);
    print_test(test);
    start_timer();
    fgets(result, TEST_LENGTH + 1, stdin);
    Result res = calculate_result(test, result);
    float accuracy = (float) res.correct / TEST_LENGTH * 100;
    printf("\nYour typing speed test results:\n");
    printf("Time: %ds\n", MAX_TIME);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Correct: %d\n", res.correct);
    printf("Incorrect: %d\n", res.incorrect);
    free(test);
    free(result);
    return 0;
}