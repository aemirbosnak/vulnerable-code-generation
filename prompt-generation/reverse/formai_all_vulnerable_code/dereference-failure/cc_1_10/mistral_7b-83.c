//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
    float weight;
} Person;

void read_csv(FILE *file, Person **persons, int *count) {
    char line[1024];
    char *token;
    Person *person;

    *count = 0;
    *persons = malloc(sizeof(Person));
    person = *persons;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        person->name = strdup(token);

        token = strtok(NULL, ",");
        person->age = atoi(token);

        token = strtok(NULL, ",");
        person->weight = atof(token);

        (*count)++;

        if (*count < 2) {
            *persons = realloc(*persons, sizeof(Person) * (*count));
            person = *persons + (*count - 1);
            *persons = *persons + sizeof(Person);
        }
    }

    if (ferror(file)) {
        perror("Error reading CSV file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Person *persons;
    int count;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening CSV file");
        exit(EXIT_FAILURE);
    }

    read_csv(file, &persons, &count);

    printf("Cornelius, the CSV Carousel, presents:\n");
    for (int i = 0; i < count; ++i) {
        printf("%s (%d years old, %.2f kg)\n", persons[i].name, persons[i].age, persons[i].weight);
    }

    fclose(file);

    for (int i = 0; i <= count; ++i) {
        free(persons[i].name);
    }
    free(persons);

    return EXIT_SUCCESS;
}