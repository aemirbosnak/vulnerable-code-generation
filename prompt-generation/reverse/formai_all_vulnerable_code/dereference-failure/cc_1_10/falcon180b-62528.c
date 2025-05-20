//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _conspiracy_theory {
    char* name;
    char* description;
};

struct _conspiracy_theory generate_theory() {
    struct _conspiracy_theory theory;
    theory.name = malloc(50 * sizeof(char));
    theory.description = malloc(200 * sizeof(char));

    srand(time(NULL));
    int name_length = rand() % 50 + 1;
    int description_length = rand() % 200 + 1;

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

void print_theory(struct _conspiracy_theory theory) {
    printf("Name: %s\n", theory.name);
    printf("Description: %s\n", theory.description);
}

int main() {
    int num_theories;
    printf("Enter the number of conspiracy theories you want to generate: ");
    scanf("%d", &num_theories);

    for (int i = 0; i < num_theories; i++) {
        struct _conspiracy_theory theory = generate_theory();
        print_theory(theory);
        free(theory.name);
        free(theory.description);
    }

    return 0;
}