//Falcon-180B DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_LINE_LENGTH];
    char phone[MAX_LINE_LENGTH];
} Person;

void read_file(FILE *file, Person *people, int *num_people) {
    char line[MAX_LINE_LENGTH];
    char *name, *address, *phone;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        name = strtok(line, ",");
        address = strtok(NULL, ",");
        phone = strtok(NULL, ",");
        strcpy(people[*num_people].name, name);
        strcpy(people[*num_people].address, address);
        strcpy(people[*num_people].phone, phone);
        (*num_people)++;
    }
}

void write_file(FILE *file, Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%s,%s\n", people[i].name, people[i].address, people[i].phone);
    }
}

int main() {
    FILE *input_file, *output_file;
    Person people[100];
    int num_people = 0;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read data from input file
    read_file(input_file, people, &num_people);

    // Sort data by name
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (strcmp(people[i].name, people[j].name) > 0) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Write sorted data to output file
    write_file(output_file, people, num_people);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}