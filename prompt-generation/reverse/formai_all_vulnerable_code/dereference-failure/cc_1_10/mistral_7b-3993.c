//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int age;
    float height;
} Person;

void readFile(FILE *file, Person *persons, int *numPersons) {
    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
    int counter = 0;

    while (!feof(file)) {
        fscanf(file, "%s %d %f", persons[counter].name, &persons[counter].age, &persons[counter].height);
        counter++;
        *numPersons = counter;
    }

    fclose(file);
}

void writeFile(FILE *file, Person *persons, int numPersons) {
    fwrite(persons, sizeof(Person), numPersons, file);
    fclose(file);
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.bin", "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Unable to open files.\n");
        return 1;
    }

    int numPersons;
    Person persons[100];
    readFile(inputFile, persons, &numPersons);

    printf("Successfully read %d persons from input.txt.\n", numPersons);

    writeFile(outputFile, persons, numPersons);

    printf("Successfully wrote %d persons to output.bin.\n", numPersons);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}