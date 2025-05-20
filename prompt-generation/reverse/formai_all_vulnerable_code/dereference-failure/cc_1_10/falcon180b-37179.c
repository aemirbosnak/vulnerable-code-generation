//Falcon-180B DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
} Person;

int compare_name(const void* a, const void* b) {
    const char* name_a = *(char**)a;
    const char* name_b = *(char**)b;
    return strcmp(name_a, name_b);
}

int compare_age(const void* a, const void* b) {
    const int* age_a = *(int**)a;
    const int* age_b = *(int**)b;
    return *age_a - *age_b;
}

void print_person(const void* data) {
    const Person* person = *(Person**)data;
    printf("%s, %d\n", person->name, person->age);
}

int main() {
    int num_people = 5;
    Person* people = malloc(num_people * sizeof(Person));
    if (!people) {
        printf("Error: could not allocate memory for people.\n");
        return 1;
    }
    for (int i = 0; i < num_people; i++) {
        char name[32];
        printf("Enter name for person %d: ", i + 1);
        scanf("%31s", name);
        people[i].name = strdup(name);
        people[i].age = rand() % 100;
    }
    qsort(people, num_people, sizeof(Person), compare_name);
    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }
    qsort(people, num_people, sizeof(Person), compare_age);
    printf("\nSorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);
    return 0;
}