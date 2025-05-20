//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void read_file(const char *filename, Person **people, int *count) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int line_number = 0;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        line_number++;

        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        Person *person = malloc(sizeof(Person));
        person->name = strdup(name);
        person->age = age;

        (*people)[*count] = *person;
        (*count)++;
    }

    fclose(file);
}

void write_file(const char *filename, Person *people, int count) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        Person person = people[i];

        fprintf(file, "%s,%d\n", person.name, person.age);
    }

    fclose(file);
}

void sort_people(Person *people, int count, int (*compare)(const void *, const void *)) {
    qsort(people, count, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    Person person_a = *(Person *)a;
    Person person_b = *(Person *)b;

    if (person_a.age < person_b.age) {
        return -1;
    } else if (person_a.age > person_b.age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    const char *filename = "people.txt";
    Person *people = NULL;
    int count = 0;

    read_file(filename, &people, &count);

    printf("Sorted by age:\n");
    sort_people(people, count, compare_age);
    write_file("sorted_by_age.txt", people, count);

    free(people);

    return 0;
}