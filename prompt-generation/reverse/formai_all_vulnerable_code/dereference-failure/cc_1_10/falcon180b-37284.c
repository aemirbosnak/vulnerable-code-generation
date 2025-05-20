//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

void read_file(char *filename, Person *people, int *num_people) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    *num_people = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");

        Person person = {.name = strdup(name),.age = age,.address = strdup(address)};
        people[*num_people] = person;
        (*num_people)++;
        num_lines++;
    }

    printf("Read %d lines from file %s\n", num_lines, filename);
    fclose(file);
}

void write_file(char *filename, Person *people, int num_people) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].address);
    }

    printf("Wrote %d lines to file %s\n", num_people, filename);
    fclose(file);
}

void free_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
        free(people[i].address);
    }
    free(people);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    Person *people = NULL;
    int num_people = 0;

    read_file(input_file, people, &num_people);

    write_file(output_file, people, num_people);

    free_people(people, num_people);

    return 0;
}