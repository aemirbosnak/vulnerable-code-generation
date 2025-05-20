//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct for holding the parsed data */
typedef struct {
    char* name;
    int age;
    char* gender;
} Person;

/* Define a function for parsing a single line */
Person* parse_line(char* line) {
    Person* person = malloc(sizeof(Person));
    char* token = strtok(line, ",");
    person->name = strdup(token);
    token = strtok(NULL, ",");
    person->age = atoi(token);
    token = strtok(NULL, ",");
    person->gender = strdup(token);
    return person;
}

/* Define a function for parsing a file */
void parse_file(FILE* file, void (*callback)(Person*)) {
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        Person* person = parse_line(line);
        callback(person);
    }
}

/* Define a callback function for printing the parsed data */
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %s\n", person->gender);
    printf("\n");
}

/* Define a main function for running the program */
int main() {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    parse_file(file, print_person);
    fclose(file);
    return 0;
}