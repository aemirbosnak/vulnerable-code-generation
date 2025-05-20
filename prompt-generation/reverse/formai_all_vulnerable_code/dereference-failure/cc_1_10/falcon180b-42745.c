//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 120
#define MAX_ROWS 100
#define MAX_COLS 3

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char address[MAX_NAME_LEN];
} Person;

void read_csv_file(FILE *fp, Person people[]) {
    char line[1024];
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[row].name, token);
        people[row].age = atoi(strtok(NULL, ","));
        strcpy(people[row].address, strtok(NULL, ","));
        row++;
        if (row == MAX_ROWS) {
            break;
        }
    }
}

void print_table(Person people[], int num_rows, int num_cols) {
    printf("+----+----------------+--------------------+\n");
    for (int i = 0; i < num_cols; i++) {
        printf("| %-*s | %-*s | %-*s |\n", MAX_NAME_LEN, "Name", MAX_NAME_LEN, "Age", MAX_NAME_LEN, "Address");
    }
    printf("+----+----------------+--------------------+\n");
    for (int i = 0; i < num_rows; i++) {
        printf("| %-*s | %-*d | %-*s |\n", MAX_NAME_LEN, people[i].name, MAX_AGE, people[i].age, MAX_NAME_LEN, people[i].address);
    }
    printf("+----+----------------+--------------------+\n");
}

int main() {
    FILE *fp;
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    Person people[MAX_ROWS];
    int num_rows = 0;

    read_csv_file(fp, people);
    num_rows = ftell(fp) / sizeof(Person);

    fclose(fp);

    print_table(people, num_rows, 3);

    return 0;
}