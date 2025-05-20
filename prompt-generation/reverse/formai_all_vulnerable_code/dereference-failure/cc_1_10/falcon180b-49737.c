//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    double income;
} Person;

int compare_persons(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    if (person1->age > person2->age) {
        return 1;
    } else if (person1->age < person2->age) {
        return -1;
    } else {
        return 0;
    }
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Income: $%.2f\n\n", person->income);
}

int main() {
    srand(time(NULL));

    Person *people = malloc(10 * sizeof(Person));

    for (int i = 0; i < 10; i++) {
        people[i].name = malloc(20 * sizeof(char));
        sprintf(people[i].name, "Person %d", i + 1);
        people[i].age = rand() % 100;
        people[i].income = rand() % 100000 + 1;
    }

    qsort(people, 10, sizeof(Person), compare_persons);

    for (int i = 0; i < 10; i++) {
        print_person(&people[i]);
    }

    free(people);

    return 0;
}