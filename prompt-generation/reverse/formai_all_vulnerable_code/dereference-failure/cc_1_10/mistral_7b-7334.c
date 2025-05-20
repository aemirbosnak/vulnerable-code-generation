//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define MAX_STRING_LENGTH 1024
#define NUM_STRINGS 10
#define STRING_SIZE (MAX_STRING_LENGTH + 1)

void generate_random_strings(char *strings[], int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        strings[i] = mmap(NULL, STRING_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
        snprintf(strings[i], MAX_STRING_LENGTH, "%.*s%c", rand() % MAX_STRING_LENGTH, "abcdefghijklmnopqrstuvwxyz", rand() % 26 + 'a');
        strings[i][MAX_STRING_LENGTH] = '\0';
    }
}

void print_strings(char *strings[], int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        printf("String %d: %s\n", i + 1, strings[i]);
        free(strings[i]);
    }
}

int main() {
    char *strings[NUM_STRINGS];
    int num_correct = 0;
    clock_t start, end;
    double elapsed_time;

    start = clock();
    generate_random_strings(strings, NUM_STRINGS);

    printf("Typing speed test:\n");
    for (int i = 0; i < NUM_STRINGS; ++i) {
        char user_input[MAX_STRING_LENGTH];
        fgets(user_input, MAX_STRING_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(strings[i], user_input) == 0) {
            ++num_correct;
        }
    }

    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("You typed %d strings correctly in %.2f seconds.\n", num_correct, elapsed_time);

    print_strings(strings, NUM_STRINGS);

    return 0;
}