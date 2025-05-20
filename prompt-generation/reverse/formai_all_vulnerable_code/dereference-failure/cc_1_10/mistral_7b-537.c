//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
} Person;

void read_csv(FILE *file, Person **persons, int *num_persons) {
    char line[1024];
    char *token;
    Person *person = NULL;
    int num_fields = 0;

    *persons = malloc(sizeof(Person) * (*num_persons + 1));

    while (fgets(line, sizeof(line), file)) {
        num_fields = 0;
        person = &((*persons)[*num_persons++]);

        token = strtok(line, ",");
        person->name = strdup(token);

        while ((token = strtok(NULL, ","))) {
            if (num_fields++ > 0) {
                person->age = atoi(token);
            }
        }
    }
}

void free_persons(Person *persons, int num_persons) {
    for (int i = 0; i < num_persons; ++i) {
        free(persons[i].name);
    }

    free(persons);
}

int main(int argc, char **argv) {
    FILE *file;
    Person *persons = NULL;
    int num_persons = 0;

    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    read_csv(file, &persons, &num_persons);

    for (int i = 0; i < num_persons; ++i) {
        printf("Name: %s, Age: %d\n", persons[i].name, persons[i].age);
    }

    free_persons(persons, num_persons);

    fclose(file);
    return 0;
}