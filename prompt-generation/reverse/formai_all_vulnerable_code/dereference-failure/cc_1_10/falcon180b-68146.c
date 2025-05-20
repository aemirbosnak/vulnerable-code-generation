//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_SIZE 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_FILE_NAME_LENGTH];
} Person;

void read_csv_file(const char* filename, Person* people, int* num_people) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int line_num = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_num++;
        char* token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: invalid line format in file %s at line %d\n", filename, line_num);
            exit(1);
        }
        strcpy(people[(*num_people) - 1].name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: invalid line format in file %s at line %d\n", filename, line_num);
            exit(1);
        }
        people[(*num_people) - 1].age = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: invalid line format in file %s at line %d\n", filename, line_num);
            exit(1);
        }
        strcpy(people[(*num_people) - 1].address, token);
        (*num_people)++;
    }

    fclose(file);
}

void write_csv_file(const char* filename, Person* people, int num_people) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        fprintf(file, "%s,%d,%s\n", people[i].name, people[i].age, people[i].address);
    }

    fclose(file);
}

int main() {
    Person people[100];
    int num_people = 0;

    read_csv_file("data.csv", people, &num_people);

    printf("Number of people: %d\n", num_people);

    write_csv_file("output.csv", people, num_people);

    return 0;
}