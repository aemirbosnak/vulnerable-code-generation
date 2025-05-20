//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_CONSPIRACIES 100

typedef struct {
    char *name;
    int id;
} Person;

typedef struct {
    Person *people;
    int num_people;
} Conspiracy;

void *generate_conspiracy(void *arg) {
    int i;
    Conspiracy *conspiracy = (Conspiracy *) arg;

    for (i = 0; i < conspiracy->num_people; i++) {
        Person *person1 = &conspiracy->people[i];
        int j;

        for (j = i + 1; j < conspiracy->num_people; j++) {
            Person *person2 = &conspiracy->people[j];

            if (person1->id == person2->id) {
                // Ignore self-conspiracies
                continue;
            }

            char *conspiracy_text = malloc(1024);
            sprintf(conspiracy_text, "Conspiracy involving %s and %s", person1->name, person2->name);
            printf("%s\n", conspiracy_text);

            free(conspiracy_text);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Conspiracy conspiracies[MAX_CONSPIRACIES];
    int num_conspiracies = 0;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        conspiracies[i].people = malloc(sizeof(Person) * 2);
        conspiracies[i].num_people = 2;

        conspiracies[i].people[0].name = malloc(32);
        sprintf(conspiracies[i].people[0].name, "Person %d", rand() % 100);
        conspiracies[i].people[0].id = rand() % 100;

        conspiracies[i].people[1].name = malloc(32);
        sprintf(conspiracies[i].people[1].name, "Person %d", rand() % 100);
        conspiracies[i].people[1].id = rand() % 100;

        num_conspiracies++;
    }

    for (i = 0; i < num_conspiracies; i++) {
        pthread_create(&threads[i], NULL, generate_conspiracy, &conspiracies[i]);
    }

    for (i = 0; i < num_conspiracies; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}