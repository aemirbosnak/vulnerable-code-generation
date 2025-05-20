//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PATTERN_LEN 20
#define MAX_STEPS 10

void print_pattern(const char *pattern, int step) {
    int i, j;
    char temp[MAX_PATTERN_LEN];

    for (i = 0; i < MAX_PATTERN_LEN; i++) {
        temp[i] = pattern[i];
    }

    for (j = 0; j < step; j++) {
        int random_index = rand() % MAX_PATTERN_LEN;
        temp[random_index] = 'X';
    }

    printf("Step %d: %s\n", step, temp);
}

int main() {
    const char *patterns[] = {
        "Hello World",
        "This is a test",
        "The quick brown fox",
        "A man, a plan, a canal, Panama!"
    };

    int steps[] = {
        1,
        2,
        3,
        4
    };

    int i, j;

    for (i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        for (j = 0; j < sizeof(steps) / sizeof(steps[0]); j++) {
            print_pattern(patterns[i], steps[j]);
        }
    }

    return 0;
}