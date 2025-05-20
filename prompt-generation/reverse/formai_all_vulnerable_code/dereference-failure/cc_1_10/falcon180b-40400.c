//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Person;

Person *read_csv(FILE *fp) {
    Person *people = NULL;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (i == 0) {
                people = realloc(people, sizeof(Person) * ++i);
                people[i - 1].name = strdup(token);
            } else if (i == 1) {
                people[i - 1].age = atoi(token);
            } else if (i == 2) {
                people[i - 1].salary = atof(token);
            }
            token = strtok(NULL, ",");
            i++;
        }
    }

    return people;
}

void print_people(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Salary: $%.2f\n\n", people[i].salary);
    }
}

int main() {
    FILE *fp;
    Person *people;

    fp = fopen("people.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    people = read_csv(fp);

    if (people == NULL) {
        printf("Error: No data found in file.\n");
        exit(1);
    }

    print_people(people, 3);

    free(people);
    fclose(fp);

    return 0;
}