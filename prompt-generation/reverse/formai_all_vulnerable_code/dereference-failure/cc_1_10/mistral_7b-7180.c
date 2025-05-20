//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
} Person;

void parse_line(char *line, Person *person) {
    char *token = strtok(line, ",");
    int field_count = 0;

    person->name = malloc(strlen(token) + 1);
    strcpy(person->name, token);

    while (token = strtok(NULL, ",")) {
        field_count++;

        if (field_count > 1) {
            person->age = atoi(token);
        }
    }
}

void read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    Person person;

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        parse_line(line, &person);
        printf("Name: %s, Age: %d\n", person.name, person.age);
        free(person.name);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_csv(argv[1]);
    return 0;
}