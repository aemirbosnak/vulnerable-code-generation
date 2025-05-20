//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_persons(Person *person1, Person *person2) {
    return strcmp(person1->name, person2->name);
}

void swap_persons(Person *person1, Person *person2) {
    Person temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

void quicksort(Person **array, int left, int right) {
    int i = left, j = right;
    Person *pivot = array[right];
    Person *tmp;

    if (left < right) {
        while (i <= j) {
            while (compare_persons(array[i], pivot) < 0)
                i++;
            while (compare_persons(array[j], pivot) > 0)
                j--;
            if (i <= j) {
                swap_persons(array[i], array[j]);
                i++;
                j--;
            }
        }
        quicksort(array, left, j);
        quicksort(array, i, right);
    }
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    int n;
    scanf("%d", &n);

    Person **array = (Person **) malloc(n * sizeof(Person *));

    for (int i = 0; i < n; i++) {
        char name[50];
        int age;
        scanf("%s %d", name, &age);
        array[i] = create_person(name, age);
    }

    quicksort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        print_person(array[i]);
        delete_person(array[i]);
    }

    free(array);

    return 0;
}