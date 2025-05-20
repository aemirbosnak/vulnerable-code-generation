//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

typedef struct oracle {
    char **messages;
    int num_messages;
} oracle_t;

oracle_t *create_oracle(int num_messages) {
    oracle_t *oracle = malloc(sizeof(oracle_t));
    oracle->messages = malloc(sizeof(char *) * num_messages);
    oracle->num_messages = num_messages;

    for (int i = 0; i < num_messages; i++) {
        oracle->messages[i] = malloc(256);
    }

    return oracle;
}

void destroy_oracle(oracle_t *oracle) {
    for (int i = 0; i < oracle->num_messages; i++) {
        free(oracle->messages[i]);
    }
    free(oracle->messages);
    free(oracle);
}

void load_oracle(oracle_t *oracle, ...) {
    va_list args;
    va_start(args, oracle);
    for (int i = 0; i < oracle->num_messages; i++) {
        strcpy(oracle->messages[i], va_arg(args, char *));
    }
    va_end(args);
}

char *get_fortune(oracle_t *oracle) {
    srand(time(NULL));
    return oracle->messages[rand() % oracle->num_messages];
}

int main() {
    oracle_t *oracle = create_oracle(5);
    load_oracle(oracle,
        "You will find success in your endeavors.",
        "The future is bright.",
        "Be careful what you wish for.",
        "You are on the right path.",
        "You will find what you are looking for.");

    printf("%s\n", get_fortune(oracle));
    destroy_oracle(oracle);
    return 0;
}