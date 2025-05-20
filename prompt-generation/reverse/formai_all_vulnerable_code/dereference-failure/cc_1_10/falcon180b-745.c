//Falcon-180B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
} Person;

void read_file(FILE *fp, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    char *token;
    Person *current_person = people;
    int current_person_index = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        current_person->name = strdup(token);
        token = strtok(NULL, ",");
        current_person->age = atoi(token);

        current_person++;
        current_person_index++;
    }

    *num_people = current_person_index;
}

void write_file(FILE *fp, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(fp, "%s,%d\n", people[i].name, people[i].age);
    }
}

void sort_people(Person *people, int num_people, int (*comparator)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), comparator);
}

int compare_by_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return person_a->age - person_b->age;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person *people = malloc(100 * sizeof(Person));
    int num_people = 0;

    read_file(input_file, people, &num_people);

    sort_people(people, num_people, compare_by_age);

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    free(people);

    return 0;
}