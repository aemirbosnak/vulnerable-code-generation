//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define FILENAME "input.txt"
#define BINARY_FILENAME "output.bin"

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void readTextFile(FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        Person person;
        sscanf(line, "%[^,],%d,%f", person.name, &person.age, &person.weight);
        printf("%s %d %f\n", person.name, person.age, person.weight);
    }
}

void writeBinaryFile(Person person, FILE *file) {
    fwrite(&person, sizeof(Person), 1, file);
}

int main() {
    FILE *textFile = fopen(FILENAME, "r");
    FILE *binaryFile = fopen(BINARY_FILENAME, "wb");

    if (textFile == NULL || binaryFile == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    readTextFile(textFile);

    Person person;
    while (fscanf(textFile, "%[^,],%d,%f", person.name, &person.age, &person.weight) != EOF) {
        writeBinaryFile(person, binaryFile);
    }

    fclose(textFile);
    fclose(binaryFile);

    printf("Text file processing completed.\n");
    printf("Binary file processing started.\n");

    textFile = fopen(FILENAME, "r");
    binaryFile = fopen(BINARY_FILENAME, "rb");

    if (textFile == NULL || binaryFile == NULL) {
        perror("Error re-opening file.");
        exit(EXIT_FAILURE);
    }

    Person readPerson;
    while (fread(&readPerson, sizeof(Person), 1, textFile) != EOF && fread(&person, sizeof(Person), 1, binaryFile) != EOF) {
        if (strcmp(readPerson.name, person.name) != 0) {
            printf("Mismatch found between text and binary file!\n");
            printf("Text file name: %s\n", readPerson.name);
            printf("Binary file name: %s\n", person.name);
            break;
        }
    }

    if (feof(textFile) && feof(binaryFile)) {
        printf("File processing completed.\n");
    } else {
        perror("Error during file comparison.");
        exit(EXIT_FAILURE);
    }

    fclose(textFile);
    fclose(binaryFile);

    return EXIT_SUCCESS;
}