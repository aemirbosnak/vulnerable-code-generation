//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

void load_data(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            break;
        }

        people[i].name = strdup(token);
        token = strtok(NULL, ",");
        people[i].age = atoi(token);
        token = strtok(NULL, ",");
        people[i].occupation = strdup(token);

        i++;
        *num_people = i;
    }
}

void print_data(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Occupation: %s\n\n", people[i].occupation);
    }
}

void sort_data(Person *people, int num_people, int (*compar)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compar);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return person_a->age - person_b->age;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person *people = malloc(sizeof(Person) * 100);
    int num_people = 0;

    load_data(file, people, &num_people);
    print_data(people, num_people);

    sort_data(people, num_people, compare_age);
    printf("Sorted by age:\n");
    print_data(people, num_people);

    free(people);
    fclose(file);

    return 0;
}