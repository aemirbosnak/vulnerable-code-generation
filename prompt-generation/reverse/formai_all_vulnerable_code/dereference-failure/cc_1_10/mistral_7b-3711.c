//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[50];
    int age;
    float height;
    double weight;
} Person;

void read_csv(FILE *file, Person *persons, int *num_persons) {
    char line[1024];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        Person *person = &persons[row];
        char *token;

        token = strtok(line, ",");
        strcpy(person->name, token);

        token = strtok(NULL, ",");
        person->age = atoi(token);

        token = strtok(NULL, ",");
        person->height = atof(token);

        token = strtok(NULL, ",");
        person->weight = atof(token);

        row++;
        if (row >= *num_persons) {
            *num_persons += 10;
            persons = realloc(persons, sizeof(Person) * (*num_persons));
        }
    }
}

void print_persons(Person *persons, int num_persons) {
    for (int i = 0; i < num_persons; i++) {
        Person person = persons[i];
        printf("%s (%d years old)\n", person.name, person.age);
        printf("Height: %.2f meters, Weight: %.2f kilograms\n", person.height, person.weight);
        printf("Magic Index: %.2f\n", person.height * person.weight / person.age);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Person *persons = NULL;
    int num_persons = 0;

    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    read_csv(file, persons, &num_persons);
    fclose(file);

    print_persons(persons, num_persons);

    free(persons);

    return 0;
}