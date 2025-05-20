//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int age;
} Person;

void read_csv_file(FILE *file, void (*callback)(Person *person)) {
    char line[MAX_LINE_LENGTH];
    char *token;
    Person person = { NULL, 0 };

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        if (token!= NULL) {
            person.name = strdup(token);
        } else {
            printf("Error: Invalid line format\n");
            exit(1);
        }

        token = strtok(NULL, ",");
        if (token!= NULL) {
            person.age = atoi(token);
        } else {
            printf("Error: Invalid line format\n");
            exit(1);
        }

        callback(&person);
    }
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    FILE *file = fopen("people.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    read_csv_file(file, print_person);

    fclose(file);

    return 0;
}