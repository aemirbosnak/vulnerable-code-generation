//Falcon-180B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *city;
} Person;

int compare_people(const void *a, const void *b) {
    Person *person1 = (Person *)a;
    Person *person2 = (Person *)b;

    if (person1->age < person2->age) {
        return -1;
    } else if (person1->age > person2->age) {
        return 1;
    } else {
        return 0;
    }
}

void read_people_from_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_SIZE];
    Person *current_person = people;
    int num_lines_read = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        num_lines_read++;

        if (num_lines_read == 1) {
            continue; // Skip header line
        }

        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *city = strtok(NULL, ",");

        current_person->name = strdup(name);
        current_person->age = age;
        current_person->city = strdup(city);

        current_person++;
    }

    *num_people = num_lines_read - 1;
}

void write_people_to_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].city);
    }
}

void sort_people(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_people);
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

    read_people_from_file(input_file, people, &num_people);

    sort_people(people, num_people);

    write_people_to_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    free(people);

    return 0;
}