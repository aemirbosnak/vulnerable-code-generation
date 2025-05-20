//Falcon-180B DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;
    char input_buffer[1024];
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        Person *new_person = malloc(sizeof(Person));
        if (new_person == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }

        char *name = strtok(input_buffer, ",");
        if (name == NULL) {
            fprintf(stderr, "Invalid input format\n");
            exit(1);
        }

        int age_str = atoi(strtok(NULL, ","));
        if (age_str < 1 || age_str > 120) {
            fprintf(stderr, "Invalid age: %d\n", age_str);
            exit(1);
        }

        new_person->name = strdup(name);
        new_person->age = age_str;

        people = realloc(people, sizeof(Person) * ++num_people);
        if (people == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }

        people[num_people - 1] = *new_person;
        free(new_person);
    }

    fclose(input_file);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}