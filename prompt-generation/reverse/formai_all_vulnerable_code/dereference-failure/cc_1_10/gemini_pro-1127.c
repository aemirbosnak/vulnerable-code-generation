//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *str;
    size_t len;
} string;

string generate_random_string(size_t len) {
    string s;
    s.str = malloc(len + 1);
    if (!s.str) {
        return s;
    }
    for (size_t i = 0; i < len; i++) {
        s.str[i] = 'a' + rand() % 26;
    }
    s.str[len] = '\0';
    return s;
}

void free_string(string *s) {
    free(s->str);
    s->str = NULL;
    s->len = 0;
}

int main() {
    srand(time(NULL));

    string target = generate_random_string(100);
    string input = generate_random_string(100);

    printf("Target: %s\n", target.str);
    printf("Input: %s\n", input.str);

    clock_t start = clock();
    while (true) {
        char c = getchar();
        if (c == '\n') {
            break;
        }
        if (c != input.str[input.len]) {
            printf("Error: Incorrect key pressed.\n");
            free_string(&target);
            free_string(&input);
            return 1;
        }
        input.len++;
    }
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    double speed = (double)input.len / elapsed_time;

    printf("Typing speed: %.2f characters per second\n", speed);

    free_string(&target);
    free_string(&input);

    return 0;
}