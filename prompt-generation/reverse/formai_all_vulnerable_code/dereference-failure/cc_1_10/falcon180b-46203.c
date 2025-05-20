//Falcon-180B DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender;
} Person;

void read_csv(FILE *file, Person *people, int *count) {
    char line[MAX_SIZE];
    char *token;
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(people[*count].name, token);
        token = strtok(NULL, ",");
        people[*count].age = atoi(token);
        token = strtok(NULL, ",");
        people[*count].gender = token[0];
        (*count)++;
    }
}

void print_people(Person *people, int count) {
    printf("Name\tAge\tGender\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%c\n", people[i].name, people[i].age, people[i].gender);
    }
}

int main() {
    FILE *file;
    Person people[MAX_SIZE];
    int count = 0;

    file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    read_csv(file, people, &count);

    print_people(people, count);

    fclose(file);
    return 0;
}