//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

void search(Person *array, int size, int targetAge) {
    qsort(array, size, sizeof(Person), compare);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].age == targetAge) {
            printf("%s\n", array[i].name);
            found = 1;
        }
    }

    if (!found) {
        printf("No person found with age %d.\n", targetAge);
    }
}

int main() {
    Person array[MAX_SIZE];
    int size = 0;

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, stdin)) {
        if (size >= MAX_SIZE) {
            printf("Array is full.\n");
            break;
        }

        char *token = strtok(line, " ");
        strcpy(array[size].name, token);
        array[size].age = atoi(token);
        size++;
    }

    int targetAge;
    printf("Enter target age: ");
    scanf("%d", &targetAge);

    search(array, size, targetAge);

    return 0;
}