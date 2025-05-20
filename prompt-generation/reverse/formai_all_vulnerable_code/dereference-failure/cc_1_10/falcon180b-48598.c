//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char city[MAX_SIZE];
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *) a;
    Person *personB = (Person *) b;

    int result = strcmp(personA->name, personB->name);

    if (result == 0) {
        result = personA->age - personB->age;
    }

    return result;
}

int main() {
    Person people[10];
    int numPeople = 0;

    FILE *file = fopen("people.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[numPeople].name, token);

        token = strtok(NULL, ",");
        people[numPeople].age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(people[numPeople].city, token);

        numPeople++;
    }

    fclose(file);

    qsort(people, numPeople, sizeof(Person), compare);

    for (int i = 0; i < numPeople; i++) {
        printf("%s %d %s\n", people[i].name, people[i].age, people[i].city);
    }

    return 0;
}