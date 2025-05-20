//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 4096
#define HAPPY_SIZE 512

typedef struct {
    char happy[HAPPY_SIZE];
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
} happy_t;

void happy_print(happy_t *happy) {
    printf("\n====== Happy Input Sanitizer ======\n");
    printf("Input: %s\n", happy->input);
    printf("Output: %s\n", happy->output);
    printf("Happy: %s\n", happy->happy);
    printf("===================================\n");
}

void sanitize_input(happy_t *happy) {
    int i, j;
    for (i = 0; happy->input[i] != '\0'; i++) {
        for (j = 0; j < HAPPY_SIZE && happy->happy[j] != '\0'; j++) {
            if (happy->input[i] == happy->happy[j]) {
                happy->output[i] = happy->input[i];
                break;
            }
        }
        if (j == HAPPY_SIZE) {
            happy->output[i] = '_';
        }
    }
    happy->output[i] = '\0';
}

int main(int argc, char *argv[]) {
    happy_t *happy = mmap(NULL, sizeof(happy_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (happy == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    printf("Enter a happy input:\n");
    fgets(happy->happy, HAPPY_SIZE, stdin);
    happy->happy[strcspn(happy->happy, "\n")] = '\0';

    printf("Enter a input to sanitize:\n");
    fgets(happy->input, MAX_INPUT_SIZE, stdin);
    happy->input[strcspn(happy->input, "\n")] = '\0';

    sanitize_input(happy);

    happy_print(happy);

    munmap(happy, sizeof(happy_t));

    return 0;
}