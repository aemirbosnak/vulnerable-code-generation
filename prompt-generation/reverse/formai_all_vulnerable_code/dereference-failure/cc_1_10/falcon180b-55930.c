//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare_persons(const void *a, const void *b) {
    const Person *person_a = a;
    const Person *person_b = b;

    if (person_a->age < person_b->age) {
        return -1;
    } else if (person_a->age > person_b->age) {
        return 1;
    } else {
        return 0;
    }
}

void read_people_from_file(const char *filename, Person *people, int *num_people) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_num++;
        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Invalid line format on line %d\n", line_num);
            exit(1);
        }
        char *name = token;
        int age;
        if (sscanf(token, "%d", &age)!= 1) {
            printf("Invalid age on line %d\n", line_num);
            exit(1);
        }
        people[(*num_people)++] = (Person) {.name = strdup(name),.age = age };
    }

    fclose(file);
}

void write_people_to_file(const char *filename, const Person *people, int num_people) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

void sort_people_by_age(Person *people, int num_people) {
    qsort(people, num_people, sizeof(Person), compare_persons);
}

int main() {
    const char *input_filename = "input.txt";
    const char *output_filename = "output.txt";

    Person people[1000];
    int num_people = 0;

    read_people_from_file(input_filename, people, &num_people);
    sort_people_by_age(people, num_people);
    write_people_to_file(output_filename, people, num_people);

    return 0;
}