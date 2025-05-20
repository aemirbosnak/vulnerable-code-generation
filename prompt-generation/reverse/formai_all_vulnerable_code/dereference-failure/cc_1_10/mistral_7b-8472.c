//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 16
#define CHAR_SET_SIZE 64

typedef struct {
    int count[CHAR_SET_SIZE];
} char_set;

void init_char_set(char_set *cs) {
    int i;

    for (i = 0; i < CHAR_SET_SIZE; ++i)
        cs->count[i] = 1;
}

void add_char_to_char_set(char_set *cs, char c) {
    cs->count[c & 0x7f]++;
}

char random_char() {
    static char_set cs;
    static int seed = 0;
    int roll, i;

    if (cs.count[0] == 0) {
        init_char_set(&cs);
        srand(seed++);
    }

    roll = rand();

    for (i = 1; i < CHAR_SET_SIZE; ++i) {
        if (cs.count[i] && roll < cs.count[i])
            return i | 0x80;
    }

    return random_char();
}

int main() {
    int i;
    char password[LENGTH + 1];

    init_char_set(&(password[0]));

    for (i = 0; i < LENGTH; ++i)
        password[i] = random_char();

    password[LENGTH] = '\0';

    printf("Generated Password: %s\n", password);

    return 0;
}