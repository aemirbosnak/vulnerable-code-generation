//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = (char *) malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
}

void delete_person(Person *person) {
    free(person->name);
    person->name = NULL;
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *) a;
    Person *person_b = (Person *) b;
    return person_a->age - person_b->age;
}

void search_people(Person *people, int num_people, int age) {
    qsort(people, num_people, sizeof(Person), compare_age);
    printf("People aged %d:\n", age);
    for (int i = 0; i < num_people; i++) {
        if (people[i].age == age) {
            printf("%s\n", people[i].name);
        }
    }
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    create_person(&people[num_people], "Alice", 25);
    num_people++;
    create_person(&people[num_people], "Bob", 30);
    num_people++;
    create_person(&people[num_people], "Charlie", 20);
    num_people++;

    int search_age;
    printf("Enter age to search: ");
    scanf("%d", &search_age);

    search_people(people, num_people, search_age);

    for (int i = 0; i < num_people; i++) {
        delete_person(&people[i]);
    }

    return 0;
}