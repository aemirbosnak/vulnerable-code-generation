//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    const Person *personA = (const Person *)a;
    const Person *personB = (const Person *)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(Person *people, int left, int right) {
    int i = left, j = right;
    Person pivot = people[(left + right) / 2];
    Person *pivotPtr = &pivot;

    while (i <= j) {
        while (compare(&people[i], pivotPtr) < 0) {
            i++;
        }
        while (compare(&people[j], pivotPtr) > 0) {
            j--;
        }
        if (i <= j) {
            swap(&people[i], &people[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(people, left, j);
    }
    if (i < right) {
        quicksort(people, i, right);
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[numPeople].name, token);
        token = strtok(NULL, ",");
        people[numPeople].age = atoi(token);
        numPeople++;
    }

    fclose(file);

    quicksort(people, 0, numPeople - 1);

    for (int i = 0; i < numPeople; i++) {
        printf("%s, %d\n", people[i].name, people[i].age);
    }

    return 0;
}