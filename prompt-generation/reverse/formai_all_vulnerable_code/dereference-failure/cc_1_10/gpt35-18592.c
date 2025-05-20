//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int age;
    float rating;
} Person;

int countLines(FILE* file) {
    int count = 0;
    char c;
    while((c = fgetc(file)) != EOF) {
        if(c == '\n') count++;
    }
    rewind(file);
    return count;
}

void readPerson(char* line, int* index, Person* person) {
    char* token = strtok(line, ",");
    while(token != NULL) {
        switch(*index) {
            case 0:
                strcpy(person->name, token);
                break;
            case 1:
                person->age = atoi(token);
                break;
            case 2:
                person->rating = atof(token);
                break;
        }
        token = strtok(NULL, ",");
        (*index)++;
    }
}

void printPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Rating: %.2f\n", person.rating);
}

int main() {
    FILE* file = fopen("people.csv", "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int numLines = countLines(file);
    printf("Number of lines in file: %d\n", numLines);

    Person* people = (Person*) malloc(numLines * sizeof(Person));
    char line[MAX_LENGTH];
    int index = 0;
    while(fgets(line, MAX_LENGTH, file)) {
        readPerson(line, &index, &people[index]);
        index = 0;
    }

    printf("People in file:\n");
    for(int i = 0; i < numLines; i++) {
        printPerson(people[i]);
    }

    fclose(file);
    free(people);

    return 0;
}