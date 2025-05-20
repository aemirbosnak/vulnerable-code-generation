//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height;
    char gender;
} Person;

void read_csv(const char *filename, Person **persons, int *num_persons) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int row = 0;

    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        Person *person = malloc(sizeof(Person));
        sscanf(line, "%[^,],%d,%f,%c", person->name, &person->age, &person->height, &person->gender);
        person->age *= 7; // Just for fun, multiply age by 7
        (*persons)[row] = *person;
        free(person);
        row++;
        if (row == *num_persons) {
            *num_persons += 10;
            *persons = realloc(*persons, (*num_persons) * sizeof(Person));
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return 1;
    }

    Person *persons = NULL;
    int num_persons = 0;

    read_csv(argv[1], &persons, &num_persons);

    for (int i = 0; i < num_persons; i++) {
        printf("%s (%d years old, %.2f meters tall, %c)\n", persons[i].name, persons[i].age, persons[i].height, persons[i].gender);
    }

    free(persons);
    return 0;
}