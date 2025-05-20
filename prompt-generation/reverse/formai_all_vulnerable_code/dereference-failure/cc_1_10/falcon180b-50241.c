//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_THEORIES 1000
#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

person_t *generate_person(void) {
    person_t *person = malloc(sizeof(person_t));

    person->name = malloc(MAX_WORD_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        person->name[i] = rand() % 26 + 'a';
    }
    person->name[MAX_WORD_LENGTH - 1] = '\0';

    person->age = rand() % 100;

    person->occupation = malloc(MAX_WORD_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        person->occupation[i] = rand() % 26 + 'a';
    }
    person->occupation[MAX_WORD_LENGTH - 1] = '\0';

    return person;
}

void generate_theory(person_t *person) {
    char theory[MAX_THEORIES];

    sprintf(theory, "%s %s is a %s-year-old %s who is secretly controlling the world's %s supply.",
            person->name, person->name, person->age, person->occupation, rand() % 2? "oil" : "coffee");

    printf("%s\n", theory);
}

int main(void) {
    srand(time(NULL));

    person_t *person;

    for (int i = 0; i < 10; i++) {
        person = generate_person();
        generate_theory(person);
        free(person->name);
        free(person->occupation);
        free(person);
    }

    return 0;
}