//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void read_csv(FILE *file, Person **persons, int *count) {
    char line[1024];
    char *token = NULL;
    Person *person = NULL;
    int rows = 0;

    *persons = malloc(1 * sizeof(Person));

    while (fgets(line, sizeof(line), file)) {
        person = realloc(*persons, sizeof(Person) * (rows + 1));

        token = strtok(line, ",");
        person->name = strdup(token);

        token = strtok(NULL, ",");
        person->age = atoi(token);

        token = strtok(NULL, ",");
        person->height = atof(token);

        rows++;
        *persons = realloc(*persons, sizeof(Person) * (rows + 1));
    }

    *count = rows;
}

int main() {
    FILE *file = fopen("people.csv", "r");
    Person *people = NULL;
    int count = 0;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_csv(file, &people, &count);

    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", people[i].name, people[i].age, people[i].height);
        free(people[i].name);
    }

    free(people);
    fclose(file);

    return 0;
}