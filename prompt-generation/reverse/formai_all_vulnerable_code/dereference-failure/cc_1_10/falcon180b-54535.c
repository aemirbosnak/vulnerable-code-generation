//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
    char gender;
} Person;

Person *create_person(char *name, int age, char gender) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->gender = gender;
    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %c\n", person->gender);
}

void write_person_to_file(FILE *file, Person *person) {
    fprintf(file, "%s|%d|%c\n", person->name, person->age, person->gender);
}

Person *read_person_from_file(FILE *file) {
    char line[256];
    Person *person = NULL;
    fgets(line, sizeof(line), file);
    if (line[0]!= '\0') {
        char *token = strtok(line, "|");
        person = create_person(token, atoi(strtok(NULL, "|")), tolower(strtok(NULL, "|")));
    }
    return person;
}

int main() {
    FILE *file = fopen("people.txt", "w+");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    Person *person1 = create_person("John Doe", 25, 'M');
    Person *person2 = create_person("Jane Smith", 30, 'F');

    print_person(person1);
    print_person(person2);

    write_person_to_file(file, person1);
    write_person_to_file(file, person2);

    rewind(file);

    Person *person3 = read_person_from_file(file);
    Person *person4 = read_person_from_file(file);

    print_person(person3);
    print_person(person4);

    fclose(file);

    return 0;
}