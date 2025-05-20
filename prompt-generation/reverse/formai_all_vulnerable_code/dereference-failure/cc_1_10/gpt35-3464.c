//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[20];
    int age;
    char gender[10];
} Person;

void readCSVFile(FILE *csvFile, Person people[], int *numPeople) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, csvFile) != NULL) {
        token = strtok(line, ",");
        strcpy(people[i].name, token);

        token = strtok(NULL, ",");
        people[i].age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(people[i].gender, token);

        i++;
    }

    *numPeople = i;
}

int main() {
    FILE *csvFile;
    char *filename = "people.csv";
    Person people[100];
    int numPeople = 0;

    csvFile = fopen(filename, "r");

    if (csvFile == NULL) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    readCSVFile(csvFile, people, &numPeople);

    fclose(csvFile);

    printf("Read in %d people:\n", numPeople);
    printf("--------------------\n");
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s, Age: %d, Gender: %s\n", people[i].name, people[i].age, people[i].gender);
    }

    return 0;
}