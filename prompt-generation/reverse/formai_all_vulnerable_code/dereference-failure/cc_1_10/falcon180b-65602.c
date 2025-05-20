//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
} Person;

void read_data_from_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i >= *num_people) {
            printf("Error: Too many lines in file.\n");
            exit(1);
        }

        int j = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            switch (j) {
                case 0:
                    strncpy(people[i].name, token, MAX_NAME_LENGTH);
                    break;
                case 1:
                    people[i].age = atoi(token);
                    break;
                case 2:
                    people[i].height = atof(token);
                    break;
                default:
                    printf("Error: Invalid line format.\n");
                    exit(1);
            }

            j++;
            token = strtok(NULL, ",");
        }

        i++;
    }

    *num_people = i;
}

void write_data_to_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%.2f\n", people[i].name, people[i].age, people[i].height);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open files.\n");
        return 1;
    }

    int num_people = 0;
    Person people[100];

    read_data_from_file(input_file, people, &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old and %.2f meters tall.\n", people[i].name, people[i].age, people[i].height);
    }

    write_data_to_file(output_file, people, num_people);

    fclose(input_file);
    fclose(output_file);

    return 0;
}