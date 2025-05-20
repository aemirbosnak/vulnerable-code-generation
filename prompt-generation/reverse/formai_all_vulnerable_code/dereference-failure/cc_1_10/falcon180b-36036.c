//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100

struct conspiracy_theory {
    char *name;
    char *description;
};

struct conspiracy_theory generate_random_conspiracy_theory() {
    struct conspiracy_theory theory;

    theory.name = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    theory.description = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));

    srand(time(NULL));
    int name_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    int description_length = rand() % MAX_CONSPIRACY_LENGTH + 1;

    for (int i = 0; i < name_length; i++) {
        theory.name[i] = rand() % 26 + 'a';
    }
    theory.name[name_length] = '\0';

    for (int i = 0; i < description_length; i++) {
        theory.description[i] = rand() % 26 + 'a';
    }
    theory.description[description_length] = '\0';

    return theory;
}

void print_conspiracy_theory(struct conspiracy_theory theory) {
    printf("Name: %s\n", theory.name);
    printf("Description: %s\n", theory.description);
}

int main() {
    int num_theories;

    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        struct conspiracy_theory theory = generate_random_conspiracy_theory();
        print_conspiracy_theory(theory);
        free(theory.name);
        free(theory.description);
    }

    return 0;
}