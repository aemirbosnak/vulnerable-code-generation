//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MIN_LENGTH 20
#define MAX_LENGTH 100
#define MIN_REPS 3
#define MAX_REPS 10

void generate_random_string(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int length, reps;

    if (argc < 2 || argc > 3) {
        printf("Usage: %s <string length> [number of repetitions]\n", argv[0]);
        return 1;
    }

    length = atoi(argv[1]);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: String length must be between %d and %d\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    if (argc > 2) {
        reps = atoi(argv[2]);
        if (reps < MIN_REPS || reps > MAX_REPS) {
            printf("Error: Number of repetitions must be between %d and %d\n", MIN_REPS, MAX_REPS);
            return 1;
        }
    } else {
        reps = MIN_REPS;
    }

    char str[length + 1];
    generate_random_string(str, length);

    clock_t start, end;
    double elapsed_time;

    for (int i = 0; i < reps; i++) {
        start = clock();
        printf("%s\n", str);
        fflush(stdout);
        usleep(100000); // Wait for 0.1s to let the output be displayed
        end = clock();
        elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %.6f seconds\n", elapsed_time);
    }

    return 0;
}