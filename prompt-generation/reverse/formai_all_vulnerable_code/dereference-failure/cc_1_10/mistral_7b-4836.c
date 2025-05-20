//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} Person;

void trim(char *str, int len) {
    int i = 0;
    while (isspace(str[i]) && i < len) i++;
    memmove(str, str + i, len - i);
    len -= i;
    str[len] = '\0';
}

int parseCSVLine(char *line, Person *person) {
    char *token;
    int i = 0;

    token = strtok(line, ",");
    strcpy(person->name, token);
    trim(person->name, strlen(person->name));

    token = strtok(NULL, ",");
    person->age = atoi(token);

    token = strtok(NULL, ",");
    person->weight = atof(token);

    if (token != NULL) {
        printf("Invalid CSV format: %s\n", token);
        return 0;
    }

    return 1;
}

int main() {
    FILE *inputFile, *outputFile;
    Person person;
    char line[1024];

    inputFile = fopen("input.csv", "r");
    if (inputFile == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        printf("Could not open output file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        if (parseCSVLine(line, &person) == 0) continue;

        fprintf(outputFile, "%s,%d,%.2f\n", person.name, person.age, person.weight);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}