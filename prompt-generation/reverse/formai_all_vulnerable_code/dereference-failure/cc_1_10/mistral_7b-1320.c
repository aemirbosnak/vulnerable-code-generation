//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_CHAR 256
#define MAX_TEST 10
#define SEED 1337

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void generate_random_string(char *str, size_t len) {
    srand(time(NULL) + getpid());
    for (size_t i = 0; i < len; ++i) {
        str[i] = (rand() % (128 - 33 + 1)) + 33;
    }
    str[len] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <level>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int level = atoi(argv[1]);
    if (level <= 0 || level > MAX_TEST) {
        fprintf(stderr, "Invalid level: %d\n", level);
        exit(EXIT_FAILURE);
    }

    char input[MAX_CHAR];
    char output[MAX_CHAR];

    generate_random_string(input, rand() % (MAX_CHAR - 1) + 1);
    printf("Type the following string:\n'%s'\n", input);

    clock_t start = clock();

    for (int i = 0; i < level; ++i) {
        generate_random_string(input, rand() % (MAX_CHAR - 1) + 1);
        fgets(output, sizeof(output), stdin);
        memset(output, 0, sizeof(output));

        if (strcmp(input, output) != 0) {
            printf("Incorrect! Try again.\n");
            continue;
        }

        printf("Correct! Next string.\n");
    }

    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Congratulations! You completed level %d in %.2fs.\n", level, elapsed_secs);

    return EXIT_SUCCESS;
}