//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    if (p1->age < p2->age) {
        return -1;
    } else if (p1->age > p2->age) {
        return 1;
    } else {
        return 0;
    }
}

void print_result(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Person *array = (Person *)malloc(size * sizeof(Person));

    printf("Enter the names and ages of %d people:\n", size);

    for (int i = 0; i < size; i++) {
        char name[MAX_SIZE];
        int age;

        printf("Name: ");
        scanf("%s", name);

        printf("Age: ");
        scanf("%d", &age);

        array[i].name = (char *)malloc(strlen(name) + 1);
        strcpy(array[i].name, name);

        array[i].age = age;
    }

    qsort(array, size, sizeof(Person), compare);

    printf("Sorted by age:\n");

    for (int i = 0; i < size; i++) {
        print_result(&array[i]);
    }

    return 0;
}