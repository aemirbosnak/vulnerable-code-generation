//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int id;
    char name[50];
    char address[100];
} Person;

int compare(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;

    if (personA->id < personB->id) {
        return -1;
    } else if (personA->id > personB->id) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Person* people = NULL;
    int numPeople = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* token = strtok(line, ",");
        int id = atoi(token);

        token = strtok(NULL, ",");
        strncpy(people[numPeople].name, token, sizeof(people[numPeople].name));

        token = strtok(NULL, ",");
        strncpy(people[numPeople].address, token, sizeof(people[numPeople].address));

        numPeople++;
        people = realloc(people, sizeof(Person) * numPeople);
    }

    fclose(file);

    qsort(people, numPeople, sizeof(Person), compare);

    for (int i = 0; i < numPeople; i++) {
        printf("%d: %s, %s\n", people[i].id, people[i].name, people[i].address);
    }

    free(people);
    return 0;
}