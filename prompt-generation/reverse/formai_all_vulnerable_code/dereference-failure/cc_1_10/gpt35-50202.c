//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

void writeToFile(FILE* file, Person* person) {
    fprintf(file, "%s,%d,%s\n", person->name, person->age, person->address);
}

void readFromFile(FILE* file, Person* person) {
    char line[150];
    fgets(line, sizeof(line), file);
    char * tokens = strtok(line, ",");
    strcpy(person->name, tokens);
    tokens = strtok(NULL, ",");
    person->age = atoi(tokens);
    tokens = strtok(NULL, ",");
    strcpy(person->address, tokens);
}

int main() {
    FILE* file = fopen("person.txt", "w+");
    if(file == NULL) {
        printf("Error: Failed to open file\n");
        exit(1);
    }
    Person* firstPerson = (Person*) malloc(sizeof(Person));
    strcpy(firstPerson->name, "John");
    firstPerson->age = 25;
    strcpy(firstPerson->address, "123 Main Street");
    writeToFile(file, firstPerson);
    free(firstPerson);
    
    Person* secondPerson = (Person*) malloc(sizeof(Person));
    strcpy(secondPerson->name, "Jane");
    secondPerson->age = 30;
    strcpy(secondPerson->address, "456 Elm Street");
    writeToFile(file, secondPerson);
    free(secondPerson);
    
    rewind(file);
    
    Person* readFirstPerson = (Person*) malloc(sizeof(Person));
    readFromFile(file, readFirstPerson);
    printf("Name: %s\n", readFirstPerson->name);
    printf("Age: %d\n", readFirstPerson->age);
    printf("Address: %s\n\n", readFirstPerson->address);
    free(readFirstPerson);
    
    Person* readSecondPerson = (Person*) malloc(sizeof(Person));
    readFromFile(file, readSecondPerson);
    printf("Name: %s\n", readSecondPerson->name);
    printf("Age: %d\n", readSecondPerson->age);
    printf("Address: %s\n", readSecondPerson->address);
    free(readSecondPerson);
    
    fclose(file);
    return 0;
}