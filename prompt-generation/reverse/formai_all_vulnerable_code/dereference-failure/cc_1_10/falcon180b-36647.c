//Falcon-180B DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
    char *occupation;
    char *hobbies;
} Person;

Person *create_person(char *name, int age, char *occupation, char *hobbies) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->occupation = strdup(occupation);
    person->hobbies = strdup(hobbies);
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person->occupation);
    free(person->hobbies);
    free(person);
}

int compare_persons(Person *person1, Person *person2) {
    return strcmp(person1->name, person2->name);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
    printf("Hobbies: %s\n", person->hobbies);
}

int main() {
    srand(time(NULL));
    int num_people = rand() % 10 + 1;
    Person **people = (Person **) malloc(sizeof(Person *) * num_people);

    for (int i = 0; i < num_people; i++) {
        char *name = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
        sprintf(name, "Person %d", i + 1);
        people[i] = create_person(name, rand() % 100 + 1, "Programmer", "Reading books");
    }

    qsort(people, num_people, sizeof(Person *), compare_persons);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }
    free(people);

    return 0;
}