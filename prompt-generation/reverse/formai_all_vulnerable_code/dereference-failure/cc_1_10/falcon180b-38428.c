//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    char *title;
    char *conspiracy;
} Person;

Person *generate_person(void) {
    Person *person = malloc(sizeof(Person));
    person->name = malloc(16 * sizeof(char));
    person->title = malloc(16 * sizeof(char));
    person->conspiracy = malloc(64 * sizeof(char));

    srand(time(NULL));
    int name_length = rand() % 16 + 1;
    int title_length = rand() % 16 + 1;
    int conspiracy_length = rand() % 64 + 1;

    for (int i = 0; i < name_length; i++) {
        person->name[i] = 'A' + rand() % 26;
    }
    person->name[name_length] = '\0';

    for (int i = 0; i < title_length; i++) {
        person->title[i] = 'A' + rand() % 26;
    }
    person->title[title_length] = '\0';

    for (int i = 0; i < conspiracy_length; i++) {
        person->conspiracy[i] = 'A' + rand() % 26;
    }
    person->conspiracy[conspiracy_length] = '\0';

    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Title: %s\n", person->title);
    printf("Conspiracy: %s\n", person->conspiracy);
}

int main(void) {
    Person *person = generate_person();
    print_person(person);
    free(person->name);
    free(person->title);
    free(person->conspiracy);
    free(person);
    return 0;
}