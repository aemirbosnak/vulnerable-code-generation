//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create(Person *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i].name = (char *)malloc(MAX_SIZE);
        arr[i].age = i;
        sprintf(arr[i].name, "Person %d", i);
    }
}

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age > p2->age)
        return 1;
    else if (p1->age < p2->age)
        return -1;
    else
        return 0;
}

void print(Person *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d years old\n", arr[i].name, arr[i].age);
    }
}

void search(Person *arr, int size, int age) {
    qsort(arr, size, sizeof(Person), compare);

    printf("Sorted by age:\n");
    print(arr, size);

    Person target = {0};
    target.age = age;

    Person *result = bsearch(&target, arr, size, sizeof(Person), compare);

    if (result!= NULL) {
        printf("\nFound person with age %d:\n", result->age);
        printf("Name: %s\n", result->name);
    } else {
        printf("\nPerson not found.\n");
    }
}

int main() {
    Person *people = (Person *)malloc(MAX_SIZE * 10);
    int size = 10;

    create(people, size);
    search(people, size, 25);

    free(people);

    return 0;
}