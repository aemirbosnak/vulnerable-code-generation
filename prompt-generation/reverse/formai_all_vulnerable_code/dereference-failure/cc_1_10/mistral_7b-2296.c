//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    float height;
} Person;

void readFile(const char *filename, Person *people, int *numPeople);
void writeFile(const char *filename, Person *people, int numPeople);
void printPerson(const Person *person);

int main() {
    const char *filename = "people.dat";
    Person *people;
    int numPeople;

    readFile(filename, &people, &numPeople);

    for (int i = 0; i < numPeople; ++i) {
        printPerson(&people[i]);
    }

    // Add new person here
    Person newPerson = {"John Doe", 25, 1.75};
    people = realloc(people, sizeof(Person) * (numPeople + 1));
    strcpy(people[numPeople].name, newPerson.name);
    people[numPeople].age = newPerson.age;
    people[numPeople].height = newPerson.height;
    ++numPeople;

    writeFile(filename, people, numPeople);

    free(people);

    return 0;
}

void readFile(const char *filename, Person *people, int *numPeople) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        *numPeople = 0;
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *numPeople = fileSize / sizeof(Person);
    people = malloc(*numPeople * sizeof(Person));

    fread(people, sizeof(Person), *numPeople, file);
    fclose(file);
}

void writeFile(const char *filename, Person *people, int numPeople) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    fwrite(people, sizeof(Person), numPeople, file);
    fclose(file);
}

void printPerson(const Person *person) {
    printf("%s (%d years old, %.2f meters)\n", person->name, person->age, person->height);
}