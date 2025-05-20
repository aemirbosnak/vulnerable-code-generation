//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

int read_file(FILE *file, Person *people, int max_people) {
    int num_people = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_people >= max_people) {
            fprintf(stderr, "Error: Reached maximum number of people.\n");
            exit(1);
        }

        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *email = strtok(NULL, ",");

        people[num_people] = (Person) {
           .name = strdup(name),
           .age = age,
           .email = strdup(email)
        };

        num_people++;
    }

    return num_people;
}

void write_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].email);
    }
}

void sort_people_by_age(Person *people, int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("input.csv", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen("output.csv", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        exit(1);
    }

    Person people[100];
    int num_people = read_file(input_file, people, 100);

    sort_people_by_age(people, num_people);

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}