//Falcon-180B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = *(Person **) a;
    Person *person_b = *(Person **) b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void read_file(FILE *file, Person **people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        *num_people += 1;
        Person *new_person = malloc(sizeof(Person));
        new_person->name = strdup(name);
        new_person->age = age;

        *people = realloc(*people, (*num_people) * sizeof(Person));
        (*people)[(*num_people) - 1] = *new_person;
    }
}

void write_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d\n", people[i].name, people[i].age);
    }
}

void sort_people(Person *people, int num_people, int (*comparator)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), comparator);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    Person *people = NULL;
    int num_people = 0;

    read_file(input_file, &people, &num_people);

    sort_people(people, num_people, compare_names);
    write_file(output_file, people, num_people);

    sort_people(people, num_people, compare_ages);
    write_file(output_file, people, num_people);

    free(people);
    fclose(input_file);
    fclose(output_file);

    return 0;
}