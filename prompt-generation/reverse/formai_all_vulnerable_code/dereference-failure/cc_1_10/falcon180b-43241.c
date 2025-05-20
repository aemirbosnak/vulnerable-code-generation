//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 200
#define MAX_ADDRESS_LENGTH 100

typedef struct person {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
} Person;

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Address: %s\n\n", p->address);
}

int main() {
    srand(time(NULL));

    Person *people = malloc(sizeof(Person) * 10);

    for (int i = 0; i < 10; i++) {
        people[i].name[0] = '\0';
        people[i].age = rand() % MAX_AGE;
        people[i].address[0] = '\0';

        int name_length = rand() % MAX_NAME_LENGTH + 1;
        for (int j = 0; j < name_length; j++) {
            people[i].name[j] = 'A' + rand() % 26;
        }

        int address_length = rand() % MAX_ADDRESS_LENGTH + 1;
        for (int j = 0; j < address_length; j++) {
            people[i].address[j] = 'A' + rand() % 26;
        }
    }

    printf("Random people:\n");
    for (int i = 0; i < 10; i++) {
        print_person(&people[i]);
    }

    free(people);

    return 0;
}