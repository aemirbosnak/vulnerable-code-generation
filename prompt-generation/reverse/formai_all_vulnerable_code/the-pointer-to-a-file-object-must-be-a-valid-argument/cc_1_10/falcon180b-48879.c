//Falcon-180B DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare_people(const void *a, const void *b) {
    const Person *person1 = (const Person *) a;
    const Person *person2 = (const Person *) b;

    if (person1->age > person2->age) {
        return 1;
    } else if (person1->age < person2->age) {
        return -1;
    } else {
        return 0;
    }
}

void read_people_from_file(FILE *file, Person **people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    Person *new_people = NULL;
    int new_num_people = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Person *person = malloc(sizeof(Person));
        person->name = strdup(line);
        sscanf(line, "%s %d", person->name, &person->age);

        if (new_people == NULL) {
            new_people = person;
        } else {
            *(Person **) realloc(new_people, sizeof(Person) * (new_num_people + 1)) = person;
        }

        new_num_people++;
    }

    if (new_people == NULL) {
        free(*people);
        *people = NULL;
        *num_people = 0;
    } else {
        *people = new_people;
        *num_people = new_num_people;
    }
}

void write_people_to_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }
}

void sort_people(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_people);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    Person *people = NULL;
    int num_people = 0;

    read_people_from_file(input_file, &people, &num_people);

    sort_people(people, num_people);

    write_people_to_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    free(people);

    return 0;
}