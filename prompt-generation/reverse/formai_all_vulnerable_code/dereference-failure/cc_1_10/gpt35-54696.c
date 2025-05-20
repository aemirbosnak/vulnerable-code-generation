//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog."
#define MAX_TIME 10.0

char *type_sentence();
double time_taken();

int main() {
    char *to_type = SENTENCE;
    char *typed = type_sentence(to_type);
    double time_spent = time_taken();

    printf("\nTyped: %s", typed);
    printf("\nYou typed %.2f characters per second.\n", (double)strlen(typed)/time_spent);

    free(typed);
    return 0;
}

char *type_sentence(char *to_type) {
    int position = 0;
    char *typed = calloc(strlen(to_type), sizeof(char));
    double start_time = time(NULL);

    printf("Type the following sentence: %s\n", to_type);

    while (1) {
        if (difftime(time(NULL), start_time) >= MAX_TIME) {
            break;
        }

        char input = getchar();
        if (input == '\n' || input == EOF) {
            break;
        }

        if (input == to_type[position]) {
            putchar(input);
            typed[position++] = input;
        } else {
            putchar('*');
        }

        if (position == strlen(to_type)) {
            break;
        }
    }

    putchar('\n');
    return typed;
}

double time_taken() {
    static struct timespec start_time = {0, 0};
    struct timespec current_time;
    if (start_time.tv_sec == 0 && start_time.tv_nsec == 0) {
        clock_gettime(CLOCK_REALTIME, &start_time);
    }
    clock_gettime(CLOCK_REALTIME, &current_time);
    double elapsed = (current_time.tv_sec - start_time.tv_sec) + (double)(current_time.tv_nsec - start_time.tv_nsec)/1000000000L;
    return elapsed;
}