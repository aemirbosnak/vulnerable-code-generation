//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_conspiracy_theory(void) {
    ConspiracyTheory *conspiracy = malloc(sizeof(ConspiracyTheory));

    conspiracy->name = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    conspiracy->description = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));

    srand(time(NULL));
    int name_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    int description_length = rand() % MAX_CONSPIRACY_LENGTH + 1;

    for (int i = 0; i < name_length; i++) {
        conspiracy->name[i] = 'A' + rand() % 26;
    }
    conspiracy->name[name_length] = '\0';

    for (int i = 0; i < description_length; i++) {
        conspiracy->description[i] = 'A' + rand() % 26;
    }
    conspiracy->description[description_length] = '\0';

    return conspiracy;
}

void print_conspiracy_theory(ConspiracyTheory *conspiracy) {
    printf("Name: %s\n", conspiracy->name);
    printf("Description: %s\n", conspiracy->description);
}

void free_conspiracy_theory(ConspiracyTheory *conspiracy) {
    free(conspiracy->name);
    free(conspiracy->description);
    free(conspiracy);
}

int main(void) {
    ConspiracyTheory *conspiracy = generate_conspiracy_theory();
    print_conspiracy_theory(conspiracy);
    free_conspiracy_theory(conspiracy);

    return 0;
}