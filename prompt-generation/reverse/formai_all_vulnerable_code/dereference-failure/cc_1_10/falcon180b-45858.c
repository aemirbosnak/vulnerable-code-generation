//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *title;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Title: %s\n", person->title);
}

int main() {
    FILE *fp;
    char line[1000];
    char *token;
    Person people[MAX_ROWS];
    int num_rows = 0;
    int num_cols;

    // Open the CSV file
    fp = fopen("people.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the header row
    fgets(line, sizeof(line), fp);
    num_cols = strlen(line) / sizeof(char);

    // Read the data rows
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        people[num_rows].name = strdup(token);
        token = strtok(NULL, ",");
        people[num_rows].age = atoi(token);
        token = strtok(NULL, ",");
        people[num_rows].title = strdup(token);
        num_rows++;
    }

    // Close the file
    fclose(fp);

    // Print the data
    for (int i = 0; i < num_rows; i++) {
        print_person(&people[i]);
    }

    return 0;
}