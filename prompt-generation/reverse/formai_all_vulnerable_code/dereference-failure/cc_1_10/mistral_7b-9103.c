//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
} Person;

void read_csv(FILE *file, Person **persons, int *count) {
    char line[1024];
    char *token;
    int rows = 0;

    *persons = malloc(sizeof(Person) * (*count + 1));

    while (fgets(line, sizeof(line), file)) {
        Person *person = &((*persons)[rows++]);
        char *name = strtok(line, ",");

        if (name == NULL) {
            fprintf(stderr, "Invalid CSV format: missing name!\n");
            exit(1);
        }
        person->name = strdup(name);

        token = strtok(NULL, ",");
        if (token == NULL) {
            fprintf(stderr, "Invalid CSV format: missing age!\n");
            exit(1);
        }
        person->age = atoi(token);
    }

    *count = rows;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    int count = 0;
    Person *persons = NULL;

    read_csv(file, &persons, &count);

    printf("Total %d persons loaded from CSV file:\n", count);

    for (int i = 0; i < count; i++) {
        printf("Person %d: %s (%d years old)\n", i + 1, persons[i].name, persons[i].age);
    }

    for (int i = 0; i < count; i++) {
        free(persons[i].name);
    }
    free(persons);

    fclose(file);
    return 0;
}