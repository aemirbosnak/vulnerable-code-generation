//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *occupation;
    int age;
    char *address;
} person;

int main() {
    // Initialize Sherlock Holmes' notebook
    person notebook[100];

    // Read in data from the suspects' files
    FILE *file = fopen("suspects.txt", "r");
    if (file == NULL) {
        printf("Error: could not open suspects.txt\n");
        return 1;
    }
    char line[100];
    int i = 0;
    while (fgets(line, 100, file)) {
        // Parse the data into the notebook
        char *name = strtok(line, ",");
        char *occupation = strtok(NULL, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");

        notebook[i].name = strdup(name);
        notebook[i].occupation = strdup(occupation);
        notebook[i].age = age;
        notebook[i].address = strdup(address);

        i++;
    }
    fclose(file);

    // Print out the notebook
    printf("Sherlock Holmes' Notebook:\n");
    for (i = 0; i < 100; i++) {
        printf("Name: %s\n", notebook[i].name);
        printf("Occupation: %s\n", notebook[i].occupation);
        printf("Age: %d\n", notebook[i].age);
        printf("Address: %s\n\n", notebook[i].address);
    }

    // Solve the crime!
    // ...

    // Print out the solution
    printf("The culprit is: %s\n", notebook[i].name);

    // Free the memory allocated for the notebook
    for (i = 0; i < 100; i++) {
        free(notebook[i].name);
        free(notebook[i].occupation);
        free(notebook[i].address);
    }

    return 0;
}