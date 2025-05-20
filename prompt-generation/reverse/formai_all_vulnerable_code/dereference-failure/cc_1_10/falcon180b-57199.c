//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    int income;
} Person;

void generate_conspiracy_theory(char *subject) {
    printf("The truth about %s:\n", subject);
    printf("They don't want you to know that %s is actually a ", subject);
    int random_adjective = rand() % 4;
    switch(random_adjective) {
        case 0:
            printf("shape-shifting alien from the planet Zorgon.\n");
            break;
        case 1:
            printf("member of the Illuminati, controlling world events from behind the scenes.\n");
            break;
        case 2:
            printf("robot created by a secret government agency to spy on citizens.\n");
            break;
        case 3:
            printf("vampire, living for centuries by drinking the blood of innocents.\n");
            break;
    }
    printf("But we know the truth! %s must be stopped!\n", subject);
}

int main() {
    srand(time(NULL));

    Person *people[10];

    for(int i=0; i<10; i++) {
        people[i] = malloc(sizeof(Person));
        people[i]->name = malloc(16);
        sprintf(people[i]->name, "Person %d", i+1);
        people[i]->age = rand() % 100;
        people[i]->income = rand() % 100000;
    }

    for(int i=0; i<10; i++) {
        generate_conspiracy_theory(people[i]->name);
    }

    for(int i=0; i<10; i++) {
        free(people[i]->name);
        free(people[i]);
    }

    return 0;
}