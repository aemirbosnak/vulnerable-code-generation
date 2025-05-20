//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
} Person;

void bubbleSort(Person arr[], int size) {
    int i, j, tempAge;
    char tempName[50];

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                tempAge = arr[j].age;
                arr[j].age = arr[j + 1].age;
                arr[j + 1].age = tempAge;

                strcpy(tempName, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, tempName);
            }
        }
    }
}

void printArray(Person arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
    }
}

int main(int argc, char **argv) {
    int size;
    Person *people;

    if (argc < 2) {
        printf("Error: Please provide the number of people as an argument.\n");
        return 1;
    }

    size = atoi(argv[1]);

    if (size <= 0) {
        printf("Error: Invalid input size.\n");
        return 1;
    }

    people = (Person *) malloc(size * sizeof(Person));

    if (people == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &people[i].age);
    }

    bubbleSort(people, size);

    printf("\nSorted list:\n");
    printArray(people, size);

    free(people);

    return 0;
}