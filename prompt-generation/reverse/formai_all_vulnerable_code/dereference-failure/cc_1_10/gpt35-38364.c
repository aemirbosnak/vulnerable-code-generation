//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char *name;
    int age;
    char *job_title;
} person;

void read_csv_file(char *filename, person *people, int *num_rows) {
    FILE *csv_file;
    char line[MAX_COLS*20];
    char *field = NULL;

    csv_file = fopen(filename, "r");
    if (!csv_file) {
        perror("Error opening file");
        return;
    }

    int row = 0; 
    while (fgets(line, sizeof(line), csv_file)) {
        field = strtok(line, ",");
        people[row].name = strdup(field);

        field = strtok(NULL, ",");
        people[row].age = atoi(field);

        field = strtok(NULL, ",");
        people[row].job_title = strdup(field);

        row++;
        if (row >= MAX_ROWS) {
            printf("Warning: maximum rows exceeded\n");
            break;
        }
    }

    fclose(csv_file);
    *num_rows = row;
}

void print_people(person *people, int num_rows) {
    for (int i=0; i<num_rows; i++) {
        printf("Name: %s, Age: %d, Job Title: %s\n", people[i].name, people[i].age, people[i].job_title);
    }
}

int main() {
    person people[MAX_ROWS];
    int num_rows;

    read_csv_file("people.csv", people, &num_rows);
    print_people(people, num_rows);

    return 0;
}