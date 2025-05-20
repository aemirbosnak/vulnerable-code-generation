//Falcon-180B DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

void read_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        people[i].name = strdup(token);
        token = strtok(NULL, ",");
        people[i].age = atoi(token);
        token = strtok(NULL, ",");
        people[i].email = strdup(token);
        i++;
    }

    *num_people = i;
}

void write_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].email);
    }
}

int main() {
    FILE *input_file, *output_file;
    Person people[100];
    int num_people = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    read_file(input_file, people, &num_people);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    write_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}