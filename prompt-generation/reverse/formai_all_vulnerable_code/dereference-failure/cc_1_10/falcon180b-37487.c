//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *name;
    int age;
    Person *people;
} Family;

void create_family(Family *family, char *name, int age) {
    family->name = name;
    family->age = age;
    family->people = malloc(MAX_ROWS * sizeof(Person));
}

void add_person(Family *family, char *name, int age) {
    Person *person = family->people;
    int count = 0;

    while (count < MAX_ROWS && person->name!= NULL) {
        person++;
        count++;
    }

    person->name = name;
    person->age = age;
}

void print_family(Family *family) {
    printf("Family Name: %s\n", family->name);
    printf("Family Age: %d\n", family->age);

    Person *person = family->people;
    int count = 0;

    while (count < MAX_ROWS && person->name!= NULL) {
        printf("Person Name: %s\n", person->name);
        printf("Person Age: %d\n", person->age);
        person++;
        count++;
    }
}

int main() {
    Family family;
    create_family(&family, "Smith", 35);
    add_person(&family, "John", 10);
    add_person(&family, "Jane", 8);
    add_person(&family, "Bob", 5);

    print_family(&family);

    return 0;
}