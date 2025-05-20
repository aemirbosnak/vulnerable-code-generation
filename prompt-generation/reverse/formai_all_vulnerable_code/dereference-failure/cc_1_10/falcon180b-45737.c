//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char name[100];
    int age;
    char address[200];
} Person;

void read_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (i >= *num_people) {
            printf("Error: Too many people in file.\n");
            exit(1);
        }

        Person person;
        int j = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            switch (j) {
                case 0:
                    strcpy(person.name, token);
                    break;
                case 1:
                    person.age = atoi(token);
                    break;
                case 2:
                    strcpy(person.address, token);
                    break;
                default:
                    printf("Error: Invalid line format.\n");
                    exit(1);
            }
            j++;
            token = strtok(NULL, ",");
        }

        people[i++] = person;
    }

    *num_people = i;
}

void write_file(FILE *file, Person people[], int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].address);
    }
}

void sort_people(Person people[], int num_people, int (*compare)(const void *, const void *)) {
    qsort(people, num_people, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return person_a->age - person_b->age;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    int num_people = 0;
    Person people[100];

    read_file(input_file, people, &num_people);

    sort_people(people, num_people, compare_age);

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;
}