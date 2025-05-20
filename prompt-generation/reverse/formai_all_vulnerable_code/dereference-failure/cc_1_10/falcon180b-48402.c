//Falcon-180B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_LINE_LENGTH];
} Person;

void read_person_data(FILE *file, Person *person) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    fgets(line, MAX_LINE_LENGTH, file);
    token = strtok(line, ",");

    strcpy(person->name, token);
    person->age = atoi(strtok(NULL, ","));

    while ((token = strtok(NULL, ","))!= NULL) {
        if (i < MAX_LINE_LENGTH - strlen(person->address)) {
            strcat(person->address, " ");
            strcat(person->address, token);
        }
        i++;
    }
}

void write_person_data(FILE *file, Person *person) {
    fprintf(file, "%s,%d,%s\n", person->name, person->age, person->address);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Person person;

    while (fscanf(input_file, "%s,%d,%s", person.name, &person.age, person.address)!= EOF) {
        person.age++;
        write_person_data(output_file, &person);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}